#include "motor.h"
#include "sys.h"


void Gpio_init()
{ 
	
	 GPIO_InitTypeDef GPIO_InitStruct;
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
   GPIO_InitStruct.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_11; //定时器1通道1..4.分别对应PA8.11
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;      // pA8 右电机， A11 左电机
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;     
   GPIO_Init(GPIOA, &GPIO_InitStruct);            


}	

void pwm_init() 
 { 
    /*两路pwm*/
	 
	
	 TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;//定义一个定时器结构体变量
	 TIM_OCInitTypeDef TIM_OCInitStructure;//定时器输出设置
	// TIM_BDTRInitTypeDef TIM_BDTRInitStructure;//关于刹车和死区的配置
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_TIM1, ENABLE);
	
                                            
      
	   
	 TIM_TimeBaseInitStruct.TIM_Period=7199;  
	 TIM_TimeBaseInitStruct.TIM_ClockDivision=0;//频率大了容易烧驱动，小了电机震动
	 TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	 TIM_TimeBaseInitStruct.TIM_Prescaler=0;
	 TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStruct);
	 
	   /**********左轮*********/
	 //设置通道4
	 TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	 TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse=400;//比较值
	 TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
   TIM_OC4Init(TIM1,&TIM_OCInitStructure);
	 TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);//左轮
	 
	 
	 
	 
	 
	/**********右轮*********/
	 
	 
	 TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	 TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse=400;//比较值
	 TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
   TIM_OC1Init(TIM1,&TIM_OCInitStructure);
	 TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);//you轮
	 
	  
	   
	  
	  TIM_ARRPreloadConfig(TIM1,ENABLE);  
   
	   TIM_Cmd(TIM1,ENABLE); 
	 
	 
	 
	  
 
   
	 TIM_CtrlPWMOutputs(TIM1, ENABLE);
 }                                 
  
 
 //B14 15 右轮          B12  13  左轮
 
void Direction_Configuration(void)//方向控制    
{	    GPIO_InitTypeDef GPIO_InitStruc;                             
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
     
		 GPIO_InitStruc.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
     GPIO_InitStruc.GPIO_Mode=GPIO_Mode_Out_PP;
     GPIO_InitStruc.GPIO_Speed=GPIO_Speed_50MHz;	
	   GPIO_Init(GPIOB,&GPIO_InitStruc);	

    GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_14|GPIO_Pin_13|GPIO_Pin_15);

}	
// 1   2               1    2
//B14 15 右轮          B12   13左轮
void Left_Go()
{  GPIO_SetBits(GPIOB,GPIO_Pin_12);
	 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}
void Left_Back()
{ GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	
}	
void Left_Stop()
{ GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13);
}	
void Right_Go()
{GPIO_SetBits(GPIOB,GPIO_Pin_15);
	GPIO_ResetBits(GPIOB,GPIO_Pin_14);
}
void Right_Back()
{GPIO_ResetBits(GPIOB,GPIO_Pin_15);
	GPIO_SetBits(GPIOB,GPIO_Pin_14);
}	
void Right_Stop()
{ 
	GPIO_ResetBits(GPIOB,GPIO_Pin_14|GPIO_Pin_15);
}	


void gpio_init1()
{

  GPIO_InitTypeDef GPIO_InitStruct;
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
   GPIO_InitStruct.GPIO_Pin=GPIO_Pin_15; 
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;      
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;     
   GPIO_Init(GPIOA, &GPIO_InitStruct); 
   GPIO_ResetBits(GPIOA,GPIO_Pin_15);
	
	
   GPIO_InitStruct.GPIO_Pin=GPIO_Pin_7; 
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;      
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;     
   GPIO_Init(GPIOB, &GPIO_InitStruct); 

	


}







void motor_init()
{  
	  Gpio_init();
	
	  pwm_init();
	 
	Direction_Configuration();
	
	  Left_Stop();
	
  	Right_Stop();
	
}




















