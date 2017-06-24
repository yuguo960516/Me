#include "time.h"
#include "pwm_out.h"
#include "nrf24l01.h"
//#include "usmart.h"
#include "stdio.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "iicc.h"
#include "bmp085.h"
#include "delay.h"
#include "usart.h"
#include "usart3.h"
#include "capture.h"
#include "exit.h"
#include "sccb.h"
#include "ov7670.h"
#include "telecontrol.h"



int main()
{
	//float h;
	//u32 temp,temp2,temp3;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();
  uart_init(115200);
	LED_Init();
	//NRF24L01_Init();
	MPU_Init();
	delay_ms(1000);
	IICC_Init();
  Init_HMC5883();
	//MS5611_init();
	Init_BMP085();
	mpu_dmp_init();
	ALG_Date_Init();
	//usmart_dev.init(SystemCoreClock/1000000);
	PWM_GPIO_Init();
  //PWM_Out_Init(4999,71,1999,1999,1999,1999);
	TIM1_Int_Init(20000-1,72-1);
	usart3_init(9600);	//��ʼ������3Ϊ:9600,������
	TIM3_Cap_Init(4999,71);
	OV7670_Init();  
	EXTI14_Init();
	OV7670_Window_Set(12,176,240,320);	//���ô���
	
  OV7670_CS=0;					
	
	while(1)
	{
		camera_refresh();
		bluetoothdate_process();
	}
	
//}
	
//	while(1)
//	{

//		

//		if(TIM3CH1_CAPTURE_STA&0X80)//�ɹ�������һ��������
//		{
//			
//			
//			temp=TIM3CH1_CAPTURE_VAL;//�õ��ܵĸߵ�ƽʱ��
//			printf("HIGH:%d us\r\n",temp);//��ӡ�ܵĸߵ�ƽʱ��
//			TIM3CH1_CAPTURE_STA=0;//������һ�β���
//		}
//		
//		if(TIM3CH2_CAPTURE_STA&0X80)//�ɹ�������һ��������
//		{
//			
//			temp2=TIM3CH2_CAPTURE_VAL;//�õ��ܵĸߵ�ƽʱ��
//			printf("HIGH2:%d us\r\n",temp2);//��ӡ�ܵĸߵ�ƽʱ��
//			TIM3CH2_CAPTURE_STA=0;//������һ�β���
//		}
//		
//		if(TIM3CH3_CAPTURE_STA&0X80)//�ɹ�������һ��������
//		{
//			
//			temp3=TIM3CH3_CAPTURE_VAL;//�õ��ܵĸߵ�ƽʱ��
//			printf("HIGH3:%d us\r\n",temp3);//��ӡ�ܵĸߵ�ƽʱ��
//			TIM3CH3_CAPTURE_STA=0;//������һ�β���
//		}
//		
//	}
	


//	while(1)
//	{
//		Get_bluetoothdate();							
//	}

//	while(1)
//	{
//	source_date();
//	sendd();
//	}
	
//	while(1)
//	{
////		OFFSET_function();
////		printf("\r\nУ׼��ѹֵ��%f \r\n",Preref	);
////		test_ref();
////		delay_ms(10);
////		h=Get_High();
////		Get_High();
////		MS561101BA_getTemperature();
////	  printf("\r\n��ǰ�߶�ֵΪ:%f \r\n",h);
//	}
//	


}





