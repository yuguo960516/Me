#include "MS5611.h"
#include "math.h"
#include "stdint.h"
#include "ALG.h"

//��ѹ��״̬��
#define SCTemperature    0x01	  //��ʼ�¶�ת��
#define CTemperatureing  0x02 //����ת���¶�
#define SCPressure  		 0x03	    //��ʼ��ѹת��
#define SCPressureing    0x04	  //����ת����ѹ


 
/*
C1 ѹ�������� SENS|T1
C2  ѹ������  OFF|T1
C3	�¶�ѹ��������ϵ�� TCS
C4	�¶�ϵ����ѹ������ TCO
C5	�ο��¶� T|REF
C6 	�¶�ϵ�����¶� TEMPSENS
*/
uint32_t  Cal_C[7];	        //���ڴ��PROM�е�6������1-6

double OFF_;
float Aux;
/*
dT ʵ�ʺͲο��¶�֮��Ĳ���
TEMP ʵ���¶�	
*/
uint64_t dT,TEMP;
/*
OFF ʵ���¶Ȳ���
SENS ʵ���¶�������
*/
uint64_t OFf,SENS;
uint32_t D1_Pres,D2_Temp;	// ����ѹ��ֵ,�����¶�ֵ

uint32_t Pressure,Pressure_old,qqp;				//����ѹ
uint32_t TEMP2,T2,OFF2,SENS2;	//�¶�У��ֵ


/*******************************************************************************
  * @��������	MS561101BA_RESET
  * @����˵��   ��λMS5611
  * @�������   ��
  * @�������   ��
  * @���ز���   ��
*******************************************************************************/
void MS561101BA_RESET(void)
{
		MPU_IIC_Start();
		MPU_IIC_Send_Byte(0xEE);//CSB�ӵأ�������ַ��0XEE������ 0X77
	  MPU_IIC_Wait_Ack();
    MPU_IIC_Send_Byte(0x1E);//���͸�λ����
	  MPU_IIC_Wait_Ack();
    MPU_IIC_Stop();
	
}
/*******************************************************************************
  * @��������	MS5611_init
  * @����˵��   ��ʼ��5611
  * @�������  	��
  * @�������   ��
  * @���ز���   ��
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
		MPU_IIC_Send_Byte(0xEE+0x01);  //�������ģʽ
		delay_us(1);
		MPU_IIC_Wait_Ack();
		inth = MPU_IIC_Read_Byte(1);  		//��ACK�Ķ�����
		delay_us(1);
		intl = MPU_IIC_Read_Byte(0); 			//���һ���ֽ�NACK
		MPU_IIC_Stop();
    Cal_C[i] = (((uint16_t)inth << 8) | intl);
	}
	 
 }


/**************************ʵ�ֺ���********************************************
*����ԭ��:unsigned long MS561101BA_getConversion(void)
*��������:    ��ȡ MS561101B ��ת����� 
*******************************************************************************/
unsigned long MS561101BA_getConversion(uint8_t command)
{
 
			unsigned long conversion = 0;
			u8 temp[3];
	
	    MPU_IIC_Start();
			MPU_IIC_Send_Byte(0xEE); 		//д��ַ
			MPU_IIC_Wait_Ack();
			MPU_IIC_Send_Byte(command); //дת������
			MPU_IIC_Wait_Ack();
			MPU_IIC_Stop();

			delay_ms(1);
			MPU_IIC_Start();
			MPU_IIC_Send_Byte(0xEE); 		//д��ַ
			MPU_IIC_Wait_Ack();
			MPU_IIC_Send_Byte(0);				// start read sequence
			MPU_IIC_Wait_Ack();
			MPU_IIC_Stop();
		 
			MPU_IIC_Start();
			MPU_IIC_Send_Byte(0xEE+0x01);  //�������ģʽ
			MPU_IIC_Wait_Ack();
			temp[0] = MPU_IIC_Read_Byte(1);  //��ACK�Ķ�����  bit 23-16
			temp[1] = MPU_IIC_Read_Byte(1);  //��ACK�Ķ�����  bit 8-15
			temp[2] = MPU_IIC_Read_Byte(0);  //��NACK�Ķ����� bit 0-7
			MPU_IIC_Stop();
			
			conversion = (unsigned long)temp[0] * 65536 + (unsigned long)temp[1] * 256 + (unsigned long)temp[2];
				
			return conversion;
 
}


/**************************ʵ�ֺ���********************************************
*����ԭ��:void MS561101BA_GetTemperature(void)
*��������:    ��ȡ �¶�ת����� 
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
//  * @brief  ��ȡ��ѹ
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






