#include "ALG.h"
#include "delay.h"
#include "control.h"

float q0,q1,q2,q3;

float A,B,C,D;

float magOffset[3];

 S_INT16_XYZ MPU6050_Acc;
 S_INT16_XYZ MPU6050_Gyro;
 S_INT16_XYZ HMC5883_Geo;
 S_INT16_XYZ	Acc_Offset;
 S_INT16_XYZ	Gyro_Offset;
 S_INT16_XYZ	Geo_Offset;
 S_INT16_XYZ	Acc_date_after_Offset;
 S_INT16_XYZ	Gyro_date_after_Offset;
 S_INT16_XYZ	Geo_date_after_Offset;

 float prepre;

//volatile S_FLOAT_XYZ Acc_Angle;    //加速度计计算出的角度
volatile S_INT16_XYZ Acc_Avg;			 //滑动滤波后加速度计值
volatile S_INT16_XYZ Geo_Avg;	
volatile S_INT16_XYZ Acc_Buf[FILTER_WINDOW];
volatile S_INT16_XYZ Geo_Buf[FILTER_WINDOW];

void ALG_Date_Init(void)
{
	int cnt;
	
	for(cnt	=	0;cnt	<	FILTER_WINDOW;cnt++)
	{
		Acc_Buf[cnt].X = 0;
		Acc_Buf[cnt].Y = 0;
		Acc_Buf[cnt].Z = 0;
		Geo_Buf[cnt].X=0;
		Geo_Buf[cnt].Y=0;
		Geo_Buf[cnt].Z=0;
		Tar_Angle.X=0;
		Tar_Angle.Y=0;
		Tar_Angle.Z=0;
	}


}

 

void GET_MPU_date(void)
{
	short gyx,gyy,gyz,acx,acy,acz;
	//short cx,cy,cz;
	u8 BUF[6];
  mpu_dmp_get_data(&q0,&q1,&q2,&q3);
	
//  printf("\r\nq0原始数据:%f \r\n",q0);
//  delay_ms(10);
//	printf("\r\nq1原始数据:%f \r\n",q1);
//	delay_ms(10);
//	printf("\r\nq2原始数据:%f \r\n",q2);
//	delay_ms(10);
//	printf("\r\nq3原始数据:%f \r\n",q3);
	
		MPU_Get_Accelerometer(&acx,&acy,&acz);
		
			MPU6050_Acc.X=acx;
			MPU6050_Acc.Y=acy;
			MPU6050_Acc.Z=acz;
//	
	 //printf("\r\n加速度Z轴原始数据:%f \r\n",(float)MPU6050_Acc.Z);
//   delay_ms(10);
	
			MPU_Get_Gyroscope(&gyx,&gyy,&gyz);
			
				MPU6050_Gyro.X=gyx;
				MPU6050_Gyro.Y=gyy;
				MPU6050_Gyro.Z=gyz;
			
					/*hmc5883_Get_geomagnetism(&cx,&cy,&cz);
				
					HMC5883_Geo.X=cx;
					HMC5883_Geo.Y=cy;
					HMC5883_Geo.Z=cz;*/
				
				Init_HMC5883();
				//delay_ms(10);
	      Multiple_read_HMC5883(BUF);
        HMC5883_Geo.X=BUF[0] << 8 | BUF[1]; 
        HMC5883_Geo.Z=BUF[2] << 8 | BUF[3]; 
        HMC5883_Geo.Y=BUF[4] << 8 | BUF[5];
				
				//BMP085Convert();
				
				//prepre=test_ref();
				
//					 printf("\r\n磁力计x轴原始数据:%f \r\n",(float)HMC5883_Geo.X);
//         //  delay_ms(10);
//					 printf("\r\n磁力计Y轴原始数据:%f \r\n",(float)HMC5883_Geo.Y);
////					 delay_ms(10);
//					 printf("\r\n磁力计Z轴原始数据:%f \r\n",(float)HMC5883_Geo.Z);
////					 delay_ms(10);

//             printf("\r\n加速度x轴原始数据:%f \r\n",(float)MPU6050_Acc.X);
//         //  delay_ms(10);
//					 printf("\r\n加速度y轴原始数据:%f \r\n",(float)MPU6050_Acc.Y);
////					 delay_ms(10);
//					 printf("\r\n加速度z轴原始数据:%f \r\n",(float)MPU6050_Acc.Z);
////					 delay_ms(10);

//             printf("\r\n陀螺仪x轴原始数据:%f \r\n",(float)MPU6050_Gyro.X);
//         //  delay_ms(10);
//					 printf("\r\n陀螺仪y轴原始数据:%f \r\n",(float)MPU6050_Gyro.Y);
////					 delay_ms(10);
//					 printf("\r\n陀螺仪Z轴原始数据:%f \r\n",(float)MPU6050_Gyro.Z);
////					 delay_ms(10);

}

  float  Preref;

