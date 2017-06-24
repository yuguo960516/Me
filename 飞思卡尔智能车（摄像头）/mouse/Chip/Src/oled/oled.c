
#include "common.h"
#include "ASCII.h"
#include  "MKL_gpio.h" 
/*
 ----------------------管脚定义
 */
//#define LCD_DC1   PTE29_OUT =1 
//#define LCD_DC0   PTE29_OUT =0
//#define LCD_SCL1  PTE31_OUT = 1
//#define LCD_SCL0  PTE31_OUT = 0
//#define LCD_SDA1  PTE30_OUT = 1
//#define LCD_SDA0  PTE30_OUT = 0
//#define LCD_RST1  PTE25_OUT = 1
//#define LCD_RST0  PTE25_OUT = 0

#define LCD_DC1   PTE30_OUT =1 
#define LCD_DC0   PTE30_OUT =0
#define LCD_SCL1  PTE24_OUT = 1
#define LCD_SCL0  PTE24_OUT = 0
#define LCD_SDA1  PTE25_OUT = 1
#define LCD_SDA0  PTE25_OUT = 0
#define LCD_RST1  PTE29_OUT = 1
#define LCD_RST0  PTE29_OUT = 0
/*
 ----------------------管脚定义
 */

void oled_gpio()                  //OLED GPIO口初始化
{

      gpio_init (PTE25, GPO, HIGH); 
      gpio_init (PTE29, GPO, HIGH);
      gpio_init (PTE30, GPO, HIGH); 
      gpio_init (PTE24, GPO, HIGH); 
      gpio_init (PTE31, GPO, LOW);
      
       
}
/*
 ----------------OLED指令
 */
#define XLevelL		  0x00
#define XLevelH		  0x10
#define XLevel		  ((XLevelH&0x0F)*16+XLevelL)
#define Max_Column	128
#define Max_Row		  64
#define	Brightness	0xCF 
#define X_WIDTH     128
#define Y_WIDTH     64

