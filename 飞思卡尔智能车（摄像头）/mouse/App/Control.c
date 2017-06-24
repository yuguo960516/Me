            #include "common.h"
            #include "include.h"
            #include  "pid.h" 
 extern int speed_in,speed_out,speed,speed_ref;
 extern int speed_adjust;
 extern int angle,angle_old,angle_out;
 extern uint8 check_start;
 extern uint8 check_stop;
 extern char cross,stop;
 extern uint8 mode,safe;
 extern int8 road_flag;

//   extern                 float  Ref;   		// Input: Reference input 标准输入
//   extern                 float  Fdb;   		// Input: Feedback input  反馈输入
//   extern                 float  Err;			// Variable: Error        误差
//   extern                 float  Kp;			// Parameter: Proportional gain 比例
   extern int kp,ki,kd;
//   extern                 float  Up;			// Variable: Proportional output 比例输出
//   extern                 float  Ui;			// Variable: Integral output     积分输出
//   extern                 float  Ud;		        // Variable: Derivative output 	导数-输出 
//   extern                 float  OutPreSat; 		// Variable: Pre-saturated output
//   extern                 float  OutMax;		// Parameter: Maximum output    最大限幅输出
//   extern                 float  OutMin;	    	// Parameter: Minimum output    最小限幅输出
//   extern                 float  Out;   		// Output: PID output           PID最终输出
//   extern                 float  SatErr;		// Variable: Saturated difference 饱和差
//   extern                 float  Ki;		        // Parameter: Integral gain       积分系数
//   extern                 float  Ki_leave;           // 分离积分           
//   extern                 float  Kc;		     	// Parameter: Integral correction gain 积分校正
//   extern                 float  Kd; 		        // Parameter: Derivative gain          微分增益
//   extern                 float  Up_old;		        // History: Previous proportional output以前的成比例的输出

//   extern                 float p1,p2;
   extern                 int speed_min,speed_max;
   extern                 int count;
   
   int8 k1=10,k2=20,k3=100,k4=40,k5=0;  
   int ang_adj=0; 
     

 void run(int V,int T)     //控制
{
  

  /**********电机控制************/
  
  if(V>=0)
  {
  tpm_pwm_duty(TPM1,TPM_CH0,0);
  tpm_pwm_duty(TPM1,TPM_CH1,V);
  }
  else
  { 
  tpm_pwm_duty(TPM1,TPM_CH0,-V);
  tpm_pwm_duty(TPM1,TPM_CH1,0);  
  }    
  
  /************舵机控制************/
  
  tpm_pwm_duty(TPM0,TPM_CH0,15100+T);
  
} 

     /**********   计算  矫正  *************/
void computer()
{
  speed_in=12*count; 
  
   road_flag=check_road_flag(); 
if(road_flag)
{   
  if(road_flag==1 && stop==0)                                       //
  {  
  if(speed<2700) speed+=30;    
  else speed=2700;                                                      //
//angle=-100*(check_medium(1,CAMERA_H/3-1,CAMERA_H/3+1)-CAMERA_W/2+1);
angle=   -0*(check_medium(safe,5,9)-CAMERA_W/2+1) 
        -60*(check_medium(safe,10,16)-CAMERA_W/2+1)
         -0*(check_medium(safe,17,25)-CAMERA_W/2+1)
           -0*(check_medium(safe,26,36)-CAMERA_W/2+1)
             -0*(check_medium(safe,37,49)-CAMERA_W/2+1);  
  }
  
  if(road_flag==2)
  {
    speed=1700;                                                     //    
angle=   k1*(check_medium(safe,5,9)-CAMERA_W/2+1)
        -k2*(check_medium(safe,10,16)-CAMERA_W/2+1)
         -k3*(check_medium(safe,17,25)-CAMERA_W/2+1)
           -k4*(check_medium(safe,26,36)-CAMERA_W/2+1);
            // -k5*(check_medium(safe,37,49)-CAMERA_W/2+1);          
  }
  if(road_flag==3) 
  {
    speed=1700;                                                        //
angle=   k1*(check_medium(safe,5,9)-CAMERA_W/2+1)
          -k2*(check_medium(safe,10,16)-CAMERA_W/2+1)
           -k3*(check_medium(safe,17,25)-CAMERA_W/2+1)
            -k4*(check_medium(safe,26,36)-CAMERA_W/2+1);
           //  -k5*(check_medium(safe,37,49)-CAMERA_W/2+1);          
  }     
    
} 
else
{
  if(stop==0  && 1 )    
  {  
speed=1900;                                                           //
angle=-0*(check_medium(safe,46,49)-CAMERA_W/2+1)         
    -50*(check_medium(safe,26,28)-CAMERA_W/2+1) 
    -70*(check_medium(safe,8,10)-CAMERA_W/2+1);          
  }
   else  
   {
speed=1600;                                                           //
       
angle=   -k1*(check_medium(safe,5,9)-CAMERA_W/2+1)
        -k2*(check_medium(safe,10,16)-CAMERA_W/2+1)
         -k3*(check_medium(safe,17,25)-CAMERA_W/2+1)
           -k4*(check_medium(safe,26,36)-CAMERA_W/2+1)
             -k5*(check_medium(safe,37,49)-CAMERA_W/2+1);   
   }
} 
 
//if(angle>2600)  angle=2600;         
//if(angle<-2600) angle=-2600;        

//speed_ref=speed+speed_adjust+(1300-abs(angle))/13;
speed_ref=speed+speed_adjust;//-abs(angle)/26;         
//speed_ref=1500+speed_adjust;   

if(safe!=3)                                                    //速度输出
speed_out=pid(kp,ki,kd,speed_ref,speed_in,-9000,9000);   
else 
{
  if(count>=200)
    speed_out=-8000; 
  else
speed_out=-40*count; 
        led_turn(LED3);                     //LED1翻转
          if(key_check(KEY6)==0)   
            safe=1; 
}

angle_out=angle+6*(angle-angle_old); 

angle_old=angle;  

// **********************************************
if(angle_out>2600)  angle_out=2600;
if(angle_out<-2600) angle_out=-2600; 

}