void Date_Offset(u16 cnt)
{
	static short  Temp_GyroX,Temp_GyroY,Temp_GyroZ;
	static short  Temp_AccX, Temp_AccY, Temp_AccZ;
	static int i ;
	static float refp ;
	
	  refp +=prepre;
	
		Temp_AccX   +=	MPU6050_Acc.X;
		Temp_AccY	  +=	MPU6050_Acc.Y;		
		Temp_AccZ   +=  MPU6050_Acc.Z;
		Temp_GyroX	+=	MPU6050_Gyro.X;
		Temp_GyroY	+=	MPU6050_Gyro.Y;
		Temp_GyroZ	+=	MPU6050_Gyro.Z;
		
		
	//	i++;
		
	if(i==cnt)
	{
		i=0;
		Acc_Offset.X 	=	Temp_AccX	/	cnt;
		Temp_AccX=0;
		Acc_Offset.Y 	=	Temp_AccY	/	cnt;
		Temp_AccY=0;
		Acc_Offset.Z  = Temp_AccZ  / cnt ;
		Temp_AccZ=0;
		Gyro_Offset.X	= Temp_GyroX	/	cnt;
		Temp_GyroX=0;
		Gyro_Offset.Y	= Temp_GyroY	/	cnt;
		Temp_GyroY=0;
		Gyro_Offset.Z =	Temp_GyroZ	/	cnt;
		Temp_GyroZ=0;
		
		Preref=refp/cnt ;
	  refp=0;
		
		offsetflag=0;
		
		TIM_Cmd(TIM3, ENABLE);
		
	}
}



void GEO_fliter(void)
{
	      static float magRange[6] = {-171,151,-278,55,-173,172};   //Xmin,Xmax,........
       
        if(magRange[0] > HMC5883_Geo.X) magRange[0] =HMC5883_Geo.X*0.2 + magRange[0]*0.8; // x min
        if(magRange[1] < HMC5883_Geo.X) magRange[1] =HMC5883_Geo.X*0.2 + magRange[1]*0.8; // x max
        if(magRange[2] > HMC5883_Geo.Y) magRange[2] = HMC5883_Geo.Y*0.2 + magRange[2]*0.8;
        if(magRange[3] < HMC5883_Geo.Y) magRange[3] =HMC5883_Geo.Y*0.2 + magRange[3]*0.8;
        if(magRange[4] > HMC5883_Geo.Z) magRange[4] =HMC5883_Geo.Z*0.2 + magRange[4]*0.8; // z min
        if(magRange[5] < HMC5883_Geo.Z) magRange[5] = HMC5883_Geo.Z*0.2 + magRange[5]*0.8; // z max
        magOffset[0] = (magRange[0]+magRange[1])/2.0;
        magOffset[1] = (magRange[2]+magRange[3])/2.0;
        magOffset[2] = (magRange[4]+magRange[5])/2.0;
				
					
				
}



void Date_after_offset(void)
{
					Acc_date_after_Offset.X=MPU6050_Acc.X-Acc_Offset.X;
					Acc_date_after_Offset.Y=MPU6050_Acc.Y-Acc_Offset.Y;
					Acc_date_after_Offset.Z=MPU6050_Acc.Z;
					Gyro_date_after_Offset.X=MPU6050_Gyro.X-Gyro_Offset.X;
					Gyro_date_after_Offset.Y=MPU6050_Gyro.Y-Gyro_Offset.Y;
					Gyro_date_after_Offset.Z=MPU6050_Gyro.Z-Gyro_Offset.Z;
          Geo_date_after_Offset.X =HMC5883_Geo.X- magOffset[0];
          Geo_date_after_Offset.Y =HMC5883_Geo.Y- magOffset[1];
          Geo_date_after_Offset.Z =HMC5883_Geo.Z- magOffset[2];
}


