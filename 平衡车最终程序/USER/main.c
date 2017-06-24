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
    // �����ĵط��Ϳ�����PID          �µ���=P*���+I*������+D��������-�ϴ���
    //TIME 4 ��Ȼ��APB1��  ����Ԥ��Ƶϵ��Ϊ1ʱ��APB1Ϊ36Mʱ  �����϶�ʱ����Ϊ 72 






    //һ����ʱ��ֻ����һ��������  �ң�������ӳ�� ��ֻ����ch1 ch2 
		
    //������printf �ر�ռ����ʱ��    




        //������B1,B0���           A2A1����
         //�� PWMB                 ��  PWMA  A8  
        //����	B12 B13             ����     B14 15//STBY  A12 �͵�ƽʱ����ر�	     

/*****************************************************************/

int main(void)
 {  
	 	 delay_init();
     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
     usart1_init(9600);	//��������ͨ��
	  MPU_Init();
 	  Gpio_init();  
	  Disable_Jtag(); //ʧ��jtag�ӿ�
	  PAout(15)=1;  //������� stby���Ÿߵ�ƽ���� �͵�ƽ�رյ��
	  motor_init();//�����ʼ��pwm
	  encoder_init();//��������ʼ��     

	 while(1)
{	 
		
   delay_ms(19);   //ԭ���Ŷ�ʱ����ÿ19ms�жϴ���һ�µ�������Ҫ�ö�ʱ��  ��
	  control();    //��delay����δ������Ӱ��
} 

 }