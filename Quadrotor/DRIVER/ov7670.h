#ifndef __OV7670_H
#define __OV7670_H
#include "sys.h"
#include "sccb.h"
 
#define OV7670_VSYNC  	PBin(14)			//同步信号检测IO
#define OV7670_WRST		PBout(9)		//写指针复位
#define OV7670_WREN		PBout(8)		//写入FIFO使能
#define OV7670_RCK_H	GPIOB->BSRR=1<<5//设置读数据时钟高电平
#define OV7670_RCK_L	GPIOB->BRR=1<<5	//设置读数据时钟低电平
#define OV7670_RRST		PBout(13)  		//读指针复位
#define OV7670_CS		PBout(15)  		//片选信号(OE)


#define OV7670_DATA   GPIOA->IDR&0xFF00  					//数据输入端口
/////////////////////////////////////////									
	    				 
u8   OV7670_Init(void);		  	   		 
void OV7670_Light_Mode(void);
void OV7670_Color_Saturation(void);
void OV7670_Brightness(void);
void OV7670_Contrast(void);
void OV7670_Special_Effects(void);
void OV7670_Window_Set(u16 sx,u16 sy,u16 width,u16 height);

void camera_refresh(void);
void data_process(void);

#endif

