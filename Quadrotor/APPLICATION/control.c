#include "control.h"


u16 motor[4];
//vs16 throttle=300;
u8 flag;

PID PID_Pitch_Angle,PID_Roll_Angle,PID_Yaw_Angle;	//外环：角度PID环
PID PID_Pitch_Rate,PID_Roll_Rate,PID_Yaw_Rate;		//内环：角速度PID环

s16 OUT_X,OUT_Y,OUT_Z,OUT_H;

PID PID_Height;                     //外环：高度PID环
PID PID_Acc_z_after_offset;            //内环；Z轴加速度PID环



void PID_Init_OUT_P(float Pitch_Angle_P,float Roll_Angle_P,float Yaw_Angle_P)
{
	
	PID_Pitch_Angle.P =Pitch_Angle_P;
	PID_Roll_Angle.P =Roll_Angle_P;
  PID_Yaw_Angle.P =Yaw_Angle_P;

}


void PID_Init_OUT_I(float Pitch_Angle_I,float Roll_Angle_I,float Yaw_Angle_I)
{

	PID_Pitch_Angle.I = Pitch_Angle_I;
	PID_Roll_Angle.I = Roll_Angle_I;
	PID_Yaw_Angle.I = Yaw_Angle_I;

}


void PID_Init_OUT_D(float Pitch_Angle_D,float Roll_Angle_D,float Yaw_Angle_D)
{

	PID_Pitch_Angle.D = Pitch_Angle_D;
	PID_Roll_Angle.D = Roll_Angle_D;
	PID_Yaw_Angle.D = Yaw_Angle_D;

}


void PID_Init_IN_P(float Pitch_Rate_P,float Roll_Rate_P,float Yaw_Rate_P)
{

	PID_Pitch_Rate.P = Pitch_Rate_P;
	PID_Roll_Rate.P = Roll_Rate_P;
	PID_Yaw_Rate.P = Yaw_Rate_P;

}


void PID_Init_IN_I(float Pitch_Rate_I,float Roll_Rate_I,float Yaw_Rate_I)
{

	PID_Pitch_Rate.I = Pitch_Rate_I;
	PID_Roll_Rate.I = Roll_Rate_I;
	PID_Yaw_Rate.I = Yaw_Rate_I;

}


void PID_Init_IN_D(float Pitch_Rate_D,float Roll_Rate_D,float Yaw_Rate_D)
{

	PID_Pitch_Rate.D = Pitch_Rate_D;
	PID_Roll_Rate.D = Roll_Rate_D;
	PID_Yaw_Rate.D = Yaw_Rate_D;

}


void H_PID_Init_OUT_P(float PID_Height_P)
{
	PID_Height.P=PID_Height_P;
}
void H_PID_Init_OUT_I(float PID_Height_I)
{
	PID_Height.I=PID_Height_I;
}
void H_PID_Init_OUT_D(float PID_Height_D)
{
	PID_Height.D=PID_Height_D;
}
void Z_PID_Init_IN_P(float PID_Acc_z_after_offset_P)
{
	PID_Acc_z_after_offset.P=PID_Acc_z_after_offset_P;
}
void Z_PID_Init_IN_I(float PID_Acc_z_after_offset_I)
{
	PID_Acc_z_after_offset.I=PID_Acc_z_after_offset_I;
}
void Z_PID_Init_IN_D(float PID_Acc_z_after_offset_D)
{
	PID_Acc_z_after_offset.D=PID_Acc_z_after_offset_D;
}



volatile float angle_z;

