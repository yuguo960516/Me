#include "pwm_out.h"


void PWM_GPIO_Init()
{
	  GPIO_InitTypeDef GPIO_InitStructureA;
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_AFIO, ENABLE);
	
		GPIO_InitStructureA.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
		GPIO_InitStructureA.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructureA.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructureA); 

}

void PWM_Out_Init(u16 arr, u16 psc,s16	CCR1,s16	CCR2,s16	CCR3,s16	CCR4)//CCR为16位的数
{	 
		
		TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;
	  
		
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
	  
			
  	TIM_TimeBaseStructure.TIM_Period = arr;
  	TIM_TimeBaseStructure.TIM_Prescaler = psc;
  	TIM_TimeBaseStructure.TIM_ClockDivision = 1;
  	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
  	//通道1
  	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  	TIM_OCInitStructure.TIM_Pulse = CCR1;
  	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
		
  	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
  	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
		
		//通道2 	
  	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  	TIM_OCInitStructure.TIM_Pulse = CCR2;
  	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
		
  	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
  	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
		
		//通道3
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  	TIM_OCInitStructure.TIM_Pulse = CCR3;
  	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
		
  	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
  	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
		
		//通道4
  	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  	TIM_OCInitStructure.TIM_Pulse = CCR4;
  	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
		
  	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
  	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

		TIM_ARRPreloadConfig(TIM2,ENABLE);
		TIM_Cmd(TIM2, ENABLE);		
}




/*
 
 描述  ：电机PWM输出更新函数
 
 */ 
void Motor_PWM_Update(s16 motor1_pwm,s16 motor2_pwm,s16 motor3_pwm,s16 motor4_pwm)
{		
	if(motor1_pwm	>	MOTOR_PWM_MAX)	
		motor1_pwm = MOTOR_PWM_MAX;
	if(motor2_pwm	>	MOTOR_PWM_MAX)	
		motor2_pwm = MOTOR_PWM_MAX;
	if(motor3_pwm	>	MOTOR_PWM_MAX)	
		motor3_pwm = MOTOR_PWM_MAX;
	if(motor4_pwm	>	MOTOR_PWM_MAX)	
		motor4_pwm = MOTOR_PWM_MAX;
	
	if(motor1_pwm	<	0)	
		motor1_pwm = 0;
	if(motor2_pwm	<	0)	
		motor2_pwm = 0;
	if(motor3_pwm	<	0)	
		motor3_pwm = 0;
	if(motor4_pwm	<	0)	
		motor4_pwm = 0;
	
//	TIM2->CCR1 = motor1_pwm;      //待定通道对应电机。
//	TIM2->CCR2 = motor2_pwm;
//	TIM2->CCR3 = motor3_pwm;
//	TIM2->CCR4 = motor4_pwm;
//	
	PWM_Out_Init(19999,71,motor1_pwm,motor2_pwm,motor3_pwm,motor4_pwm);
}

