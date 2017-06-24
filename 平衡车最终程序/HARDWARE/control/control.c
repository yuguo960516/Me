#include "control.h"  
#include "sys.h"
#include "mpu6050.h"
#include "motor.h"
#include "encoder.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "encoder.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 

#include "lcd.h"
short aacx,aacy,aacz;		//���ٶȴ�����ԭʼ����
float ay_angle;//	ȥ�����ƮƯ�ƺ�����
short gyrox,gyroy,gyroz;	//������ԭʼ����
static float Angle;//�����սǶ�
float Gyro;
float Gyro_x;//���ս��ٶ�
float Gyro_y;
int BalancePWM, VelocityPWM, TurnPWM;
int Encoder_Left,Encoder_Right;
short A,B,C;

//**************����***********/		
int sudu;
int zhuanxiang;




//******����������************


float PWM;           //�ۺ�PWM����
float speed_r_l;	//���ת��
float speed;      //���ת���˲�
int Motor_Right;
int Motor_Left;
                          //Motor_left motor1   
													
													

/******************������λ��***************************************/	

/*    void usart1_send_char(u8 c)
{   	
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); //ѭ������,ֱ���������   
	USART_SendData(USART1,c);  
} 
//�������ݸ�����������λ�����(V2.6�汾)
//fun:������. 0XA0~0XAF
//data:���ݻ�����,���28�ֽ�!!
//len:data����Ч���ݸ���
void usart1_niming_report(u8 fun,u8*data,u8 len)
{
	u8 send_buf[32];
	u8 i;
	if(len>28)return;	//���28�ֽ����� 
	send_buf[len+3]=0;	//У��������
	send_buf[0]=0X88;	//֡ͷ
	send_buf[1]=fun;	//������
	send_buf[2]=len;	//���ݳ���
	for(i=0;i<len;i++)send_buf[3+i]=data[i];			//��������
	for(i=0;i<len+3;i++)send_buf[len+3]+=send_buf[i];	//����У���	
	for(i=0;i<len+4;i++)usart1_send_char(send_buf[i]);	//�������ݵ�����1 
}
//���ͼ��ٶȴ��������ݺ�����������
//aacx,aacy,aacz:x,y,z������������ļ��ٶ�ֵ
//gyrox,gyroy,gyroz:x,y,z�������������������ֵ
void mpu6050_send_data(short ay_angle,short Angle,short Gyro)
{  u8 tbuf[6]; 
	
	
	tbuf[0]=(ay_angle>>8)&0XFF;
	tbuf[1]=ay_angle&0XFF;
	tbuf[2]=(Angle>>8)&0XFF;
	tbuf[3]=Angle&0XFF;
	tbuf[4]=(Gyro>>8)&0XFF;
	tbuf[5]=Gyro&0XFF;
	
		usart1_niming_report(0XA1,tbuf,12);//�Զ���֡,0XA1
	}
/******************��λ��***************************************/	
	


	
	
	
/********************������ʱ��******�ж�һ���ַ��Ƿ������****************/	
	
	
	
void TIM4_Int_Init(u16 arr,u16 psc)
{	
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//TIM7ʱ��ʹ��    
	 
	//��ʱ��TIM7��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM7�ж�,��������ж�
	
	TIM_Cmd(TIM4,ENABLE);//������ʱ��7
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//�����ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
	
}
	 
	


extern vu16 USART1_RX_STA;

//��ʱ��4�жϷ������		    
void TIM4_IRQHandler(void)
{ 	
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)//�Ǹ����ж�
	{	 		
		USART1_RX_STA|=1<<15;	//��ǽ������
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update  );  //���TIM7�����жϱ�־    
		TIM_Cmd(TIM4, DISABLE);  //�ر�TIM4 
		
	}	    
}
 













	
	
	
	
/*************************PWM����**********************/	
	
  //��ΧΪ2gʱ�������ϵ��16384 LSB/g
 //�ǶȽ�Сʱ��x=sinx�õ��Ƕȣ����ȣ�, deg = rad*180/3.14
//  ��Ϊx>=sinx,�ʳ���1.3�ʵ��Ŵ�
int Turn (int Encoder_Left,int Encoder_Right,float gyroz)
{ float Turn,Kp=-9,Bias;
	Bias=gyroz-0;
	
	Turn=Bias*Kp;
	Turn+=zhuanxiang;
	return Turn;
}

