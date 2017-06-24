#include "pid.h"

           //         float  Ref;   		// Input: Reference input 标准输入
            //        float  Fdb;   		// Input: Feedback input  反馈输入
                    int  Err;			// Variable: Error        误差
           //         float  Kp;			// Parameter: Proportional gain 比例extern                 float  Up,up;
           //         float  Ki;		        // Parameter: Integral gain       积分系数   // Variable: Proportional output 比例输出
           //         float  Kd; 		        // Parameter: Derivative gain          微分增益
                    int  Up;			// Variable: Proportional output 比例输出
                    int  Ui;			// Variable: Integral output     积分输出
                    int  Ud;		        // Variable: Derivative output 	导数-输出 
                    int  OutPreSat; 		// Variable: Pre-saturated output
           //         float  OutMin;	    	// Parameter: Minimum output    最小限幅输出
            //        float  OutMax;		// Parameter: Maximum output    最大限幅输出extern                 float  OutMin;	    	// Parameter: Minimum output    最小限幅输出
                    int  Out;   		// Output: PID output           PID最终输出
                    int  SatErr;		// Variable: Saturated difference 饱和差
             //       int  Ki;		        // Parameter: Integral gain       积分系数
            //        float  Ki_leave;       // 分离积分           
                    int  Kc=5;		     	// Parameter: Integral correction gain 积分校正
            //        int  Kd; 		        // Parameter: Derivative gain          微分增益
                    int  Err_old;		        // History: Previous proportional output以前的成比例的输出
/*****  P,I D,标准输入，反馈输入，输出下限，输出上限         *****/
   int pid(int Kp,int Ki,int Kd,int Ref,int Fdb,int OutMin,int OutMax) 
   {
     int Ref_Old=0; 
     
   Err=Fdb-Ref; 
   
   Up=Kp*Err;
   
   Ui=Ui+Ki*Err/10-Kc*SatErr;
   
   if(Ui>2000) Ui=2000;
   
   Ud=Kd*(Ref - Ref_Old);
      
   OutPreSat =Ref-Up - Ui +  Ud;
   
       if (OutPreSat > OutMax)
      Out =  OutMax;
    else if (OutPreSat < OutMin) 
      Out =  OutMin;
    else
      Out = OutPreSat;
    
    SatErr = Out - OutPreSat; 

   
   Err_old=Err;
   Ref_Old=Ref;
   
   return Out;
   }
   