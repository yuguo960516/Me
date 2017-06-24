#ifndef __MOTOR_H
#define __MOTOR_H
#include "sys.h"

void pwm_init(void);
void motor_init(void);
void Direction_Configuration(void);
void Left_Go(void);
void Left_Back(void);
void Left_Stop(void);
void Right_Go(void);
void Right_Back(void);
void Right_Stop(void);	
void Gpio_init(void);


#endif
