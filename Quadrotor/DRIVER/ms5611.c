#include "MS5611.h"
#include "math.h"
#include "stdint.h"
#include "ALG.h"

//气压计状态机
#define SCTemperature    0x01	  //开始温度转换
#define CTemperatureing  0x02 //正在转换温度
#define SCPressure  		 0x03	    //开始气压转换
#define SCPressureing    0x04	  //正在转换气压


 
/*
C1 压力灵敏度 SENS|T1
C2  压力补偿  OFF|T1
C3	温度压力灵敏度系数 TCS
C4	温度系数的压力补偿 TCO
C5	参考温度 T|REF
C6 	温度系数的温度 TEMPSENS
*/
uint32_t  Cal_C[7];	        //用于存放PROM中的6组数据1-6

double OFF_;
float Aux;
/*
dT 实际和参考温度之间的差异
TEMP 实际温度	
*/
uint64_t dT,TEMP;
/*
OFF 实际温度补偿
SENS 实际温度灵敏度
*/
uint64_t OFf,SENS;
uint32_t D1_Pres,D2_Temp;	// 数字压力值,数字温度值

uint32_t Pressure,Pressure_old,qqp;				//大气压
uint32_t TEMP2,T2,OFF2,SENS2;	//温度校验值


/*******************************************************************************
  * @函数名称	MS561101BA_RESET
  * @函数说明   复位MS5611
  * @输入参数   无
  * @输出参数   无
  * @返回参数   无
*******************************************************************************/
void MS561101BA_RESET(void)
{
		MPU_IIC_Start();
		MPU_IIC_Send_Byte(0xEE);//CSB接地，主机地址：0XEE，否则 0X77
	  MPU_IIC_Wait_Ack();
    MPU_IIC_Send_Byte(0x1E);//发送复位命令
	  MPU_IIC_Wait_Ack();
    MPU_IIC_Stop();
	
}
/*******************************************************************************
  * @函数名称	MS5611_init
  * @函数说明   初始化5611
  * @输入参数  	无
  * @输出参数   无
  * @返回参数   无
*******************************************************************************/
void MS5611_init(void)
 {	 
  u8  inth,intl;
  int i;
	MS561101BA_RESET();
  for (i=1;i<=6;i++) 
	{
 
		MPU_IIC_Start();
    MPU_IIC_Send_Byte(0xEE);
		MPU_IIC_Wait_Ack();
		MPU_IIC_Send_Byte(0xA0 + (i*2));
		MPU_IIC_Wait_Ack();
    MPU_IIC_Stop();
		delay_us(5);
		MPU_IIC_Start();
		MPU_IIC_Send_Byte(0xEE+0x01);  //进入接收模式
		delay_us(1);
		MPU_IIC_Wait_Ack();
		inth = MPU_IIC_Read_Byte(1);  		//带ACK的读数据
		delay_us(1);
		intl = MPU_IIC_Read_Byte(0); 			//最后一个字节NACK
		MPU_IIC_Stop();
    Cal_C[i] = (((uint16_t)inth << 8) | intl);
	}
	 
 }


/**************************实现函数********************************************
*函数原型:unsigned long MS561101BA_getConversion(void)
*功　　能:    读取 MS561101B 的转换结果 
*******************************************************************************/
unsigned long MS561101BA_getConversion(uint8_t command)
{
 
			unsigned long conversion = 0;
			u8 temp[3];
	
	    MPU_IIC_Start();
			MPU_IIC_Send_Byte(0xEE); 		//写地址
			MPU_IIC_Wait_Ack();
			MPU_IIC_Send_Byte(command); //写转换命令
			MPU_IIC_Wait_Ack();
			MPU_IIC_Stop();

			delay_ms(1);
			MPU_IIC_Start();
			MPU_IIC_Send_Byte(0xEE); 		//写地址
			MPU_IIC_Wait_Ack();
			MPU_IIC_Send_Byte(0);				// start read sequence
			MPU_IIC_Wait_Ack();
			MPU_IIC_Stop();
		 
			MPU_IIC_Start();
			MPU_IIC_Send_Byte(0xEE+0x01);  //进入接收模式
			MPU_IIC_Wait_Ack();
			temp[0] = MPU_IIC_Read_Byte(1);  //带ACK的读数据  bit 23-16
			temp[1] = MPU_IIC_Read_Byte(1);  //带ACK的读数据  bit 8-15
			temp[2] = MPU_IIC_Read_Byte(0);  //带NACK的读数据 bit 0-7
			MPU_IIC_Stop();
			
			conversion = (unsigned long)temp[0] * 65536 + (unsigned long)temp[1] * 256 + (unsigned long)temp[2];
				
			return conversion;
 
}


/**************************实现函数********************************************
*函数原型:void MS561101BA_GetTemperature(void)
*功　　能:    读取 温度转换结果 
*******************************************************************************/

float MS561101BA_getTemperature(void)
{
	
	D2_Temp = MS561101BA_getConversion(0x58);
	delay_ms(2);
	
	dT=D2_Temp - (((uint32_t)Cal_C[5])<<8);
	TEMP=2000+dT*((uint32_t)Cal_C[6])/8388608;
	
	return (float)TEMP/100;
	
}

///***********************************************
//  * @brief  读取气压
//  * @param  None
//  * @retval None
//************************************************/
float MS561101BA_getPressure(void)
{
	D1_Pres= MS561101BA_getConversion(0x48);
	delay_ms(2);
	
	
	OFF_=(uint32_t)Cal_C[2]*65536+((uint32_t)Cal_C[4]*dT)/128;
	SENS=(uint32_t)Cal_C[1]*32768+((uint32_t)Cal_C[3]*dT)/256;
  
	if(TEMP<2000)
	{
		Aux = (2000-TEMP)*(2000-TEMP);
		T2 = (dT*dT) / 0x80000000; 
		OFF2 = 2.5f*Aux;
		SENS2 = 1.25f*Aux;
		
		TEMP = TEMP - T2;
		OFF_ = OFF_ - OFF2;
		SENS = SENS - SENS2;	
		
	}

  Pressure= (D1_Pres*SENS/2097152-OFF_)/32768;
	
	return (float)Pressure;
}






