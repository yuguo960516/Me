#include "stm32f10x.h"
#include "mpu6050.h"
#include "ALG.h"
#include "math.h"
#include "pwm_out.h"
#include "telecontrol.h"
//#include "ms5611.h"

//#define LAUNCH_THROTTLE	200 			//∆∑…”Õ√≈
//#define ADD_THROTTLE	500 			//≤π≥‰”Õ√≈

typedef struct 
	{float 
	P,
	Pout,
	I,
	Iout,
	D,
	Dout,
	Out;
	}
PID;


extern volatile S_FLOAT_XYZ Tar_Angle;
extern volatile float Tar_Height;
extern volatile float angle_z;
extern u8 flag;

void Control_gesture(S_FLOAT_XYZ	Now_Angle, S_FLOAT_XYZ Exp_Angle);
void Control_height(float	Now_Height, float Exp_Height);
	
	
void PID_Init_OUT_P(float Pitch_Angle_P,float Roll_Angle_P,float Yaw_Angle_P);
void PID_Init_OUT_I(float Pitch_Angle_I,float Roll_Angle_I,float Yaw_Angle_I);
void PID_Init_OUT_D(float Pitch_Angle_D,float Roll_Angle_D,float Yaw_Angle_D);
void PID_Init_IN_P(float Pitch_Rate_P,float Roll_Rate_P,float Yaw_Rate_P);
void PID_Init_IN_I(float Pitch_Rate_I,float Roll_Rate_I,float Yaw_Rate_I);
void PID_Init_IN_D(float Pitch_Rate_D,float Roll_Rate_D,float Yaw_Rate_D);
	
void H_PID_Init_OUT_P(float PID_Height_P);
void H_PID_Init_OUT_I(float PID_Height_I);
void H_PID_Init_OUT_D(float PID_Height_D);
void Z_PID_Init_IN_P(float PID_Acc_z_after_offset_P);
void Z_PID_Init_IN_I(float PID_Acc_z_after_offset_I);
void Z_PID_Init_IN_D(float PID_Acc_z_after_offset_D);

	
void GET_pwm_out_value(void);


