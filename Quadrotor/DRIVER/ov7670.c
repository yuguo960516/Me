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
			
			
//��ʼ��OV7670
//����0:�ɹ�
//��������ֵ:�������
u8 OV7670_Init(void)
{
	u8 temp;
	u16 i=0;	  
	//����IO
 	GPIO_InitTypeDef  GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ����ض˿�ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ����ض˿�ʱ��
 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15; 	//PA8 ���� ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB,GPIO_Pin_5|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
		
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);	 //ʹ����ض˿�ʱ��
	
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin  =GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	

 	SCCB_Init();        		//��ʼ��SCCB ��IO��	  
	
	
 	if(SCCB_WR_Reg(0x12,0x80))return 1;	//��λSCCB	  
	delay_ms(50);  
	//��ȡ��Ʒ�ͺ�
 	temp=SCCB_RD_Reg(0x0b);   
	if(temp!=0x73)return 2;  
 	temp=SCCB_RD_Reg(0x0a);   
	if(temp!=0x76)return 2;
	//��ʼ������	  
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
//OV7670��������
//��ƽ������
//0:�Զ�
//1:̫��sunny
//2,����cloudy
//3,�칫��office
//4,����home
void OV7670_Light_Mode(void)
{
	u8 reg13val=0XE7;//Ĭ�Ͼ�������Ϊ�Զ���ƽ��
	u8 reg01val=0;
	u8 reg02val=0;
	
	SCCB_WR_Reg(0X13,reg13val);//COM8���� 
	SCCB_WR_Reg(0X01,reg01val);//AWB��ɫͨ������ 
	SCCB_WR_Reg(0X02,reg02val);//AWB��ɫͨ������ 
}				  
//ɫ������
//0:-2
//1:-1
//2,0
//3,1
//4,2
void OV7670_Color_Saturation(void)
{
	u8 reg4f5054val=0X80;//Ĭ�Ͼ���sat=2,��������ɫ�ȵ�����
 	u8 reg52val=0X22;
	u8 reg53val=0X5E;
 	
	SCCB_WR_Reg(0X4F,reg4f5054val);	//ɫ�ʾ���ϵ��1
	SCCB_WR_Reg(0X50,reg4f5054val);	//ɫ�ʾ���ϵ��2 
	SCCB_WR_Reg(0X51,0X00);			//ɫ�ʾ���ϵ��3  
	SCCB_WR_Reg(0X52,reg52val);		//ɫ�ʾ���ϵ��4 
	SCCB_WR_Reg(0X53,reg53val);		//ɫ�ʾ���ϵ��5 
	SCCB_WR_Reg(0X54,reg4f5054val);	//ɫ�ʾ���ϵ��6  
	SCCB_WR_Reg(0X58,0X9E);			//MTXS 
}
//��������
//0:-2
//1:-1
//2,0
//3,1
//4,2
void OV7670_Brightness(void)
{
	u8 reg55val=0X00;//Ĭ�Ͼ���bright=2
  
	SCCB_WR_Reg(0X55,reg55val);	//���ȵ��� 
}
//�Աȶ�����
//0:-2
//1:-1
//2,0
//3,1
//4,2
void OV7670_Contrast(void)
{
	u8 reg56val=0X40;//Ĭ�Ͼ���contrast=2
  
	SCCB_WR_Reg(0X56,reg56val);	//�Աȶȵ��� 
}
//��Ч����
//0:��ͨģʽ    
//1,��Ƭ
//2,�ڰ�   
//3,ƫ��ɫ
//4,ƫ��ɫ
//5,ƫ��ɫ
//6,����	    
void OV7670_Special_Effects(void)
{
	u8 reg3aval=0X04;//Ĭ��Ϊ��ͨģʽ
	u8 reg67val=0XC0;
	u8 reg68val=0X80;
	
	SCCB_WR_Reg(0X3A,reg3aval);//TSLB���� 
	SCCB_WR_Reg(0X68,reg67val);//MANU,�ֶ�Uֵ 
	SCCB_WR_Reg(0X67,reg68val);//MANV,�ֶ�Vֵ 
}	
//����ͼ���������
//��QVGA���á�
void OV7670_Window_Set(u16 sx,u16 sy,u16 width,u16 height)
{
	u16 endx;
	u16 endy;
	u8 temp; 
	endx=sx+width*2;	//V*2
 	endy=sy+height*2;
	if(endy>784)endy-=784;
	temp=SCCB_RD_Reg(0X03);				//��ȡVref֮ǰ��ֵ
	temp&=0XF0;
	temp|=((endx&0X03)<<2)|(sx&0X03);
	SCCB_WR_Reg(0X03,temp);				//����Vref��start��end�����2λ
	SCCB_WR_Reg(0X19,sx>>2);			//����Vref��start��8λ
	SCCB_WR_Reg(0X1A,endx>>2);			//����Vref��end�ĸ�8λ

	temp=SCCB_RD_Reg(0X32);				//��ȡHref֮ǰ��ֵ
	temp&=0XC0;
	temp|=((endy&0X07)<<3)|(sy&0X07);
	SCCB_WR_Reg(0X17,sy>>3);			//����Href��start��8λ
	SCCB_WR_Reg(0X18,endy>>3);			//����Href��end�ĸ�8λ
}

void camera_refresh(void)
 {
  u16 j,i;
	u16 i1,j1;
 	u16 color;	 
	u8 red,green,blue;
	if(ov_sta)//��֡�жϸ��£�
	{
		
		OV7670_RRST=0;				//��ʼ��λ��ָ�� 
		OV7670_RCK_L;
		OV7670_RCK_H;
		OV7670_RCK_L;
		OV7670_RRST=1;				//��λ��ָ����� 
		OV7670_RCK_H;
		for(j=0;j<240;j++)
		{
			for(i=0;i<320;i++)
			{
			OV7670_RCK_L;
			color=GPIOA->IDR&0XFF00;	//������
			OV7670_RCK_H; 
      delay_us(1);			
			OV7670_RCK_L;
			color|=((GPIOA->IDR>>8)&0XFF);	//������
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
	
		 ov_sta=0;					//����֡�жϱ��

				OV7670_WRST=0;	//��λдָ��		  		 
				OV7670_WRST=1;
		    OV7670_WREN=1;		
	
	 } 
 }

void data_process(void)
{
		signed char i,j,pdate,err=1;
		signed char up=0,down=0,mid=0;
		
		//ɨ������ ������

	for(j=0;j<80;j++)   
	{
	 if(err)
	 {
		for(i=0;i<60;i++)//ɨ���ϱ߽�
		{
		  pdate=largebuff[i][0];	
		  up=i;  
			if(pdate==0)
			break;
		}		
		for(i=60;i>=0;i--)//ɨ���±߽�
		{
		  pdate=largebuff[i][0];	
		  down=i;
			if(pdate==0)
			break; 
	  }
		
	 }
    else	
		{ 
		if(largebuff[up][j])   //�ϱ߽�
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
		
		if(up<=down)       //�Ƚ�
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
	


