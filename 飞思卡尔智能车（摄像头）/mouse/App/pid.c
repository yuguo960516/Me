#include "pid.h"

           //         float  Ref;   		// Input: Reference input ��׼����
            //        float  Fdb;   		// Input: Feedback input  ��������
                    int  Err;			// Variable: Error        ���
           //         float  Kp;			// Parameter: Proportional gain ����extern                 float  Up,up;
           //         float  Ki;		        // Parameter: Integral gain       ����ϵ��   // Variable: Proportional output �������
           //         float  Kd; 		        // Parameter: Derivative gain          ΢������
                    int  Up;			// Variable: Proportional output �������
                    int  Ui;			// Variable: Integral output     �������
                    int  Ud;		        // Variable: Derivative output 	����-��� 
                    int  OutPreSat; 		// Variable: Pre-saturated output
           //         float  OutMin;	    	// Parameter: Minimum output    ��С�޷����
            //        float  OutMax;		// Parameter: Maximum output    ����޷����extern                 float  OutMin;	    	// Parameter: Minimum output    ��С�޷����
                    int  Out;   		// Output: PID output           PID�������
                    int  SatErr;		// Variable: Saturated difference ���Ͳ�
             //       int  Ki;		        // Parameter: Integral gain       ����ϵ��
            //        float  Ki_leave;       // �������           
                    int  Kc=5;		     	// Parameter: Integral correction gain ����У��
            //        int  Kd; 		        // Parameter: Derivative gain          ΢������
                    int  Err_old;		        // History: Previous proportional output��ǰ�ĳɱ��������
/*****  P,I D,��׼���룬�������룬������ޣ��������         *****/
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
   