void LCD_WrDat(uint8 data)
{
	uint8 i=8;
	LCD_DC1;;
	LCD_SCL0;;    
	while(i--)
	{
		if(data&0x80)
			LCD_SDA1;
		else{LCD_SDA0;}
		LCD_SCL1;            
		LCD_SCL0;
		data<<=1;
	}
}
void LCD_WrCmd(uint8 cmd)
{
	uint8 i=8;
	LCD_DC0;;
	LCD_SCL0;
	  //asm("nop");    
	  while(i--)
	  {
	    if(cmd&0x80)
	      LCD_SDA1;
	    else{LCD_SDA0;}
	    LCD_SCL1;            
	    LCD_SCL0;
	    cmd<<=1;
	  }
}
void LCD_Set_Pos(uint8 x, uint8 y)
{ 
  LCD_WrCmd(0xb0+y);
  LCD_WrCmd(((x&0xf0)>>4)|0x10);
  LCD_WrCmd((x&0x0f)|0x01); 
} 
void LCD_Fill(uint8 bmp_data)
{
	uint8 y,x;
	
	for(y=0;y<8;y++)
	{
		LCD_WrCmd(0xb0+y);
		LCD_WrCmd(0x01);
		LCD_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
			LCD_WrDat(bmp_data);
	}
}
void LCD_CLS(void)
{
	uint8 y,x;	
	for(y=0;y<8;y++)
	{
		LCD_WrCmd(0xb0+y);
		LCD_WrCmd(0x01);
		LCD_WrCmd(0x10); 
		for(x=0;x<X_WIDTH;x++)
			LCD_WrDat(0);
	}
}
void LCD_DLY_ms(uint16 ms)
{                         
  uint16 a;
  while(ms)
  {
    a=1335;
    while(a--);
    ms--;
  }
  return;
}
void oled_adjust(uint8 a)
{
  LCD_WrCmd(a);	//指令数据0x0000~0x003f  
}
void SetStartColumn(unsigned char d)
{
	LCD_WrCmd(0x00+d%16);		// Set Lower Column Start Address for Page Addressing Mode
						//   Default => 0x00
	LCD_WrCmd(0x10+d/16);		// Set Higher Column Start Address for Page Addressing Mode
						//   Default => 0x10
}
void SetAddressingMode(unsigned char d)
{
	LCD_WrCmd(0x20);			// Set Memory Addressing Mode
	LCD_WrCmd(d);			//   Default => 0x02
						//     0x00 => Horizontal Addressing Mode
						//     0x01 => Vertical Addressing Mode
						//     0x02 => Page Addressing Mode
}
void SetColumnAddress(unsigned char a, unsigned char b)
{
	LCD_WrCmd(0x21);			// Set Column Address
	LCD_WrCmd(a);			//   Default => 0x00 (Column Start Address)
	LCD_WrCmd(b);			//   Default => 0x7F (Column End Address)
}
void SetPageAddress(unsigned char a, unsigned char b)
{
	LCD_WrCmd(0x22);			// Set Page Address
	LCD_WrCmd(a);			//   Default => 0x00 (Page Start Address)
	LCD_WrCmd(b);			//   Default => 0x07 (Page End Address)
}
void SetStartLine(unsigned char d)
{
	LCD_WrCmd(0x40|d);			// Set Display Start Line
						//   Default => 0x40 (0x00)
}
void SetContrastControl(unsigned char d)
{
	LCD_WrCmd(0x81);			// Set Contrast Control
	LCD_WrCmd(d);			//   Default => 0x7F
}
void Set_Charge_Pump(unsigned char d)
{
	LCD_WrCmd(0x8D);			// Set Charge Pump
	LCD_WrCmd(0x10|d);			//   Default => 0x10
						//     0x10 (0x00) => Disable Charge Pump
						//     0x14 (0x04) => Enable Charge Pump
}
void Set_Segment_Remap(unsigned char d)
{
	LCD_WrCmd(0xA0|d);			// Set Segment Re-Map
						//   Default => 0xA0
						//     0xA0 (0x00) => Column Address 0 Mapped to SEG0
						//     0xA1 (0x01) => Column Address 0 Mapped to SEG127
}
void Set_Entire_Display(unsigned char d)
{
	LCD_WrCmd(0xA4|d);			// Set Entire Display On / Off
						//   Default => 0xA4
						//     0xA4 (0x00) => Normal Display
						//     0xA5 (0x01) => Entire Display On
}
void Set_Inverse_Display(unsigned char d)
{
	LCD_WrCmd(0xA6|d);			// Set Inverse Display On/Off
						//   Default => 0xA6
						//     0xA6 (0x00) => Normal Display
						//     0xA7 (0x01) => Inverse Display On
}
void Set_Multiplex_Ratio(unsigned char d)
{
	LCD_WrCmd(0xA8);			// Set Multiplex Ratio
	LCD_WrCmd(d);			//   Default => 0x3F (1/64 Duty)
}
void Set_Display_On_Off(unsigned char d)
{
	LCD_WrCmd(0xAE|d);			// Set Display On/Off
						//   Default => 0xAE
						//     0xAE (0x00) => Display Off
						//     0xAF (0x01) => Display On
}
void SetStartPage(unsigned char d)
{
	LCD_WrCmd(0xB0|d);			// Set Page Start Address for Page Addressing Mode
						//   Default => 0xB0 (0x00)
}
void Set_Common_Remap(unsigned char d)
{
	LCD_WrCmd(0xC0|d);			// Set COM Output Scan Direction
						//   Default => 0xC0
						//     0xC0 (0x00) => Scan from COM0 to 63
						//     0xC8 (0x08) => Scan from COM63 to 0
}
void Set_Display_Offset(unsigned char d)
{
	LCD_WrCmd(0xD3);			// Set Display Offset
	LCD_WrCmd(d);			//   Default => 0x00
}
void Set_Display_Clock(unsigned char d)
{
	LCD_WrCmd(0xD5);			// Set Display Clock Divide Ratio / Oscillator Frequency
	LCD_WrCmd(d);			//   Default => 0x80
						//     D[3:0] => Display Clock Divider
						//     D[7:4] => Oscillator Frequency
}