void Control_gesture(S_FLOAT_XYZ	Now_Angle, S_FLOAT_XYZ Exp_Angle)
{
	

  float err_ox,err_oy,err_oz;                        //定义外环差值
	
	
	float err_ix,err_iy,err_iz;                 //  定义内环差值  


	
	float err_last_x_out,err_last_y_out,err_last_z_out;                   //定义外环上一次偏差值
	float err_last_x_in,err_last_y_in,err_last_z_in;        //  定义内环上一次偏差值 

//内外环积分
	static float xi_out,yi_out,zi_out;
	static float xi_in,yi_in,zi_in;

//设置积分分离标志位
	char inde_x_out=1,inde_y_out=1,inde_z_out=1;
	char inde_x_in=1,inde_y_in=1,inde_z_in=1;
	
	
	
	
	
	//外环控制
	//位置型PID,梯形积分 
	err_ox=(Exp_Angle.X-Now_Angle.X);  //计算外环误差,500待定
	
	if(fabs(err_ox)>25)//>25
	{inde_x_out=0;} 
	else inde_x_out=1;     //积分分离 ，防止误差过大
	
	xi_out+=(err_ox+err_last_x_out)/2; 
	if(xi_out>20) {xi_out=20;}   if(xi_out<-20) {xi_out=-20;}    //积分限幅
	
	PID_Pitch_Angle.Pout=PID_Pitch_Angle.P*err_ox;
	PID_Pitch_Angle.Dout=PID_Pitch_Angle.D*(err_ox-err_last_x_out);
	PID_Pitch_Angle.Iout=PID_Pitch_Angle.I*inde_x_out*xi_out;
	
	PID_Pitch_Angle.Out=PID_Pitch_Angle.Pout+PID_Pitch_Angle.Dout+PID_Pitch_Angle.Iout;printf("\r\nPITCHout:%f \r\n",PID_Pitch_Angle.Out);

	err_last_x_out=err_ox;
	
	
	
	err_oy=(Exp_Angle.Y-Now_Angle.Y);

	if(fabs(err_oy)>25)
	{inde_y_out=0;} 
	else inde_y_out=1; 
	
	yi_out+=(err_oy+err_last_y_out)/2; 
	if(yi_out>20) {yi_out=20;}   if(yi_out<-20) {yi_out=-20;}
	
	PID_Roll_Angle.Pout=PID_Roll_Angle.P*err_oy;
	PID_Roll_Angle.Dout=PID_Roll_Angle.D*(err_oy-err_last_y_out);
	PID_Roll_Angle.Iout=PID_Roll_Angle.I*inde_y_out*yi_out;
	
	PID_Roll_Angle.Out=PID_Roll_Angle.Pout+PID_Roll_Angle.Dout+PID_Roll_Angle.Iout;
	
	err_last_y_out=err_oy;
	
	
	
	err_oz=(Exp_Angle.Z-angle_z);

	if(fabs(err_oz)>25)
	{inde_z_out=0;} 
	else inde_z_out=1; 
	
	zi_out+=(err_oz+err_last_z_out)/2; 
	if(zi_out>20) {zi_out=20;}   if(zi_out<-20) {zi_out=-20;}
	
	PID_Yaw_Angle.Pout=PID_Yaw_Angle.P*err_oz;
	PID_Yaw_Angle.Dout=PID_Yaw_Angle.D*(err_oz-err_last_z_out);
	PID_Yaw_Angle.Iout=PID_Yaw_Angle.I*inde_z_out*zi_out;
	
	PID_Yaw_Angle.Out=PID_Yaw_Angle.Pout+PID_Yaw_Angle.Dout+PID_Yaw_Angle.Iout;
	
	err_last_z_out=err_oz;
	
	
	
	
	//内环控制
	err_ix=PID_Pitch_Angle.Out-Gyro_Offset_angle_speed.X;  
	
	if(fabs(err_ix)>25)
	{inde_x_in=0;} 
	else inde_x_in=1; 
	
	xi_in+=(err_ix+err_last_x_in)/2;
	if(xi_in>30) {xi_in=30;} if(xi_in<-30) {xi_in=-30;} 
	
	PID_Pitch_Rate.Pout=PID_Pitch_Rate.P*err_ix;
	PID_Pitch_Rate.Dout=PID_Pitch_Rate.D*(err_ix-err_last_x_in);
	PID_Pitch_Rate.Iout=PID_Pitch_Rate.I*inde_x_in*xi_in;
	
	PID_Pitch_Rate.Out=PID_Pitch_Rate.Pout+PID_Pitch_Rate.Dout+PID_Pitch_Rate.Iout;
	
	err_last_x_in=err_ix;
	
	
	
	err_iy=PID_Roll_Angle.Out-Gyro_Offset_angle_speed.Y; 
	
	if(fabs(err_iy)>25)
	{inde_y_in=0;} 
	else inde_y_in=1; 
	
	yi_in+=(err_iy+err_last_y_in)/2;
	if(yi_in>30) {yi_in=30;} if(yi_in<-30) {yi_in=-30;} 
	
	PID_Roll_Rate.Pout=PID_Roll_Rate.P*err_iy;
	PID_Roll_Rate.Dout=PID_Roll_Rate.D*(err_iy-err_last_y_in);
	PID_Roll_Rate.Iout=PID_Roll_Rate.I*inde_y_in*yi_in;
	
	PID_Roll_Rate.Out=PID_Roll_Rate.Pout+PID_Roll_Rate.Dout+PID_Roll_Rate.Iout;
	
	err_last_y_in=err_iy;
	
	
	
	err_iz=PID_Yaw_Angle.Out-Gyro_Offset_angle_speed.Z; 
	
	if(fabs(err_iz)>25)
	{inde_z_in=0;} 
	else inde_z_in=1; 
	
	zi_in+=(err_iz+err_last_z_in)/2;
	if(zi_in>30) {zi_in=30;} if(zi_in<-30) {zi_in=-30;} 
	
	PID_Yaw_Rate.Pout=PID_Yaw_Rate.P*err_iz;
	PID_Yaw_Rate.Dout=PID_Yaw_Rate.D*(err_iz-err_last_z_in);
	PID_Yaw_Rate.Iout=PID_Yaw_Rate.I*inde_z_in*zi_in;
	
	PID_Yaw_Rate.Out=PID_Yaw_Rate.Pout+PID_Yaw_Rate.Dout+PID_Yaw_Rate.Iout;
	
	err_last_z_in=err_iz;
	
	
	OUT_X=(s16)PID_Roll_Rate.Out;
	  if(OUT_X>200) OUT_X=200;
    if(OUT_X<-200) OUT_X=-200;
	OUT_Y=(s16)PID_Pitch_Rate.Out;printf("\r\n%f \r\n",PID_Pitch_Rate.Out);printf("\r\n%d \r\n",OUT_Y);//必须printf			硬件bug
		if(OUT_Y>200) OUT_Y=200;
    if(OUT_Y<-200) OUT_Y=-200;
	OUT_Z=(s16)PID_Yaw_Rate.Out;
		if(OUT_Z>200) OUT_Z=200;
    if(OUT_Z<-200) OUT_Z=-200;
	
//	 printf("\r\nOUTX:%f \r\n",(float)OUT_X);
//	 printf("\r\nOUTY:%f \r\n",(float)OUT_Y);
//	 printf("\r\nOUTZ:%f \r\n",(float)OUT_Z);
	
}


