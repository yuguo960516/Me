#include "string.h"	 
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "string.h"	 	
#include "timer.h"
#include "encoder.h"
#include "motor.h"
#include "mpu6050.h"
#include "control.h"
 #include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"     


int i,a; 

u8 reclen=0;


/******************************************************************/
    // 有误差的地方就可以用PID          新的量=P*误差+I*误差积分+D（这次误差-上次误差）
    //TIME 4 虽然在APB1上  但当预分频系数为1时即APB1为36M时  其线上定时器均为 72 






    //一个定时器只能连一个编码器  且，不能重映射 ，只能用ch1 ch2 
		
    //程序中printf 特别占运算时间    




        //编码器B1,B0左边           A2A1右轮
         //左 PWMB                 右  PWMA  A8  
        //左轮	B12 B13             右轮     B14 15//STBY  A12 低电平时电机关闭	     

/*****************************************************************/

int main(void)
 {  
	 	 delay_init();
     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
     usart1_init(9600);	//蓝牙串口通信
	  MPU_Init();
 	  Gpio_init();  
	  Disable_Jtag(); //失能jtag接口
	  PAout(15)=1;  //电机驱动 stby引脚高电平工作 低电平关闭电机
	  motor_init();//电机初始化pwm
	  encoder_init();//编码器初始化     

	 while(1)
{	 
		
   delay_ms(19);   //原本放定时器中每19ms中断处理一下但因蓝牙要用定时器  换
	  control();    //做delay函数未发现有影响
} 

 }