void Set_Precharge_Period(unsigned char d)
{
	LCD_WrCmd(0xD9);			// Set Pre-Charge Period
	LCD_WrCmd(d);			//   Default => 0x22 (2 Display Clocks [Phase 2] / 2 Display Clocks [Phase 1])
						//     D[3:0] => Phase 1 Period in 1~15 Display Clocks
						//     D[7:4] => Phase 2 Period in 1~15 Display Clocks
}

void Set_Common_Config(unsigned char d)
{
	LCD_WrCmd(0xDA);			// Set COM Pins Hardware Configuration
	LCD_WrCmd(0x02|d);			//   Default => 0x12 (0x10)
						//     Alternative COM Pin Configuration
						//     Disable COM Left/Right Re-Map
}
void Set_VCOMH(unsigned char d)
{
	LCD_WrCmd(0xDB);			// Set VCOMH Deselect Level
	LCD_WrCmd(d);			//   Default => 0x20 (0.77*VCC)
}

void Set_NOP(void)
{
	LCD_WrCmd(0xE3);			// Command for No Operation
}
void LCD_Init(void)        
{
	oled_gpio();
	LCD_SCL1;
	//LCD_CS=1;	//预制SLK和SS为高电平   		
	LCD_RST0;
	LCD_DLY_ms(50);
	LCD_RST1;
	
	//从上电到下面开始初始化要有足够的时间，即等待RC复位完毕
  Set_Display_On_Off(0x00);		  // Display Off (0x00/0x01)
  Set_Display_Clock(0x80);		  // Set Clock as 100 Frames/Sec
  Set_Multiplex_Ratio(0x3F);		// 1/64 Duty (0x0F~0x3F)
  Set_Display_Offset(0x00);		  // Shift Mapping RAM Counter (0x00~0x3F)
  SetStartLine(0x00);			      // Set Mapping RAM Display Start Line (0x00~0x3F)
  Set_Charge_Pump(0x04);		    // Enable Embedded DC/DC Converter (0x00/0x04)
  SetAddressingMode(0x02);		  // Set Page Addressing Mode (0x00/0x01/0x02)
  Set_Segment_Remap(0x01);		  // Set SEG/Column Mapping     0x00左右反置 0x01正常
  Set_Common_Remap(0x08);			  // Set COM/Row Scan Direction 0x00上下反置 0x08正常
  Set_Common_Config(0x10);		  // Set Sequential Configuration (0x00/0x10)
  SetContrastControl(Brightness);	// Set SEG Output Current
  Set_Precharge_Period(0xF1);		// Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
  Set_VCOMH(0x40);			        // Set VCOM Deselect Level
  Set_Entire_Display(0x00);		  // Disable Entire Display On (0x00/0x01)
  Set_Inverse_Display(0x00);		// Disable Inverse Display On (0x00/0x01)  
  Set_Display_On_Off(0x01);		  // Display On (0x00/0x01)
  LCD_Fill(0x00);  //初始清屏
	LCD_Set_Pos(0,0); 
}
//==============================================================
//函数名： void LCD_PutPixel(byte x,byte y)
//功能描述：绘制一个点（x,y）
//参数：真实坐标值(x,y),x的范围0～127，y的范围0～64
//返回：无
//==============================================================
void LCD_PutPixel(uint8 x,uint8 y)
{
   uint8 data1;  //data1当前点的数据 
	 
    LCD_Set_Pos(x,y); 
	data1 = 0x01<<(y%8); 	
	LCD_WrCmd(0xb0+(y>>3));
	LCD_WrCmd(((x&0xf0)>>4)|0x10);
	LCD_WrCmd((x&0x0f)|0x00);
	LCD_WrDat(data1); 	 	
}
//==============================================================
//函数名： void LCD_Rectangle(byte x1,byte y1,
//                   byte x2,byte y2,byte color,byte gif)
//功能描述：绘制一个实心矩形
//参数：左上角坐标（x1,y1）,右下角坐标（x2，y2）
//      其中x1、x2的范围0～127，y1，y2的范围0～63，即真实坐标值
//返回：无
//==============================================================
void LCD_Rectangle(uint8 x1,uint8 y1,uint8 x2,uint8 y2,char gif)
{
	uint8 n; 
		
	LCD_Set_Pos(x1,y1>>3);
	for(n=x1;n<=x2;n++)
	{
		LCD_WrDat(0x01<<(y1%8)); 			
		if(gif == 1) 	LCD_DLY_ms(50);
	}  
	LCD_Set_Pos(x1,y2>>3);
  for(n=x1;n<=x2;n++)
	{
		LCD_WrDat(0x01<<(y2%8)); 			
		if(gif == 1) 	LCD_DLY_ms(5);
	}
	
} 
//==============================================================
//函数名：LCD_P6x8Str(byte x,byte y,byte *p)
//功能描述：写入一组标准ASCII字符串
//参数：显示的位置（x,y），y为页范围0～7，要显示的字符串
//返回：无
//==============================================================  
void LCD_P6x8Str(uint8 x,uint8 y,char ch[])
{
  uint8 c=0,i=0,j=0;      
  while (ch[j]!='\0') 
  {    
    c =ch[j]-32;
    if(x>126){x=0;y++;}
    LCD_Set_Pos(x,y);    
  	for(i=0;i<6;i++)     
  	  LCD_WrDat(F6x8[c][i]);  
  	x+=6;
  	j++;
  }
}
//==============================================================
//函数名：LCD_P8x16Str(byte x,byte y,byte *p)
//功能描述：写入一组标准ASCII字符串
//参数：显示的位置（x,y），y为页范围0～7，要显示的字符串
//返回：无
//==============================================================  
void LCD_P8x16Str(uint8 x,uint8 y,char ch[])
{
   uint8 c=0,i=0,j=0;
        
  while (ch[j]!='\0')
  {    
    c =ch[j]-32;
    if(x>120){x=0;y++;}
    LCD_Set_Pos(x,y);    
  	for(i=0;i<8;i++)     
  	  LCD_WrDat(F8X16[c*16+i]);
  	LCD_Set_Pos(x,y+1);    
  	for(i=0;i<8;i++)     
  	  LCD_WrDat(F8X16[c*16+i+8]);  
  	x+=8;
  	j++;
  }
}
//*****************输出汉字字符串
void LCD_P14x16Str(uint8 x,uint8 y, char ch[])
{
	uint8 wm=0,ii = 0;
	uint16 adder=1; 
	
	while(ch[ii] != '\0')
	{
  	wm = 0;
  	adder = 1;
  	while(F14x16_Idx[wm] > 127)
  	{
  		if(F14x16_Idx[wm] == ch[ii])
  		{
  			if(F14x16_Idx[wm + 1] == ch[ii + 1])
  			{
  				adder = wm * 14;
  				break;
  			}
  		}
  		wm += 2;			
  	}
  	if(x>118){x=0;y++;}
  	LCD_Set_Pos(x , y); 
  	if(adder != 1)// 显示汉字					
  	{
  		LCD_Set_Pos(x , y);
  		for(wm = 0;wm < 14;wm++)               
  		{
  			LCD_WrDat(F14x16[adder]);	
  			adder += 1;
  		}      
  		LCD_Set_Pos(x,y + 1); 
  		for(wm = 0;wm < 14;wm++)          
  		{
  			LCD_WrDat(F14x16[adder]);
  			adder += 1;
  		}   		
  	}
  	else			  //显示空白字符			
  	{
  		ii += 1;
      LCD_Set_Pos(x,y);
  		for(wm = 0;wm < 16;wm++)
  		{
  				LCD_WrDat(0);
  		}
  		LCD_Set_Pos(x,y + 1);
  		for(wm = 0;wm < 16;wm++)
  		{   		
  				LCD_WrDat(0);	
  		}
  	}
  	x += 14;
  	ii += 2;
	}
}
//******************输出汉字和字符混合字符串
void LCD_Print(uint8 x, uint8 y,  char ch[])
{
	 char ch2[3];
	uint8 ii=0;        
	while(ch[ii] != '\0')
	{
		if(ch[ii] > 126)
		{
			ch2[0] = ch[ii];
	 		ch2[1] = ch[ii + 1];
			ch2[2] = '\0';			//汉字为两个字节
			LCD_P14x16Str(x , y, ch2);	//显示汉字
			x += 14;
			ii += 2;
		}
		else
		{
			ch2[0] = ch[ii];	
			ch2[1] = '\0';			//字母占一个字节
			LCD_P6x8Str(x , y , ch2);	//显示字母
			x += 8;
			ii+= 1;
		}
	}
} 