volatile float Tar_Height;


void Control_height(float	Now_Height, float Exp_Height)
{
	float err_oH;                        //定义外环差值
	float err_iZ;                 //  定义内环差值                            
	float err_last_H_out;                   //定义外环上一次偏差值
	float err_last_Z_in;        //  定义内环上一次偏差值 

//内外环积分
	static float Hi_out;
	static float Zi_in;

//设置积分分离标志位
	char inde_H_out=1;
	char inde_Z_in=1;
	
	
	//外环
	
	
	err_oH=(Exp_Height-Now_Height)/500;

	if(fabs(err_oH)>0.004)
	{inde_H_out=0;} 
	else inde_H_out=1; 
	
	Hi_out+=(err_oH+err_last_H_out)/2; 
	if(Hi_out>2) {Hi_out=2;}   if(Hi_out<-2) {Hi_out=-2;}
	
	PID_Height.Pout=PID_Height.P*err_oH;
	PID_Height.Dout=PID_Height.D*(err_oH-err_last_H_out);
	PID_Height.Iout=PID_Height.I*inde_H_out*Hi_out;
	
	PID_Height.Out=PID_Height.Pout+PID_Height.Dout+PID_Height.Iout;
	
	err_last_H_out=err_oH;
	
	//内环
	
	err_iZ=PID_Height.Out-(Acc_date_after_Offset.Z/8192-1); 
	
	if(fabs(err_iZ)>0.5)
	{inde_Z_in=0;} 
	else inde_Z_in=1; 
	
	Zi_in+=(err_iZ+err_last_Z_in)/2;
	if(Zi_in>50) {Zi_in=50;} if(Zi_in<-50) {Zi_in=-50;} 
	
	PID_Acc_z_after_offset.Pout=PID_Acc_z_after_offset.P*err_iZ;
	PID_Acc_z_after_offset.Dout=PID_Acc_z_after_offset.D*(err_iZ-err_last_Z_in);
	PID_Acc_z_after_offset.Iout=PID_Acc_z_after_offset.I*inde_Z_in*Zi_in;
	
	PID_Acc_z_after_offset.Out=PID_Acc_z_after_offset.Pout+PID_Acc_z_after_offset.Dout+PID_Acc_z_after_offset.Iout;
	
	err_last_Z_in=err_iZ;
	
	
	
	OUT_H=(s16)PID_Acc_z_after_offset.Out;
	
	if(OUT_H>20)OUT_H=20;
	if(OUT_H<-20)OUT_H=-20;

}
       

volatile S_FLOAT_XYZ Tar_Angle={0,0,0};

void GET_pwm_out_value(void)
{
	//float H;
	//H=Get_High();
	Control_gesture(Angle,Tar_Angle);
	//if(flag==1)Control_height(H,Tar_Height);
	
	
		motor[0] =  up_down_throttle + OUT_Y + OUT_Z;printf("\r\nmotor[0]%d \r\n",motor[0]);     //+  OUT_H;   
		motor[1] =  up_down_throttle - OUT_X - OUT_Z;//+  OUT_H;
		motor[2] =  up_down_throttle - OUT_Y + OUT_Z;printf("\r\nmotor[2]%d \r\n",motor[2]);     //+  OUT_H;
		motor[3] =  up_down_throttle + OUT_X - OUT_Z;//+  OUT_H;
//			  printf("\r\nmotor[0]:%d \r\n",motor[0]);
//				printf("\r\nmotor[1]:%d \r\n",motor[1]);
//				printf("\r\nmotor[2]:%d \r\n",motor[2]);
//		    printf("\r\nmotor[3]:%d \r\n",motor[3]);
	

		
	Motor_PWM_Update(motor[0],motor[1],motor[2],motor[3]);
}









