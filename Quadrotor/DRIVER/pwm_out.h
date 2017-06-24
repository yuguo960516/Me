#ifndef __PWM_OUT_H
#define __PWM_OUT_H

#include "stm32f10x.h"

#define MOTOR_PWM_MAX 3500

void PWM_GPIO_Init(void);
void PWM_Out_Init(u16 arr, u16 psc,s16	CCR1,s16	CCR2,s16	CCR3,s16	CCR4);
void Motor_PWM_Update(s16 motor1_pwm,s16 motor2_pwm,s16 motor3_pwm,s16 motor4_pwm);

#endif