//==============================================================
//函数名： void Draw_BMP(byte x,byte y)
//功能描述：显示BMP图片128×64
//参数：起始点坐标(x,y),x的范围0～127，y为页的范围0～7
//返回：无
//==============================================================
void Draw_BMP(uint8 x0,uint8 y0,uint8 x1,uint8 y1,uint8 bmp[])
{ 	
  uint16 ii=0;
  uint8 x,y;
  
  if(y1%8==0) y=y1/8;      
  else y=y1/8+1;
	for(y=y0;y<=y1;y++)
	{
		LCD_Set_Pos(x0,y);				
    for(x=x0;x<x1;x++)
	    {      
	    	LCD_WrDat(bmp[ii++]);	    	
	    }
	}
}
//***************oled显示AD值
void OLEDdisdate(uint8 x2,uint8 y2,uint16 AD_date)
{     
	   char oled[6];
           uint16 date;
           date=AD_date;
           oled[0]= date/10000+0x30;
	   oled[1]= date/1000%10+0x30;
           oled[2]= date/100%10+0x30;
	   oled[3]= date/10%10+0x30;
	   oled[4]= date%10+0x30;
	   oled[5]='\0';
	   LCD_P8x16Str(x2,y2,oled);
}
void OLEDdissign(uint8 x2,uint8 y2,float AD_date)
{     
	   char oled[6];
           int date;
           date=(int)AD_date;

           if(date>=0)
           {   
              oled[0]= ' ';  
              date=date;
           }
           if(date<0)
           {
              oled[0]= '-';
              date=-date;
           }
	   oled[1]= date/1000%10+0x30;
           oled[2]= date/100%10+0x30;
	   oled[3]= date/10%10+0x30;
	   oled[4]= date%10+0x30;
	   oled[5]='\0';
	   LCD_P6x8Str(x2,y2,oled);
}
void OLEDshowtwo(uint8 x2,uint8 y2,uint16 digit)
{     
	   char oled[3];

	   oled[0]= digit/10+0x30;
	   oled[1]= digit%10+0x30;
	   oled[2]='\0';
	   LCD_P6x8Str(x2,y2,oled);
}
void OLEDshowthree(uint8 x2,uint8 y2,uint16 digit)
{     
	   char oled[4];

	   oled[0]= digit/100+0x30;
	   oled[1]= digit%100/10+0x30;
           oled[2]= digit%10+0x30;
	   oled[3]='\0';
	   LCD_P6x8Str(x2,y2,oled);
}
void OLEDfloat(uint8 x2,uint8 y2,float data)
{     
	   char oled[4];
           uint16 data1;
           data1=(uint16)(data*10);

	   oled[0]= data1/10+0x30;
           oled[1]= 46;
	   oled[2]= data1%10+0x30;
	   oled[3]='\0';
	   LCD_P6x8Str(x2,y2,oled);
}
void OLEDfloat2(uint8 x2,uint8 y2,float data)
{     
	   char oled[5];
           uint16 data1;
           data1=(uint16)(data*100);

	   oled[0]= data1/100+0x30;
           oled[1]= 46;
	   oled[2]= data1%100/10+0x30;
           oled[3]= data1%10+0x30;
	   oled[4]='\0';
	   LCD_P6x8Str(x2,y2,oled);
}



