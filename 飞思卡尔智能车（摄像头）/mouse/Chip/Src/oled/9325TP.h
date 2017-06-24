#ifndef __ILI9325_H__
#define __ILI9325_H__
#include "gpio_cfg.h"
#ifndef uchar
#define uchar unsigned char 
#endif

#ifndef uint
#define uint unsigned int 
#endif
/*-----------------临时接法-------------------------------
* D0~D7  -> PC16~PC23
* CS     -> PC1
* REST   -> PC2
* RD     -> PC3
* WR     -> PC9
* RS     -> PC10
******************************************************/
/*----------------------------------------------------------------
                           定义硬件端口
----------------------------------------------------------------*/
#define	rw		 PTB9_OUT
#define	rd		 PTB3_OUT
#define	cs		 PTB1_OUT
#define	rs		 PTB10_OUT
#define	res	         PTB2_OUT
#define p0		 PTB_BYTE3_OUT
//#define	PIN	 PTB_BYTE3_IN
#define PDDR_OUT()	 (DDRD_BYTE3 = 0xff)
//#define PDDR_IN()	 (DDRD_BYTE3 = 0)
//----------------------宏定义----------------------------
#define TOP    10
#define BOTTOM 10
#define LEFT   15
#define RIGHT  10
#define DISTANCE  20

/* LCD color */
#define White          0xFFFF
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0


//--------------------------函数------------------
//unsigned char code pic[];
void LCD_io_init();//
void ILI9325_Initial(void);//
//void show_colour_bar(void);
//void Write_Cmd_Data(unsigned char x,unsigned int y);//
void Write_Cmd(unsigned char DH,unsigned char DL);//
void Write_Data(unsigned char DH,unsigned char DL);//
//void delayms(unsigned int tt);
//void show_photo(void);
void Show_RGB (unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1,unsigned int Color);//
void Write_Data_U16(unsigned int y);//
void CLR_Screen(unsigned int bColor);//
void LCD_PutChar8x16(unsigned short x, unsigned short y, char c, unsigned int fColor, unsigned int bColor);//
void LCD_PutChar(unsigned short x, unsigned short y, char c, unsigned int fColor, unsigned int bColor) ;
void LCD_PutString(unsigned short x, unsigned short y, unsigned char *s, unsigned int fColor, unsigned int bColor);//
void LCD_PutChar8x8(unsigned short x, unsigned short y, char c, unsigned int fColor, unsigned int bColor);
void PutGB1616(unsigned short x, unsigned short  y, unsigned char c[2], unsigned int fColor,unsigned int bColor);//
void Put_pixel(uchar x,uchar y,unsigned int color);
//static void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1);//
void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1);
/*void Line(	uchar X0,
			uchar Y0,
			uchar X1,
			uchar Y1,
			unsigned int color);
void Rectangle( uchar left,
				uchar top,
				uchar right,
				uchar bottom,
				unsigned int color);

void Bar(	uchar left,
			uchar top,
			uchar right,
			uchar bottom,
			unsigned int color);*/				
#endif