int Velocity(int Encoder_Left,int Encoder_Right)
{  static float Velocity,Encoder_Least,Encoder;
	static float Encoder_Integral;
	float kp=100,ki=kp/200;

	Encoder_Least=(Encoder_Left+Encoder_Right)-0;//�����ٶ�ƫ��
	Encoder*=0.7;
	Encoder+=Encoder_Least*0.3;//���е�ͨ�˲� 0.3 0.7�ɾ���ã�Ŀ�ļ�Ц�ٶȶ�ֱ����Ӱ��
	Encoder_Integral+=Encoder;
	Encoder_Integral=Encoder_Integral-sudu;
  if(Encoder_Integral> 10000)  	
	Encoder_Integral= 10000;               //===�����޷�
  if(Encoder_Integral< -10000)	
		Encoder_Integral = -10000;  

	//===�����޷�	
	Velocity=Encoder*kp+Encoder_Integral*ki;
	
	//  Encoder_Integral=0;
	
	
	return Velocity;
}


int Balance(float Angle,float Gyro)
{                                                                         
	
	float Bias,kp=220,kd=8.5;	                                               //kp  245�������ػζ� 8
	int balance;   

	                                //240 15
	 Bias = Angle-0;  	//103.68  6.48
   
	balance=(int)(kp* Bias+Gyro*kd);                //155.636  
	return balance;                                //
}	                                                //    
    






int myabs(int a)
{
	int temp;
	if(a < 0)
		temp = -a;
	else
		temp = a;
	
	return temp;
}


void Xianfu_PWM(void)
{	
	  int Amplitude=6500;    //===PWM������7200 ������6900
    if(Motor_Left<-Amplitude) Motor_Left=-Amplitude;	
		if(Motor_Left>Amplitude)  Motor_Left=Amplitude;	
	  if(Motor_Right<-Amplitude) Motor_Right=-Amplitude;	
		if(Motor_Right>Amplitude)  Motor_Right=Amplitude;		
}
		

	
int Stop(float Angle)
{ u8 temp;
	if(Angle>30|| Angle< -30)
	
	{ 
     
      PAout(15)=0; 
	  	PAout(8)=0   ;//A����STBY�͵�ƽ������ر�
	    PAout(11)=0;
		Right_Stop();
		Left_Stop();
	   temp=1;}
    else
		temp=0;
	  return temp;
	
}
















void Angle_Calculate()
{ 
  
	  
    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
	  MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������   
	
    aacy=aacy-120;
	  ay_angle=(float)aacy/16384; //ȥ�����û���
	
   ay_angle=ay_angle*1.2*180/3.14; //����Ƕ�

	      Gyro=(gyrox+5)/16.4; 
	   
      	gyroz=(gyroz+5)/16.4; 
	
	
	Kalman_Filter(ay_angle,Gyro);
   // A=(short)ay_angle;            //����λ����������
    //B=(short)Angle;
   //C=(short)Gyro;
  // mpu6050_send_data(A,B,C);
	  
}






void Speed_Calculate(void)
{ Encoder_Right=TIM_GetCounter(TIM2);//�õ���������ֵ  
	
	Encoder_Right=-(Encoder_Right-15000)/4;
  //printf("\r\n�ҵ�� :%d \r\n",Encoder_Right);	  
	
	
	Encoder_Left=TIM_GetCounter(TIM3);
	Encoder_Left=(Encoder_Left-15000)/4;
	//printf("\r\n���� :%d \r\n",Encoder_Left);
	
	
	TIM_SetCounter(TIM2,15000);           //������ֵ��0
	TIM_SetCounter(TIM3,15000);

} 	
void PWM_Calculate()
{  
  	BalancePWM=Balance(Angle,Gyro_x);
	  VelocityPWM=(int)Velocity(Encoder_Left,Encoder_Right);
    TurnPWM=Turn(Encoder_Left,Encoder_Right,gyroz);
    Motor_Left=BalancePWM + VelocityPWM+ TurnPWM;           //BalancePWM + VelocityPWM+ TurnPWM;
	 // printf("\r\n���� :%d \r\n",Encoder_Left);
		Motor_Right=BalancePWM+ VelocityPWM- TurnPWM;      // BalancePWM+ VelocityPWM- TurnPWM;
	 // printf("\r\n�ҵ�� :%d \r\n",Encoder_Right);	 
	
}	




 
void Motor_Control()
{ 
		
		
      Xianfu_PWM();
 
   if(Stop(Angle) == 0)                            //===����������������
	Set_PWM(Motor_Left, Motor_Right);	
 
	 // printf("\r\n Motor_Left %d \r\n",  Motor_Left);	
		//printf("\r\n Motor_Right %d \r\n",  Motor_Right);
	//printf("\r\n ................................. \r\n");
	
}	

