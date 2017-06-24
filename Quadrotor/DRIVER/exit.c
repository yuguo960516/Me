#include "exit.h"
#include "delay.h" 
#include "ov7670.h"

void EXTI14_Init(void)
{												  
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);//PA8对中断线8
 	   	 
	EXTI_InitStructure.EXTI_Line=EXTI_Line14;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//使能按键所在的外部中断通道
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级0 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;					//子优先级0 
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器   
}

u8 ov_sta;

void EXTI15_10_IRQHandler(void)
{		 		
	if(EXTI_GetITStatus(EXTI_Line14)==SET)	
	{ 	
				OV7670_WREN=0;
        OV7670_WRST=0;	//复位写指针		  		 
				OV7670_WRST=1;		
				
				ov_sta=1;
	}
	EXTI_ClearITPendingBit(EXTI_Line14);  //清除EXTI8线路挂起位						  
} 


