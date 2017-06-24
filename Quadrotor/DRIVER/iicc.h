#ifndef __IICC_H
#define __IICC_H
#include "sys.h"

 	   		   
//IO方向设置
#define IICC_SDA_IN()  {GPIOC->CRH&=0X0FFFFFFF;GPIOC->CRH|=((unsigned int)8<<28);}
#define IICC_SDA_OUT() {GPIOC->CRH&=0X0FFFFFFF;GPIOC->CRH|=((unsigned int)3<<28);}

//IO操作函数	 
#define IICC_SCL    PCout(14) 		//SCL
#define IICC_SDA    PCout(15) 		//SDA	 
#define IICC_READ_SDA   PCin(15) 		//输入SDA 

//IIC所有操作函数
void IICC_Delay(void);				//MPU IIC延时函数
void IICC_Init(void);                //初始化IIC的IO口				 
void IICC_Start(void);				//发送IIC开始信号
void IICC_Stop(void);	  			//发送IIC停止信号
void IICC_Send_Byte(u8 txd);			//IIC发送一个字节
u8 IICC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 IICC_Wait_Ack(void); 				//IIC等待ACK信号
void IICC_Ack(void);					//IIC发送ACK信号
void IICC_NAck(void);				//IIC不发送ACK信号


#endif
