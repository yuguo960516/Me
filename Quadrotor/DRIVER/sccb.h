#ifndef __SCCB_H
#define __SCCB_H
#include "sys.h"
  
#define SCCB_SDA_IN()  {GPIOB->CRL&=0XFFF0FFFF;GPIOB->CRL|=0X00080000;}
#define SCCB_SDA_OUT() {GPIOB->CRL&=0XFFF0FFFF;GPIOB->CRL|=0X00030000;}

//IO操作函数	 
#define SCCB_SCL    		PBout(3)	 	//SCL
#define SCCB_SDA    		PBout(4) 		//SDA	 

#define SCCB_READ_SDA    	PBin(4)  		//输入SDA    
#define SCCB_ID   			0X42  			//OV7670的ID

///////////////////////////////////////////
void SCCB_Init(void);
void SCCB_Start(void);
void SCCB_Stop(void);
void SCCB_No_Ack(void);
u8 SCCB_WR_Byte(u8 dat);
u8 SCCB_RD_Byte(void);
u8 SCCB_WR_Reg(u8 reg,u8 data);
u8 SCCB_RD_Reg(u8 reg);
#endif


