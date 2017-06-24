#include "sys.h"
#include "ov7670.h"
#include "ov7670cfg.h"	  
#include "delay.h"
#include "usart.h"			 
#include "sccb.h"	
#include "exit.h"
#include "led.h"
 	    
			
u16 largebuff[60][80];

u8 list[80];
			
			
//初始化OV7670
//返回0:成功
//返回其他值:错误代码
u8 OV7670_Init(void)
{
	u8 temp;
	u16 i=0;	  
	//设置IO
 	GPIO_InitTypeDef  GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能相关端口时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能相关端口时钟
 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15; 	//PA8 输入 上拉
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB,GPIO_Pin_5|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
		
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);	 //使能相关端口时钟
	
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin  =GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	

 	SCCB_Init();        		//初始化SCCB 的IO口	  
	
	
 	if(SCCB_WR_Reg(0x12,0x80))return 1;	//复位SCCB	  
	delay_ms(50);  
	//读取产品型号
 	temp=SCCB_RD_Reg(0x0b);   
	if(temp!=0x73)return 2;  
 	temp=SCCB_RD_Reg(0x0a);   
	if(temp!=0x76)return 2;
	//初始化序列	  
	for(i=0;i<sizeof(ov7670_init_reg_tbl)/sizeof(ov7670_init_reg_tbl[0]);i++)
	{
	   	SCCB_WR_Reg(ov7670_init_reg_tbl[i][0],ov7670_init_reg_tbl[i][1]);
  }
			 delay_ms(1500);	
			 OV7670_Light_Mode();
			 OV7670_Color_Saturation();
			 OV7670_Brightness();
			 OV7670_Contrast();
			 OV7670_Special_Effects();
	
   	return 0x00; 	//ok
} 
////////////////////////////////////////////////////////////////////////////
//OV7670功能设置
//白平衡设置
//0:自动
//1:太阳sunny
//2,阴天cloudy
//3,办公室office
//4,家里home
void OV7670_Light_Mode(void)
{
	u8 reg13val=0XE7;//默认就是设置为自动白平衡
	u8 reg01val=0;
	u8 reg02val=0;
	
	SCCB_WR_Reg(0X13,reg13val);//COM8设置 
	SCCB_WR_Reg(0X01,reg01val);//AWB蓝色通道增益 
	SCCB_WR_Reg(0X02,reg02val);//AWB红色通道增益 
}				  
//色度设置
//0:-2
//1:-1
//2,0
//3,1
//4,2
void OV7670_Color_Saturation(void)
{
	u8 reg4f5054val=0X80;//默认就是sat=2,即不调节色度的设置
 	u8 reg52val=0X22;
	u8 reg53val=0X5E;
 	
	SCCB_WR_Reg(0X4F,reg4f5054val);	//色彩矩阵系数1
	SCCB_WR_Reg(0X50,reg4f5054val);	//色彩矩阵系数2 
	SCCB_WR_Reg(0X51,0X00);			//色彩矩阵系数3  
	SCCB_WR_Reg(0X52,reg52val);		//色彩矩阵系数4 
	SCCB_WR_Reg(0X53,reg53val);		//色彩矩阵系数5 
	SCCB_WR_Reg(0X54,reg4f5054val);	//色彩矩阵系数6  
	SCCB_WR_Reg(0X58,0X9E);			//MTXS 
}
//亮度设置
//0:-2
//1:-1
//2,0
//3,1
//4,2
void OV7670_Brightness(void)
{
	u8 reg55val=0X00;//默认就是bright=2
  
	SCCB_WR_Reg(0X55,reg55val);	//亮度调节 
}
//对比度设置
//0:-2
//1:-1
//2,0
//3,1
//4,2
void OV7670_Contrast(void)
{
	u8 reg56val=0X40;//默认就是contrast=2
  
	SCCB_WR_Reg(0X56,reg56val);	//对比度调节 
}
//特效设置
//0:普通模式    
//1,负片
//2,黑白   
//3,偏红色
//4,偏绿色
//5,偏蓝色
//6,复古	    
void OV7670_Special_Effects(void)
{
	u8 reg3aval=0X04;//默认为普通模式
	u8 reg67val=0XC0;
	u8 reg68val=0X80;
	
	SCCB_WR_Reg(0X3A,reg3aval);//TSLB设置 
	SCCB_WR_Reg(0X68,reg67val);//MANU,手动U值 
	SCCB_WR_Reg(0X67,reg68val);//MANV,手动V值 
}	
//设置图像输出窗口
//对QVGA设置。
void OV7670_Window_Set(u16 sx,u16 sy,u16 width,u16 height)
{
	u16 endx;
	u16 endy;
	u8 temp; 
	endx=sx+width*2;	//V*2
 	endy=sy+height*2;
	if(endy>784)endy-=784;
	temp=SCCB_RD_Reg(0X03);				//读取Vref之前的值
	temp&=0XF0;
	temp|=((endx&0X03)<<2)|(sx&0X03);
	SCCB_WR_Reg(0X03,temp);				//设置Vref的start和end的最低2位
	SCCB_WR_Reg(0X19,sx>>2);			//设置Vref的start高8位
	SCCB_WR_Reg(0X1A,endx>>2);			//设置Vref的end的高8位

	temp=SCCB_RD_Reg(0X32);				//读取Href之前的值
	temp&=0XC0;
	temp|=((endy&0X07)<<3)|(sy&0X07);
	SCCB_WR_Reg(0X17,sy>>3);			//设置Href的start高8位
	SCCB_WR_Reg(0X18,endy>>3);			//设置Href的end的高8位
}