void  Set_PWM(int Motor_Left, int Motor_Right)
{
	if(Motor_Left<=0)         
	{	
		Left_Back(); 									
  }          
	else
	{	
    Left_Go();									
	}            
	
	TIM_SetCompare4(TIM1,myabs(Motor_Left));       //�ı�ͨ��4��ռ�ձ�

	if(Motor_Right<=0)         
	{
		Right_Back(); }  
	else
	{Right_Go()	;	}			
	            
		
	TIM_SetCompare1(TIM1,myabs(Motor_Right));	     //�ı�ͨ��1��ռ�ձ�
 
}







/*****************�������˲�**************************************************/
void Kalman_Filter(float Accel,float Gyro)		
{  

float Q_angle=0.01;                        // Q��R�����˶�Ԥ�����ݵ����ζȣ�QԽ����Խ���Ų���ֵ��RԽ����Խ����Ԥ��ֵ��
float Q_gyro=0.8;//0.08
float R_angle=15;                       //���˶��R  ������Ϊ0.5  ���ֱ�ӵ���15   �˲���ƽ��  
const float dt=0.01;	                  //dtΪkalman�˲�������ʱ��;
const char  C_0 = 1;
float  Q_bias=0, Angle_err=0;
float  PCt_0=0, PCt_1=0, E=0;
float  K_0=0, K_1=0, t_0=0, t_1=0;
float  Pdot[4] ={0,0,0,0};
float  PP[2][2] = { { 1, 0 },{ 0, 1 } };
	
	
 Angle+=(Gyro - Q_bias) * dt; //�ɴ����ǵõ��˵�ǰ�Ƕȵ�Ԥ��ֵ Angle
	
	Pdot[0]=Q_angle - PP[0][1] - PP[1][0]; // Pk-����������Э�����΢��

	Pdot[1]= -PP[1][1];
	Pdot[2]= -PP[1][1];
	Pdot[3]=Q_gyro;
	
	PP[0][0] += Pdot[0] * dt;   // Pk-����������Э����΢�ֵĻ���
	PP[0][1] += Pdot[1] * dt;   // =����������Э����
	PP[1][0] += Pdot[2] * dt;
	PP[1][1] += Pdot[3] * dt;
		
	Angle_err = Accel - Angle;	//zk-�������
	
	PCt_0 = C_0 * PP[0][0];
	PCt_1 = C_0 * PP[1][0];
	
	E = R_angle + C_0 * PCt_0;
	
	K_0 = PCt_0 / E;
	K_1 = PCt_1 / E;
	
	t_0 = PCt_0;
	t_1 = C_0 * PP[0][1];

	PP[0][0] -= K_0 * t_0;		 //����������Э����
	PP[0][1] -= K_0 * t_1;
	PP[1][0] -= K_1 * t_0;
	PP[1][1] -= K_1 * t_1;
		
	Angle	+= K_0 * Angle_err;	 //�������
	Q_bias	+= K_1 * Angle_err;	 //�������
	Gyro_x= Gyro - Q_bias;	 //���ֵ(�������)��΢��=���ٶ�*/
}   




void Disable_Jtag()
{   GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);  
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);// �ı�ָ���ܽŵ�ӳ�� GPIO_Remap_SWJ_JTAGDisable ��JTAG-DP ���� + SW-DP ʹ��


GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_Init(GPIOA, &GPIO_InitStructure); 




}	
	
void   Blue_tooth()

{  
       
	   
		if(USART1_RX_STA&0X8000)			//���յ�һ��������
		{
		
 			reclen=USART1_RX_STA&0X7FFF;	//�õ����ݳ���
		  	USART1_RX_BUF[reclen]=0;	 	//���������
		
					 
       i=USART1_RX_BUF[0];
	
			
			if(i==48) { sudu=0;zhuanxiang=0;};
			if(i==49)  {sudu=-18;};
			if(i==50) { sudu=18;};
			if(i==51)  {zhuanxiang=-800;};	
			if(i==52)  {zhuanxiang=800;};	
			
			
			//u3_printf("ALIENTEK HC05 %d\r\n",USART1_RX_BUF[0]);	
			     // else sudu=0;
				USART1_RX_STA=0;	 
		}	 	



	}
void control(void)
{
	
		  Blue_tooth();
		
	   	Angle_Calculate();
	
		 Speed_Calculate();
		 PWM_Calculate();
     Motor_Control();
 }    



