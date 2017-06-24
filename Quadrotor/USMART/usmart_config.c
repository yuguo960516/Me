#include "usmart.h"
#include "usmart_str.h"


////////////////////////////用户配置区///////////////////////////////////////////////
//这下面要包含所用到的函数所申明的头文件(用户自己添加) 
#include "delay.h"		
#include "sys.h"
#include "control.h"

												
 
//函数名列表初始化(用户自己添加)
//用户直接在这里输入要执行的函数名及其查找串
struct _m_usmart_nametab usmart_nametab[]=
{
#if USMART_USE_WRFUNS==1 	//如果使能了读写操作
	(void*)read_addr,"u32 read_addr(u32 addr)",
	(void*)write_addr,"void write_addr(u32 addr,u32 val)",	 
#endif
	(void*)delay_ms,"void delay_ms(u16 nms)",
	(void*)delay_us,"void delay_us(u32 nus)",	
	(void*)PID_Init_OUT_P,"void PID_Init_OUT_P(float Pitch_Angle_P,float Roll_Angle_P,float Yaw_Angle_P)",
	(void*)PID_Init_OUT_I,"void PID_Init_OUT_I(float Pitch_Angle_I,float Roll_Angle_I,float Yaw_Angle_I)",
	(void*)PID_Init_OUT_D,"void PID_Init_OUT_D(float Pitch_Angle_D,float Roll_Angle_D,float Yaw_Angle_D)",
	(void*)PID_Init_IN_P,"void PID_Init_IN_P(float Pitch_Rate_P,float Roll_Rate_P,float Yaw_Rate_P)",
	(void*)PID_Init_IN_I,"void PID_Init_IN_I(float Pitch_Rate_I,float Roll_Rate_I,float Yaw_Rate_I)",
	(void*)PID_Init_IN_D,"void PID_Init_IN_D(float Pitch_Rate_D,float Roll_Rate_D,float Yaw_Rate_D)",
  (void*)H_PID_Init_OUT_P,"void H_PID_Init_OUT_P(float PID_Height_P)",
  (void*)H_PID_Init_OUT_I,"void H_PID_Init_OUT_I(float PID_Height_I)",
  (void*)H_PID_Init_OUT_D,"void H_PID_Init_OUT_D(float PID_Height_D)",
  (void*)Z_PID_Init_IN_P,"void Z_PID_Init_IN_P(float PID_Acc_z_after_offset_P)",
  (void*)Z_PID_Init_IN_I,"void Z_PID_Init_IN_I(float PID_Acc_z_after_offset_I)",
  (void*)Z_PID_Init_IN_D,"void Z_PID_Init_IN_D(float PID_Acc_z_after_offset_D)",
	
};						  
///////////////////////////////////END///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//函数控制管理器初始化
//得到各个受控函数的名字
//得到函数总数量
struct _m_usmart_dev usmart_dev=
{
	usmart_nametab,
	usmart_init,
	usmart_cmd_rec,
	usmart_exe,
	usmart_scan,
	sizeof(usmart_nametab)/sizeof(struct _m_usmart_nametab),//函数数量
	0,	  	//参数数量
	0,	 	//函数ID
	1,		//参数显示类型,0,10进制;1,16进制
	0,		//参数类型.bitx:,0,数字;1,字符串	    
	0,	  	//每个参数的长度暂存表,需要MAX_PARM个0初始化
	0,		//函数的参数,需要PARM_LEN个0初始化
};   



















