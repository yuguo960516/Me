#include "encoder.h"
#include "sys.h"

                                // һ��������ֻ�ܼ�һ������ֵ���Ҳ�����ӳ��
void encoder_right_init()       //PA1 TIM2 CH2 PA0  TIM2 CH3      �ұ�
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
	
	
	TIM_DeInit(TIM2);//���½�Timer�Ĵ�������Ϊȱʡֵ
	TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);//��TIM_TimeBaseInitStruct �е�ÿһ��������ȱʡֵ����
	TIM_TimeBaseInitStruct.TIM_Prescaler=0;//����Ƶ
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//����ʱ�ӷָ� T_dts = T_ck_int 
  TIM_TimeBaseInitStruct.TIM_Period=0x7fff;//�趨��ʱ���Զ���װ��ֵ 
	TIM_TimeBaseInitStruct.TIM_CounterMode= TIM_CounterMode_Up;	//���ϼ���
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
  
  TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge ,TIM_ICPolarity_BothEdge);//ʹ�ñ�����ģʽ3�������½�������
	
	TIM_ICStructInit(&TIM_ICInitStructure); // ��TIM_ICInitStruct �е�ÿһ��������ȱʡֵ����
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;//ѡ��ͨ��1
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;////ӳ�䵽 TI1 ��
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//����Ƶ
 TIM_ICInitStructure.TIM_ICFilter = 6;//0011 ��Ӧ8���¼����һ������
 
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;//ѡ��ͨ��2
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;//ӳ�䵽 TI2 ��
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//����Ƶ
 TIM_ICInitStructure.TIM_ICFilter = 6;//0011 ��Ӧ8���¼����һ������
 
 TIM_ICInit(TIM2,&TIM_ICInitStructure);
	

	
   TIM_SetCounter(TIM2,15000);//CNT ����������
	
	 TIM_Cmd(TIM2, ENABLE); 
	 
}




void encoder_left_init() //A7 TIM3 CH2   A6 TIM3 CH1  ���
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
	
	
	TIM_DeInit(TIM3);//���½�Timer�Ĵ�������Ϊȱʡֵ 
	TIM_TimeBaseInitStruct.TIM_Prescaler=0;//����Ƶ
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//����ʱ�ӷָ� T_dts = T_ck_int 
  TIM_TimeBaseInitStruct.TIM_Period=0xffff;//�趨��ʱ���Զ���װ��ֵ 
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);
  
  TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge ,TIM_ICPolarity_BothEdge);//ʹ�ñ�����ģʽ3�������½�������
	
	TIM_ICStructInit(&TIM_ICInitStructure); // ��TIM_ICInitStruct �е�ÿһ��������ȱʡֵ����
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;//ѡ��ͨ��1
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;////ӳ�䵽 TI1 ��
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//����Ƶ
 TIM_ICInitStructure.TIM_ICFilter =6;//0011 ��Ӧ8���¼����һ������
 
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;//ѡ��ͨ��2
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;//ӳ�䵽 TI2 ��
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//����Ƶ
 TIM_ICInitStructure.TIM_ICFilter = 6;
 
 TIM_ICInit(TIM3,&TIM_ICInitStructure);
	
	
   TIM_SetCounter(TIM3,15000);//CNT ����������
	  TIM_Cmd(TIM3, ENABLE); 
}

void encoder_init()
{ encoder_right_init();
  encoder_left_init();
}