void ACC_fliter(void)
{
	static u8 filter_cnt	=	0;
	static u8 cnt;
	S_INT32_XYZ	Temp_acc;
	S_INT32_XYZ	Temp_geo;
	
	Temp_acc.X = 0;
	Temp_acc.Y = 0;
	Temp_acc.Z = 0;
	Temp_geo.X = 0;
	Temp_geo.Y = 0;
	Temp_geo.Z = 0;
	
	Acc_Buf[filter_cnt].X = Acc_date_after_Offset.X;
	Acc_Buf[filter_cnt].Y	= Acc_date_after_Offset.Y;
	Acc_Buf[filter_cnt].Z = Acc_date_after_Offset.Z;
	Geo_Buf[filter_cnt].X = Geo_date_after_Offset.X;
	Geo_Buf[filter_cnt].Y	= Geo_date_after_Offset.Y;
	Geo_Buf[filter_cnt].Z = Geo_date_after_Offset.Z;
	
	filter_cnt++;
	
	for(cnt	=	0;cnt <	FILTER_WINDOW;cnt++)
	{
		Temp_acc.X += Acc_Buf[cnt].X;
		Temp_acc.Y += Acc_Buf[cnt].Y;
		Temp_acc.Z += Acc_Buf[cnt].Z;
		Temp_geo.X += Geo_Buf[cnt].X;
		Temp_geo.Y += Geo_Buf[cnt].Y;
		Temp_geo.Z += Geo_Buf[cnt].Z;
	}
	
	Acc_Avg.X = Temp_acc.X / FILTER_WINDOW;
	Acc_Avg.Y = Temp_acc.Y / FILTER_WINDOW;
	Acc_Avg.Z = Temp_acc.Z / FILTER_WINDOW;
	Geo_Avg.X = Temp_geo.X / FILTER_WINDOW;
	Geo_Avg.Y = Temp_geo.Y / FILTER_WINDOW;
	Geo_Avg.Z = Temp_geo.Z / FILTER_WINDOW;

	if(filter_cnt	==	FILTER_WINDOW)	
		filter_cnt = 0;
}

u8 offsetflag=1;

void Prepare_Data(void)
{
	while(offsetflag ==1)
	{
		OFFSET_function();
		
	}
	//Get_High();
//	printf("\r\n标志位:%f \r\n",(float)offsetflag );
	
	GET_MPU_date();
	
	GEO_fliter();
	
	Date_after_offset();
	
	ACC_fliter();
	
}

volatile S_FLOAT_XYZ Angle;

void AGLupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz)
{  
float norm;  
float hx, hy, hz, bx, bz;  
float vx, vy, vz, wx, wy, wz;  
float ex, ey, ez;  
float exInt = 0, eyInt = 0, ezInt = 0;
 
float q0q0 = q0*q0;  
float q0q1 = q0*q1;  
float q0q2 = q0*q2;  
float q0q3 = q0*q3;  
float q1q1 = q1*q1;  
float q1q2 = q1*q2;  
float q1q3 = q1*q3;  
float q2q2 = q2*q2;     
float q2q3 = q2*q3;  
float q3q3 = q3*q3;            

  
norm = sqrt(ax*ax + ay*ay + az*az);         
ax = ax / norm;  
ay = ay / norm;  
az = az / norm;  
norm = sqrt(mx*mx + my*my + mz*mz);            
mx = mx / norm;  
my = my / norm;  
mz = mz / norm;           

 
hx = 2*mx*(0.5 - q2q2 - q3q3) + 2*my*(q1q2 - q0q3) + 2*mz*(q1q3 + q0q2);  
hy = 2*mx*(q1q2 + q0q3) + 2*my*(0.5 - q1q1 - q3q3) + 2*mz*(q2q3 - q0q1);  
hz = 2*mx*(q1q3 - q0q2) + 2*my*(q2q3 + q0q1) + 2*mz*(0.5 - q1q1 - q2q2);           
bx = sqrt((hx*hx) + (hy*hy));  
bz = hz;          

  
vx = 2*(q1q3 - q0q2);  
vy = 2*(q0q1 + q2q3);  
vz = q0q0 - q1q1 - q2q2 + q3q3;  
wx = 2*bx*(0.5 - q2q2 - q3q3) + 2*bz*(q1q3 - q0q2);  
wy = 2*bx*(q1q2 - q0q3) + 2*bz*(q0q1 + q2q3);  
wz = 2*bx*(q0q2 + q1q3) + 2*bz*(0.5 - q1q1 - q2q2);    

  
ex = (ay*vz - az*vy) + (my*wz - mz*wy);  
ey = (az*vx - ax*vz) + (mz*wx - mx*wz);  
ez = (ax*vy - ay*vx) + (mx*wy - my*wx);  

  
exInt = exInt + ex*IMU_KI;  
eyInt = eyInt + ey*IMU_KI;  
ezInt = ezInt + ez*IMU_KI;  

 
gx = gx + IMU_KP*ex + exInt;  
gy = gy + IMU_KP*ey + eyInt;  
gz = gz + IMU_KP*ez + ezInt;  

 
q0 = q0 + (-q1*gx - q2*gy - q3*gz)*HALF_FS;  
q1 = q1 + (q0*gx + q2*gz - q3*gy)*HALF_FS;  
q2 = q2 + (q0*gy - q1*gz + q3*gx)*HALF_FS;  
q3 = q3 + (q0*gz + q1*gy - q2*gx)*HALF_FS;    

 
norm = sqrt(q0*q0 + q1*q1 + q2*q2 + q3*q3);  
q0 = q0 / norm;  
q1 = q1 / norm;  
q2 = q2 / norm;  
q3 = q3 / norm;  

//求解欧拉角
Angle.X = atan2(2 * q2q3 + 2 * q0q1, -2 * q1q1 - 2 * q2q2 + 1) * 57.3f;//Pitch
Angle.Y = -asin(-2 * q1q3 + 2 * q0q2) * 57.3f;//Roll
Angle.Z = atan2(2 * q1q2 + 2 * q0q3, -2 * q2q2 - 2 * q3q3 + 1)	* 57.3f;//Yaw

}  


