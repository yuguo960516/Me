#include "exit.h"
#include "delay.h" 
#include "ov7670.h"

void EXTI14_Init(void)
{												  
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);//PA8���ж���8
 	   	 
	EXTI_InitStructure.EXTI_Line=EXTI_Line14;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ�0 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;					//�����ȼ�0 
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���   
}

u8 ov_sta;

void EXTI15_10_IRQHandler(void)
{		 		
	if(EXTI_GetITStatus(EXTI_Line14)==SET)	
	{ 	
				OV7670_WREN=0;
        OV7670_WRST=0;	//��λдָ��		  		 
				OV7670_WRST=1;		
				
				ov_sta=1;
	}
	EXTI_ClearITPendingBit(EXTI_Line14);  //���EXTI8��·����λ						  
} 


