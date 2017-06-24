#ifndef __OLED_H__
#define __OLED_H__

//#include "MKL_gpio.h"
//#include "common.h "





#define D0_PORT   PORTC
#define D1_PORT   PORTC
#define RST_PORT  PORTC
#define DC_PORT   PORTC

#define D0_PIN    6
#define D1_PIN    8
#define RST_PIN   10
#define DC_PIN    12

extern const uint8 F8X16[];
extern const uint8 F6x8[][6];
extern const uint8 F14x16[];
extern const uint8 F14x16_Idx[];
void LCD_WrDat(uint8 data);
void LCD_WrCmd(uint8 cmd);
void LCD_Set_Pos(uint8 x, uint8 y);
void LCD_Fill(uint8 bmp_data);
void LCD_CLS(void);
void LCD_DLY_ms(uint16 ms);
void oled_adjust(uint8 a);
void SetStartColumn(unsigned char d);
void SetAddressingMode(unsigned char d);
void SetColumnAddress(unsigned char a, unsigned char b);
void SetPageAddress(unsigned char a, unsigned char b);
void SetStartLine(unsigned char d);
void SetContrastControl(unsigned char d);
void Set_Charge_Pump(unsigned char d);
void Set_Segment_Remap(unsigned char d);
void Set_Entire_Display(unsigned char d);
void Set_Inverse_Display(unsigned char d);
void Set_Multiplex_Ratio(unsigned char d);
void Set_Display_On_Off(unsigned char d);
void SetStartPage(unsigned char d);
void Set_Common_Remap(unsigned char d);
void Set_Display_Offset(unsigned char d);
void Set_Display_Clock(unsigned char d);
void Set_Precharge_Period(unsigned char d);
void Set_Common_Config(unsigned char d);
void Set_VCOMH(unsigned char d);
void Set_NOP(void);
void LCD_Init(void) ;
void LCD_PutPixel(uint8 x,uint8 y);
void LCD_Rectangle(uint8 x1,uint8 y1,uint8 x2,uint8 y2,char gif);
//==============================================================
//函数名：LCD_P6x8Str(byte x,byte y,byte *p)
//功能描述：写入一组标准ASCII字符串
//参数：显示的位置（x,y），y为页范围0～7，要显示的字符串
//返回：无
//==============================================================  
void LCD_P6x8Str(uint8 x,uint8 y,char ch[]);
void LCD_P8x16Str(uint8 x,uint8 y,char ch[]);
//输出汉字字符串
void LCD_P14x16Str(uint8 x,uint8 y,char ch[]);
//输出汉字和字符混合字符串
void LCD_Print(uint8 x, uint8 y, char ch[]);
void Draw_BMP(uint8 x0,uint8 y0,uint8 x1,uint8 y1,uint8 bmp[]);
void OLEDdisdate(uint8 x2,uint8 y2,uint16 AD_date);
void OLEDshowtwo(uint8 x2,uint8 y2,uint16 digit);
void OLEDshowthree(uint8 x2,uint8 y2,uint16 digit);
void OLEDfloat(uint8 x2,uint8 y2,float data);
void OLEDfloat2(uint8 x2,uint8 y2,float data);
void OLEDdissign(uint8 x2,uint8 y2,float AD_date);
#endif
