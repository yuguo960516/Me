#ifndef __IICC_H
#define __IICC_H
#include "sys.h"

 	   		   
//IO��������
#define IICC_SDA_IN()  {GPIOC->CRH&=0X0FFFFFFF;GPIOC->CRH|=((unsigned int)8<<28);}
#define IICC_SDA_OUT() {GPIOC->CRH&=0X0FFFFFFF;GPIOC->CRH|=((unsigned int)3<<28);}

//IO��������	 
#define IICC_SCL    PCout(14) 		//SCL
#define IICC_SDA    PCout(15) 		//SDA	 
#define IICC_READ_SDA   PCin(15) 		//����SDA 

//IIC���в�������
void IICC_Delay(void);				//MPU IIC��ʱ����
void IICC_Init(void);                //��ʼ��IIC��IO��				 
void IICC_Start(void);				//����IIC��ʼ�ź�
void IICC_Stop(void);	  			//����IICֹͣ�ź�
void IICC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IICC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IICC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IICC_Ack(void);					//IIC����ACK�ź�
void IICC_NAck(void);				//IIC������ACK�ź�


#endif
