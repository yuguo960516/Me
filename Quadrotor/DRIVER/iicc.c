#include "iicc.h"
#include "delay.h"

 
 //MPU IIC 延时函数
void IICC_Delay(void)
{
	delay_us(2);
}

//初始化IIC
void IICC_Init(void)
{					     
  GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//先使能外设IO PORTB时钟 
		
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15;	 // 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIO 
	
  GPIO_SetBits(GPIOC,GPIO_Pin_14|GPIO_Pin_15);						
 
}
//产生IIC起始信号
void IICC_Start(void)
{
	IICC_SDA_OUT();     //sda线输出
	IICC_SDA=1;	  	  
	IICC_SCL=1;
	IICC_Delay();
 	IICC_SDA=0;//START:when CLK is high,DATA change form high to low 
	IICC_Delay();
	IICC_SCL=0;//钳住I2C总线，准备发送或接收数据 
}	  
//产生IIC停止信号
void IICC_Stop(void)
{
	IICC_SDA_OUT();//sda线输出
	IICC_SCL=0;
	IICC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	IICC_Delay();
	IICC_SCL=1; 
	IICC_SDA=1;//发送I2C总线结束信号
	IICC_Delay();							   	
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 IICC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	IICC_SDA_IN();      //SDA设置为输入  
	IICC_SDA=1;IICC_Delay();	   
	IICC_SCL=1;IICC_Delay();	 
	while(IICC_READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IICC_Stop();
			return 1;
		}
	}
	IICC_SCL=0;//时钟输出0 	   
	return 0;  
} 
//产生ACK应答
void IICC_Ack(void)
{
	IICC_SCL=0;
	IICC_SDA_OUT();
	IICC_SDA=0;
	IICC_Delay();
	IICC_SCL=1;
	IICC_Delay();
	IICC_SCL=0;
}
//不产生ACK应答		    
void IICC_NAck(void)
{
	IICC_SCL=0;
	IICC_SDA_OUT();
	IICC_SDA=1;
	IICC_Delay();
	IICC_SCL=1;
	IICC_Delay();
	IICC_SCL=0;
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IICC_Send_Byte(u8 txd)
{                        
    u8 t;   
	IICC_SDA_OUT(); 	    
    IICC_SCL=0;//拉低时钟开始数据传输
    for(t=0;t<8;t++)
    {              
        IICC_SDA=(txd&0x80)>>7;
        txd<<=1; 	  
		    IICC_SCL=1;
		    IICC_Delay(); 
		    IICC_SCL=0;	
		    IICC_Delay();
    }	 
} 	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
u8 IICC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	IICC_SDA_IN();//SDA设置为输入
    for(i=0;i<8;i++ )
	{
        IICC_SCL=0; 
        IICC_Delay();
		    IICC_SCL=1;
        receive<<=1;
        if(IICC_READ_SDA)receive++;   
		IICC_Delay(); 
    }					 
    if (!ack)
        IICC_NAck();//发送nACK
    else
        IICC_Ack(); //发送ACK   
    return receive;
}


























