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
short aacx,aacy,aacz;		//加速度传感器原始数据
float ay_angle;//	去除零点飘漂移后的倾角
short gyrox,gyroy,gyroz;	//陀螺仪原始数据
static float Angle;//车最终角度
float Gyro;
float Gyro_x;//最终角速度
float Gyro_y;
int BalancePWM, VelocityPWM, TurnPWM;
int Encoder_Left,Encoder_Right;
short A,B,C;

//**************蓝牙***********/		
int sudu;
int zhuanxiang;




//******卡尔曼参数************


float PWM;           //综合PWM计算
float speed_r_l;	//电机转速
float speed;      //电机转速滤波
int Motor_Right;
int Motor_Left;
                          //Motor_left motor1   
													
													

/******************匿名上位机***************************************/	

/*    void usart1_send_char(u8 c)
{   	
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); //循环发送,直到发送完毕   
	USART_SendData(USART1,c);  
} 
//传送数据给匿名四轴上位机软件(V2.6版本)
//fun:功能字. 0XA0~0XAF
//data:数据缓存区,最多28字节!!
//len:data区有效数据个数
void usart1_niming_report(u8 fun,u8*data,u8 len)
{
	u8 send_buf[32];
	u8 i;
	if(len>28)return;	//最多28字节数据 
	send_buf[len+3]=0;	//校验数置零
	send_buf[0]=0X88;	//帧头
	send_buf[1]=fun;	//功能字
	send_buf[2]=len;	//数据长度
	for(i=0;i<len;i++)send_buf[3+i]=data[i];			//复制数据
	for(i=0;i<len+3;i++)send_buf[len+3]+=send_buf[i];	//计算校验和	
	for(i=0;i<len+4;i++)usart1_send_char(send_buf[i]);	//发送数据到串口1 
}
//发送加速度传感器数据和陀螺仪数据
//aacx,aacy,aacz:x,y,z三个方向上面的加速度值
//gyrox,gyroy,gyroz:x,y,z三个方向上面的陀螺仪值
void mpu6050_send_data(short ay_angle,short Angle,short Gyro)
{  u8 tbuf[6]; 
	
	
	tbuf[0]=(ay_angle>>8)&0XFF;
	tbuf[1]=ay_angle&0XFF;
	tbuf[2]=(Angle>>8)&0XFF;
	tbuf[3]=Angle&0XFF;
	tbuf[4]=(Gyro>>8)&0XFF;
	tbuf[5]=Gyro&0XFF;
	
		usart1_niming_report(0XA1,tbuf,12);//自定义帧,0XA1
	}
/******************上位机***************************************/	
	


	
	
	
/********************蓝牙定时器******判断一次字符是否传输完毕****************/	
	
	
	
void TIM4_Int_Init(u16 arr,u16 psc)
{	
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//TIM7时钟使能    
	 
	//定时器TIM7初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); //使能指定的TIM7中断,允许更新中断
	
	TIM_Cmd(TIM4,ENABLE);//开启定时器7
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//子优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
}
	 
	


extern vu16 USART1_RX_STA;

//定时器4中断服务程序		    
void TIM4_IRQHandler(void)
{ 	
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)//是更新中断
	{	 		
		USART1_RX_STA|=1<<15;	//标记接收完成
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update  );  //清除TIM7更新中断标志    
		TIM_Cmd(TIM4, DISABLE);  //关闭TIM4 
		
	}	    
}
 













	
	
	
	
/*************************PWM计算**********************/	
	
  //范围为2g时，换算关系：16384 LSB/g
 //角度较小时，x=sinx得到角度（弧度）, deg = rad*180/3.14
//  因为x>=sinx,故乘以1.3适当放大
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

	Encoder_Least=(Encoder_Left+Encoder_Right)-0;//计算速度偏差
	Encoder*=0.7;
	Encoder+=Encoder_Least*0.3;//进行低通滤波 0.3 0.7由经验得，目的见笑速度对直立的影响
	Encoder_Integral+=Encoder;
	Encoder_Integral=Encoder_Integral-sudu;
  if(Encoder_Integral> 10000)  	
	Encoder_Integral= 10000;               //===积分限幅
  if(Encoder_Integral< -10000)	
		Encoder_Integral = -10000;  

	//===积分限幅	
	Velocity=Encoder*kp+Encoder_Integral*ki;
	
	//  Encoder_Integral=0;
	
	
	return Velocity;
}


int Balance(float Angle,float Gyro)
{                                                                         
	
	float Bias,kp=220,kd=8.5;	                                               //kp  245以上来回晃动 8
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
	  int Amplitude=6500;    //===PWM满幅是7200 限制在6900
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
	  	PAout(8)=0   ;//A控制STBY低电平电机都关闭
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
  
	  
    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
	  MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据   
	
    aacy=aacy-120;
	  ay_angle=(float)aacy/16384; //去除零点得弧度
	
   ay_angle=ay_angle*1.2*180/3.14; //换算角度

	      Gyro=(gyrox+5)/16.4; 
	   
      	gyroz=(gyroz+5)/16.4; 
	
	
	Kalman_Filter(ay_angle,Gyro);
   // A=(short)ay_angle;            //向上位机传送数据
    //B=(short)Angle;
   //C=(short)Gyro;
  // mpu6050_send_data(A,B,C);
	  
}






