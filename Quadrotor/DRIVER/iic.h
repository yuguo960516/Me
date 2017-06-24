#ifndef __IIC_H
#define __IIC_H
#include "sys.h"

 	   		   
//IO��������
#define MPU_SDA_IN()  {GPIOA->CRL&=0XFFF0FFFF;GPIOA->CRL|=8<<16;}
#define MPU_SDA_OUT() {GPIOA->CRL&=0XFFF0FFFF;GPIOA->CRL|=3<<16;}

//IO��������	 
#define MPU_IIC_SCL    PAout(5) 		//SCL
#define MPU_IIC_SDA    PAout(4) 		//SDA	 
#define MPU_READ_SDA   PAin(4) 		//����SDA 

//IIC���в�������
void MPU_IIC_Delay(void);				//MPU IIC��ʱ����
void MPU_IIC_Init(void);                //��ʼ��IIC��IO��				 
void MPU_IIC_Start(void);				//����IIC��ʼ�ź�
void MPU_IIC_Stop(void);	  			//����IICֹͣ�ź�
void MPU_IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 MPU_IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 MPU_IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void MPU_IIC_Ack(void);					//IIC����ACK�ź�
void MPU_IIC_NAck(void);				//IIC������ACK�ź�


#endif
















