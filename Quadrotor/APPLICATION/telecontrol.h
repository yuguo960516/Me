#ifndef __telecontrol_h
#define __telecontrol_h
#include "sys.h"

extern u16 left_right_throttle;
extern u16 forward_back_throttle;
extern u16 up_down_throttle;
//extern u16 offset_throttle;

u32 Get_capture_1(void);
u32 Get_capture_2(void);
u32 Get_capture_3(void);

void control_left_right(void);
void control_forward_back(void);
void control_up_down(void);

//void throttle_test(void);

void Get_bluetoothdate(void);
void bluetoothdate_process(void);

#endif

