#ifndef __TIME_H
#define __TIME_H
#include "stm32f10x.h"
#include "ALG.h"
#include "control.h"

void TIM1_Int_Init(u16 arr,u16 psc);
void TIM4_Int_Init(u16 arr,u16 psc);
 
#endif
