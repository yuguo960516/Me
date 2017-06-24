#ifndef __ALG_H
#define __ALG_H

#include "stm32f10x.h"
#include "mpu6050.h"
#include "math.h"
#include "inv_mpu.h"
#include "hmc5883.h"
#include "stdio.h"
#include "led.h"
//#include "ms5611.h"
#include "bmp085.h"

#define HALF_FS 0.0005f     //�������ڵ�һ�룬��λ��s
#define FILTER_WINDOW 20					//�����˲����ڳ���

#define GYROW_DS 	0.0610351f				//���ٶȱ�ɶ�/S   �˲�����Ӧ����2000��ÿ��  Gyro_G=1/16.375=0.0610687
#define GYROW_HDS	0.0010653f				//���ٶȱ�ɻ���/S	�˲�����Ӧ����2000��ÿ��

#define IMU_KP 1.5f     					//����
#define IMU_KI 0.0005f 						//����

typedef struct
{
	float X;
	float Y;
	float Z;
}S_FLOAT_XYZ;

typedef struct
{
	s16 X;
	s16 Y;
	s16 Z;
}S_INT16_XYZ;

typedef struct
{
	s32 X;
	s32 Y;
	s32 Z;
}S_INT32_XYZ;


extern volatile S_FLOAT_XYZ Angle; //�����ںϼ�����ĽǶ�
extern volatile S_FLOAT_XYZ	Gyro_Offset_angle_speed;
extern S_INT16_XYZ	Acc_date_after_Offset;


extern u8 offsetflag;
extern   float  Preref;


void OFFSET_function(void);
void ACC_fliter(void);
void Prepare_Data(void);
void AGLupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);
void ALG_Date_Init(void);
void GET_MPU_date(void);
void Date_Offset(u16 cnt);
void GET_final_angle(void);
void GEO_fliter(void);
void Date_after_offset(void);

void source_date(void);
void mpu6050_send_data(short yroll,short ypitch,short roll,short pitch,short yaw);
void usart1_niming_report(u8 fun,u8*data,u8 len);
void usart1_send_char(u8 c);
void sendd(void);

#endif