void Speed_Calculate(void)
{ Encoder_Right=TIM_GetCounter(TIM2);//得到编码器的值  
	
	Encoder_Right=-(Encoder_Right-15000)/4;
  //printf("\r\n右电机 :%d \r\n",Encoder_Right);	  
	
	
	Encoder_Left=TIM_GetCounter(TIM3);
	Encoder_Left=(Encoder_Left-15000)/4;
	//printf("\r\n左电机 :%d \r\n",Encoder_Left);
	
	
	TIM_SetCounter(TIM2,15000);           //编码器值置0
	TIM_SetCounter(TIM3,15000);

} 	
void PWM_Calculate()
{  
  	BalancePWM=Balance(Angle,Gyro_x);
	  VelocityPWM=(int)Velocity(Encoder_Left,Encoder_Right);
    TurnPWM=Turn(Encoder_Left,Encoder_Right,gyroz);
    Motor_Left=BalancePWM + VelocityPWM+ TurnPWM;           //BalancePWM + VelocityPWM+ TurnPWM;
	 // printf("\r\n左电机 :%d \r\n",Encoder_Left);
		Motor_Right=BalancePWM+ VelocityPWM- TurnPWM;      // BalancePWM+ VelocityPWM- TurnPWM;
	 // printf("\r\n右电机 :%d \r\n",Encoder_Right);	 
	
}	




 
void Motor_Control()
{ 
		
		
      Xianfu_PWM();
 
   if(Stop(Angle) == 0)                            //===情况正常就启动电机
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
	
	TIM_SetCompare4(TIM1,myabs(Motor_Left));       //改变通道4的占空比

	if(Motor_Right<=0)         
	{
		Right_Back(); }  
	else
	{Right_Go()	;	}			
	            
		
	TIM_SetCompare1(TIM1,myabs(Motor_Right));	     //改变通道1的占空比
 
}







/*****************卡尔曼滤波**************************************************/
void Kalman_Filter(float Accel,float Gyro)		
{  

float Q_angle=0.01;                        // Q和R代表了对预测数据的信任度，Q越大则越相信测量值，R越大则越相信预测值，
float Q_gyro=0.8;//0.08
float R_angle=15;                       //看了多份R  基本都为0.5  这个直接调成15   滤波很平滑  
const float dt=0.01;	                  //dt为kalman滤波器采样时间;
const char  C_0 = 1;
float  Q_bias=0, Angle_err=0;
float  PCt_0=0, PCt_1=0, E=0;
float  K_0=0, K_1=0, t_0=0, t_1=0;
float  Pdot[4] ={0,0,0,0};
float  PP[2][2] = { { 1, 0 },{ 0, 1 } };
	
	
 Angle+=(Gyro - Q_bias) * dt; //由此我们得到了当前角度的预测值 Angle
	
	Pdot[0]=Q_angle - PP[0][1] - PP[1][0]; // Pk-先验估计误差协方差的微分

	Pdot[1]= -PP[1][1];
	Pdot[2]= -PP[1][1];
	Pdot[3]=Q_gyro;
	
	PP[0][0] += Pdot[0] * dt;   // Pk-先验估计误差协方差微分的积分
	PP[0][1] += Pdot[1] * dt;   // =先验估计误差协方差
	PP[1][0] += Pdot[2] * dt;
	PP[1][1] += Pdot[3] * dt;
		
	Angle_err = Accel - Angle;	//zk-先验估计
	
	PCt_0 = C_0 * PP[0][0];
	PCt_1 = C_0 * PP[1][0];
	
	E = R_angle + C_0 * PCt_0;
	
	K_0 = PCt_0 / E;
	K_1 = PCt_1 / E;
	
	t_0 = PCt_0;
	t_1 = C_0 * PP[0][1];

	PP[0][0] -= K_0 * t_0;		 //后验估计误差协方差
	PP[0][1] -= K_0 * t_1;
	PP[1][0] -= K_1 * t_0;
	PP[1][1] -= K_1 * t_1;
		
	Angle	+= K_0 * Angle_err;	 //后验估计
	Q_bias	+= K_1 * Angle_err;	 //后验估计
	Gyro_x= Gyro - Q_bias;	 //输出值(后验估计)的微分=角速度*/
}   




void Disable_Jtag()
{   GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);  
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);// 改变指定管脚的映射 GPIO_Remap_SWJ_JTAGDisable ，JTAG-DP 禁用 + SW-DP 使能


GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_Init(GPIOA, &GPIO_InitStructure); 




}	
	
void   Blue_tooth()

{  
       
	   
		if(USART1_RX_STA&0X8000)			//接收到一次数据了
		{
		
 			reclen=USART1_RX_STA&0X7FFF;	//得到数据长度
		  	USART1_RX_BUF[reclen]=0;	 	//加入结束符
		
					 
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