void camera_refresh(void)
 {
  u16 j,i;
	u16 i1,j1;
 	u16 color;	 
	u8 red,green,blue;
	if(ov_sta)//有帧中断更新？
	{
		
		OV7670_RRST=0;				//开始复位读指针 
		OV7670_RCK_L;
		OV7670_RCK_H;
		OV7670_RCK_L;
		OV7670_RRST=1;				//复位读指针结束 
		OV7670_RCK_H;
		for(j=0;j<240;j++)
		{
			for(i=0;i<320;i++)
			{
			OV7670_RCK_L;
			color=GPIOA->IDR&0XFF00;	//读数据
			OV7670_RCK_H; 
      delay_us(1);			
			OV7670_RCK_L;
			color|=((GPIOA->IDR>>8)&0XFF);	//读数据
			OV7670_RCK_H; 
			delay_us(1);	
				red=(u8)((color>>11)& 0000000000011111);
				green=(u8)((color>>5)&0000000000111111);
				blue=(u8)(color&      0000000000011111);
			if(j%4==0)
			{			
					i1=j/4;
				if(i%4==0)
				{
					 j1=i/4;
					if((red>0x06)||(green>0x0C)||(blue>0x06))
					{
						largebuff[i1][j1] =1;
						//printf("%d",	largebuff[i1][j1]);
					}
          else
						{
							largebuff[i1][j1] =0;
							//printf("%d",largebuff[i1][j1]);
						}	
				}		
			}	
				
		}			
	}  
		
		   data_process();
//   for(j1=0;j1<80;j1++)
//		{
//			for(i1=0;i1<60;i1++)
//			{
//	
//				printf("%d",largebuff[i1][j1]);	
//	
//			}
//		}
	   //printf("********************\r\n");
	
		 ov_sta=0;					//清零帧中断标记

				OV7670_WRST=0;	//复位写指针		  		 
				OV7670_WRST=1;
		    OV7670_WREN=1;		
	
	 } 
 }

void data_process(void)
{
		signed char i,j,pdate,err=1;
		signed char up=0,down=0,mid=0;
		
		//扫描首列 从左到右

	for(j=0;j<80;j++)   
	{
	 if(err)
	 {
		for(i=0;i<60;i++)//扫描上边界
		{
		  pdate=largebuff[i][0];	
		  up=i;  
			if(pdate==0)
			break;
		}		
		for(i=60;i>=0;i--)//扫描下边界
		{
		  pdate=largebuff[i][0];	
		  down=i;
			if(pdate==0)
			break; 
	  }
		
	 }
    else	
		{ 
		if(largebuff[up][j])   //上边界
		{  
		 for(i=up+1;i<60;i++)
		 {
		  pdate=largebuff[i][j];
			up=i; 
 			 if(pdate==0)
			 break; 			 
		 }
		}
		else
		{
		 for(i=up;i>=0;i--)  
		 {
		  pdate=largebuff[i-1][j]; 
 			  up=i; 
			 if(pdate==0)
			 break; 			 
		 }		
		}
		if(largebuff[down][j])
		{  
		 for(i=up-1;i>=0;i--)
		 {
		  pdate=largebuff[i][j];
			down=i; 
 			 if(pdate==0)
			 break; 			 
		 }
		}
		else
		{
		 for(i=up;i>=0;i--)
		 {
		  pdate=largebuff[i+1][j];
 			  down=i; 
			 if(pdate==0)
			 break; 			 
		 }		
		}
			
		}	
		
		if(up<=down)       //比较
		{ 
		err=0; 
		mid=(up+down)/2;
		} 
		else
    {
    err=1;
		mid=60;
		}		
     
   list[j]=mid;  
//	largebuff[mid][j]=1;	
	}
	
	
}
	


