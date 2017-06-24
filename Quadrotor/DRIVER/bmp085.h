#ifndef __BMP085_H
#define __BMP085_H
#include "stm32f10x.h"
#include "stdio.h"
#include "ALG.h"
#include "math.h"

#define BMP085_ADDRESS  0xEE
#define OSS 0	// Oversampling Setting (note: code is not set up to use other OSS values)

void Single_Write_BMP085(unsigned char REG_Address,unsigned char REG_data);
unsigned char Single_Read_BMP085(unsigned char REG_Address);
short Multiple_read_BMP085(unsigned char REG_Address);
void Init_BMP085(void);
long BMP085ReadTemp(void);
long BMP085ReadPressure(void);
void BMP085Convert(void);
float Get_High(void);
float test_ref(void);

#endif


