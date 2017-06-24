#ifndef __hmc5883_h
#define __hmc5883_h
#include "stm32f10x.h"


#define SlaveAddress 0x3C
 
void Init_HMC5883(void);
void Write_HMC5883(u8 add, u8 da);
u8 Read_HMC5883(u8 REG_Address);
void Multiple_read_HMC5883(u8*BUF);
//void hmc5883_Get_geomagnetism(short *mx,short *my,short *mz);

#endif