void OFFSET_function(void)
{
	int i;
	TIM_Cmd(TIM3, DISABLE );
	for(i=0;i<=10;i++)
	{
		GET_MPU_date();
		BMP085Convert();	
		prepre=test_ref();
		Date_Offset(10);
	}
	
//  printf("\r\n校准加速度计X轴数据:%f \r\n",(float)Acc_Offset.X);
////	delay_ms(10);
//	printf("\r\n校准加速度计Y轴数据:%f \r\n",(float)Acc_Offset.Y);
//	//delay_ms(10);
//	printf("\r\n校准加速度计Z轴数据:%f \r\n",(float)Acc_Offset.Z );
//	//delay_ms(10);
//	printf("\r\n校准陀螺仪X轴数据:%f \r\n",(float)Gyro_Offset.X	);
////	delay_ms(10);
//	printf("\r\n校准陀螺仪Y轴数据:%f \r\n",(float)Gyro_Offset.Y );
////	delay_ms(10);
//	printf("\r\n校准陀螺仪Z轴数据:%f \r\n",(float)Gyro_Offset.Z	);
////	delay_ms(10);
//		
//	 printf("\r\n磁力计x轴原始数据:%f \r\n",(float)HMC5883_Geo.X);
////   delay_ms(10);
//	 printf("\r\n磁力计Y轴原始数据:%f \r\n",(float)HMC5883_Geo.Y);
////	 delay_ms(10);
//	 printf("\r\n磁力计Z轴原始数据:%f \r\n",(float)HMC5883_Geo.Z);
////	 delay_ms(10);
//	
	//printf("\r\n校准气压值：%f \r\n",Preref	);
	//delay_ms(10);
	

}

void source_date(void)
{

	 A=(float)Acc_date_after_Offset.Y/16384;		
   B=(float)A*1.2*180/3.14;
  //printf("\r\nPITCH度:%f \r\n",B);
   C=(float)Acc_date_after_Offset.X/16384;		
   D=(float)C*1.2*180/3.14;
 //printf("\r\nROLL度:%f \r\n",D);	

}

void usart1_send_char(u8 c)
{   	
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); //循环发送,直到发送完毕   
	USART_SendData(USART1,c);  
} 

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
void mpu6050_send_data(short yroll,short ypitch,short roll,short pitch,short yaw)
{
	u8 tbuf[12]; 
	tbuf[0]=(yroll>>8)&0XFF;
	tbuf[1]=yroll&0XFF;
	tbuf[2]=(ypitch>>8)&0XFF;
	tbuf[3]=ypitch&0XFF;
	tbuf[4]=(roll>>8)&0XFF;
	tbuf[5]=roll&0XFF; 
	tbuf[6]=(pitch>>8)&0XFF;
	tbuf[7]=pitch&0XFF;
	tbuf[8]=(yaw>>8)&0XFF;
	tbuf[9]=yaw&0XFF;
	
	usart1_niming_report(0XA1,tbuf,10);//自定义帧,0XA1
}	

void sendd(void)
{

	mpu6050_send_data((short)D,(short)B ,(short)Angle.Y ,(short)Angle.X ,(short)Angle.Z);

}



volatile S_FLOAT_XYZ	Gyro_Offset_angle_speed;

void GET_final_angle(void)
{
  
	Prepare_Data();

	AGLupdate(Gyro_date_after_Offset.X*GYROW_HDS,   Gyro_date_after_Offset.Y*GYROW_HDS,  Gyro_date_after_Offset.Z*GYROW_HDS,(float)	Acc_Avg.X,  (float) Acc_Avg.Y,  (float) Acc_Avg.Z,  (float)  Geo_Avg.X,  (float) Geo_Avg.Y,  (float)  Geo_Avg.Z);
	
	//source_date();
	//sendd();
	
	Gyro_Offset_angle_speed.X=Gyro_date_after_Offset.X*GYROW_DS;
	Gyro_Offset_angle_speed.Y=Gyro_date_after_Offset.Y*GYROW_DS;
	Gyro_Offset_angle_speed.Z=Gyro_date_after_Offset.Z*GYROW_DS;
}




