#ifndef __capture_h
#define __capture_h
#include "stm32f10x.h"

extern u8  TIM3CH1_CAPTURE_STA;		//输入捕获状态		    				
extern u16	TIM3CH1_CAPTURE_VAL;	//输入捕获值	
extern u8  TIM3CH2_CAPTURE_STA;		//输入捕获状态		    				
extern u16	TIM3CH2_CAPTURE_VAL;	//输入捕获值	
extern u8  TIM3CH3_CAPTURE_STA;		//输入捕获状态		    				
extern u16	TIM3CH3_CAPTURE_VAL;	//输入捕获值	
//extern u8  TIM3CH4_CAPTURE_STA;		//输入捕获状态		    				
//extern u16	TIM3CH4_CAPTURE_VAL;	//输入捕获值	

void TIM3_Cap_Init(u16 arr,u16 psc);
#endif

