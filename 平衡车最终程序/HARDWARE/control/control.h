#ifndef __CONDEF_H
#define __CONDEF_H
# include "sys.h"
void Angle_Calculate(void);
void Speed_Calculate(void);
void PWM_Calculate(void);
void Motor_Control(void);
void TIM_init(void);
void TIM4_init(void) ;
//void NVIC_Configuration(void);
void Speed_Calculate(void);
void PWM_Calculate(void);
int Balance(float Angle,float Gyro);
int Velocity(int Encoder_Left,int Encoder_Right);
void Motor_Control(void);
void Set_PWM(int Motor_Left, int Motor_Right);
void Kalman_Filter(float Accel,float Gyro);	
void TIM4_IRQHandler(void);
int Stop(float Angle);
void Xianfu_PWM(void);
void Angle_Calculate(void);
int myabs(int a);
int Turn(int Encoder_Left,int Encoder_Right,float gyroz);
void TIM4_init(void) ;
void Disable_Jtag(void);
void control(void);
void Blue_tooth(void);
void TIM4_Int_Init(u16 arr,u16 psc);
extern int i,a; 
extern  u8 reclen;  

extern int  sudu;  


#endif
