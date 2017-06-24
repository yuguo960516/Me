#include "encoder.h"
#include "sys.h"

                                // 一个编码器只能记一个数的值而且不能重映射
void encoder_right_init()       //PA1 TIM2 CH2 PA0  TIM2 CH3      右边
{
	
	
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;               
	TIM_ICInitTypeDef TIM_ICInitStructure;   
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	
  GPIO_InitStruct.GPIO_Pin= GPIO_Pin_0|GPIO_Pin_1;	
  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;  
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
	TIM_DeInit(TIM2);//重新将Timer寄存器设置为缺省值
	TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);//把TIM_TimeBaseInitStruct 中的每一个参数按缺省值填入
	TIM_TimeBaseInitStruct.TIM_Prescaler=0;//不分频
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//设置时钟分割 T_dts = T_ck_int 
  TIM_TimeBaseInitStruct.TIM_Period=0x7fff;//设定定时器自动重装载值 
	TIM_TimeBaseInitStruct.TIM_CounterMode= TIM_CounterMode_Up;	//向上计数
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
  
  TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge ,TIM_ICPolarity_BothEdge);//使用编码器模式3，上升下降都计数
	
	TIM_ICStructInit(&TIM_ICInitStructure); // 把TIM_ICInitStruct 中的每一个参数按缺省值填入
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;//选择通道1
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;////映射到 TI1 上
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//不分频
 TIM_ICInitStructure.TIM_ICFilter = 6;//0011 对应8个事件输出一个跳变
 
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;//选择通道2
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;//映射到 TI2 上
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//不分频
 TIM_ICInitStructure.TIM_ICFilter = 6;//0011 对应8个事件输出一个跳变
 
 TIM_ICInit(TIM2,&TIM_ICInitStructure);
	

	
   TIM_SetCounter(TIM2,15000);//CNT 计数器清零
	
	 TIM_Cmd(TIM2, ENABLE); 
	 
}




void encoder_left_init() //A7 TIM3 CH2   A6 TIM3 CH1  左边
{
 GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_ICInitTypeDef TIM_ICInitStructure;   
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	
  GPIO_InitStruct.GPIO_Pin= GPIO_Pin_7|GPIO_Pin_6;	
  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;  
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
	TIM_DeInit(TIM3);//重新将Timer寄存器设置为缺省值 
	TIM_TimeBaseInitStruct.TIM_Prescaler=0;//不分频
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//设置时钟分割 T_dts = T_ck_int 
  TIM_TimeBaseInitStruct.TIM_Period=0xffff;//设定定时器自动重装载值 
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//向上计数
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);
  
  TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge ,TIM_ICPolarity_BothEdge);//使用编码器模式3，上升下降都计数
	
	TIM_ICStructInit(&TIM_ICInitStructure); // 把TIM_ICInitStruct 中的每一个参数按缺省值填入
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;//选择通道1
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;////映射到 TI1 上
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//不分频
 TIM_ICInitStructure.TIM_ICFilter =6;//0011 对应8个事件输出一个跳变
 
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;//选择通道2
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;//映射到 TI2 上
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//不分频
 TIM_ICInitStructure.TIM_ICFilter = 6;
 
 TIM_ICInit(TIM3,&TIM_ICInitStructure);
	
	
   TIM_SetCounter(TIM3,15000);//CNT 计数器清零
	  TIM_Cmd(TIM3, ENABLE); 
}

void encoder_init()
{ encoder_right_init();
  encoder_left_init();
}
