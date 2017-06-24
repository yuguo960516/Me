            #include "common.h"
            #include "include.h"
#include  "pid.h"

    int kp=10,kd=1,ki=5; 
//   int speed_min=400,speed_max=800;
   int count;
   
   extern      uint8 imgbuff1[CAMERA_SIZE];                             //定义存储接收图像的数组
   extern int speed_adjust;
   extern   int8 k1,k2,k3,k4,k5; 



void init() 
{
  
  uint8 num=1;
  
  led_init(LED_MAX);       //初始化LED : LED0  LED1  LED2  LED3
  
  key_init(KEY_MAX);    //初始化KEY : KEY3  KEY4  KEY5  KEY6  
                        //            KEY_1 KEY_2 KEY_3 KEY_4
  
  LCD_Init(); 
//        LCD_Fill(0x00);               //清屏
  
  uart_init(UART0,115200);
  
    /************************ 无线模块 NRF 初始化  ***********************/
    nrf_init();
    
    nrf_msg_init();                                                     //无线模块消息初始化

  
  tpm_pwm_init(TPM1,TPM_CH0,10000,0);
  
  tpm_pwm_init(TPM1,TPM_CH1,10000,0);
  
  tpm_pwm_init(TPM0,TPM_CH0,200,15100);            
  
  lptmr_pulse_init(LPT0_ALT2,0xFFFF,LPT_Rising);             //TPM脉冲计数编码器  PTC5

  gpio_init(PTC7,GPI,LOW);                                   //方向  

    //初始化摄像头                                              
  
  

  
  while(key_check(KEY_1)==0)
 {
          
           if(key_check(KEY6)==0)                       //参数设定 共6*2个
            {
               if(num==6||num==12)
                                LCD_Fill(0x00);               //清屏  

                
                          num++;                          
                         if(num>6)   num=1;
                         while(!key_check(KEY6));
                
            }
            if(key_check(KEY5)==0)                       //参数设定
            {
               if(num==1||num==7)
                                LCD_Fill(0x00);               //清屏  
              
                          num--;                          
                         if(num<1)   num=6;
                         while(!key_check(KEY5));
                
            }
           
           if(num<=6)
           {   
             LCD_P6x8Str(0,0,"   **  setting  **   ");//21*6=126;    
         LCD_P6x8Str(6,2,"sp_aj:");                  //舵机  PD调节
         LCD_P6x8Str(6,3,"k1   :");                  //舵机  PD调节 
         LCD_P6x8Str(6,4,"k1   :");                  //舵机  PD调节
         LCD_P6x8Str(6,5,"k3   :");                //计数
         LCD_P6x8Str(6,6,"k4   :");
         LCD_P6x8Str(6,7,"k5   :");
         OLEDdissign(64,2,speed_adjust);
         OLEDdissign(64,3,k1);
         OLEDdissign(64,4,k2);        
         OLEDdissign(64,5,k3);
         OLEDdissign(64,6,k4);
         OLEDdissign(64,7,k5);
           
          switch(num)
              {
                case 1:                      //判断
                   LCD_P6x8Str(0,2,">");
                
                   LCD_P6x8Str(0,3," ");
               
                   LCD_P6x8Str(0,4," ");
               
                   LCD_P6x8Str(0,5," ");
               
                   LCD_P6x8Str(0,6," ");
                
                   LCD_P6x8Str(0,7," ");
               
                    if(key_check(KEY4)==0)                //       
            {
          speed_adjust+=20;                 
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
          speed_adjust-=20;
                        while(!key_check(KEY3));
                
            }  
                      break;  
                   case 2:                        //
                   LCD_P6x8Str(0,2," ");
                
                   LCD_P6x8Str(0,3,">");
               
                   LCD_P6x8Str(0,4," ");
               
                   LCD_P6x8Str(0,5," ");
               
                   LCD_P6x8Str(0,6," ");
                
                   LCD_P6x8Str(0,7," ");
                       if(key_check(KEY4)==0)                //       
            {
          k1+=5;
             
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
          k1-=5;               
                         while(!key_check(KEY3));
                
            }  
                      break;   
                      case 3:                 //
                   LCD_P6x8Str(0,2," ");
                
                   LCD_P6x8Str(0,3," ");
               
                   LCD_P6x8Str(0,4,">");
               
                   LCD_P6x8Str(0,5," ");
               
                   LCD_P6x8Str(0,6," ");
                
                   LCD_P6x8Str(0,7," ");

                       if(key_check(KEY4)==0)                //       
            {
          k2+=5;
             
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
          k2-=5;
               
                         while(!key_check(KEY3));
                
            }  
                      break;
                   case 4:                    //
                   LCD_P6x8Str(0,2," ");
                
                   LCD_P6x8Str(0,3," ");
               
                   LCD_P6x8Str(0,4," ");
               
                   LCD_P6x8Str(0,5,">");
               
                   LCD_P6x8Str(0,6," ");
                
                   LCD_P6x8Str(0,7," ");

                       if(key_check(KEY4)==0)                //       
            {
             k3+=5;
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
              k3-=5;
                        while(!key_check(KEY3));
                
            }  
                      break;         
                  case 5:                        //
                   LCD_P6x8Str(0,2," ");
                
                   LCD_P6x8Str(0,3," ");
               
                   LCD_P6x8Str(0,4," ");
               
                   LCD_P6x8Str(0,5," ");
               
                   LCD_P6x8Str(0,6,">");
                
                   LCD_P6x8Str(0,7," ");
                      if(key_check(KEY4)==0)                //       
            {
             k4+=5;
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
               k4-=5;
                         while(!key_check(KEY3));
                
            }  
                      break;   
                   case 6:                        //
                   LCD_P6x8Str(0,2," ");
                
                   LCD_P6x8Str(0,3," ");
               
                   LCD_P6x8Str(0,4," ");
               
                   LCD_P6x8Str(0,5," ");
               
                   LCD_P6x8Str(0,6," ");
                
                   LCD_P6x8Str(0,7,">");
                       if(key_check(KEY4)==0)                //       
            {
          k5+=5;
             
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
          k5-=5;
               
                         while(!key_check(KEY3));
                
            }  
                      break;   

       
                 }  

      } 
      else
      {
         LCD_P6x8Str(0,0,"   **  setting  **   ");//21*6=126;    
         LCD_P6x8Str(6,2,":");                  //舵机  PD调节
         LCD_P6x8Str(6,3,":");                  //舵机  PD调节 
         LCD_P6x8Str(6,4,":");                  //舵机  PD调节
         LCD_P6x8Str(6,5,":");                //计数
         LCD_P6x8Str(6,6,":");
         LCD_P6x8Str(6,7,":");
           
          switch(num)
              {
                case 7:                      //
                   LCD_P6x8Str(0,2,">");
                
                   LCD_P6x8Str(0,3," ");
               
                   LCD_P6x8Str(0,4," ");
               
                   LCD_P6x8Str(0,5," ");
               
                   LCD_P6x8Str(0,6," ");
                
                   LCD_P6x8Str(0,7," ");
               
                    if(key_check(KEY4)==0)                //       
            {
          
      
             
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
         
      
                         while(!key_check(KEY3));
                
            }  
                      break;  
                   case 8:                        //
                   LCD_P6x8Str(0,2," ");
                
                   LCD_P6x8Str(0,3,">");
               
                   LCD_P6x8Str(0,4," ");
               
                   LCD_P6x8Str(0,5," ");
               
                   LCD_P6x8Str(0,6," ");
                
                   LCD_P6x8Str(0,7," ");
                       if(key_check(KEY4)==0)                //       
            {
          
             
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
          
               
                         while(!key_check(KEY3));
                
            }  
                      break;   
                      case 9:                 //
                   LCD_P6x8Str(0,2," ");
                
                   LCD_P6x8Str(0,3," ");
               
                   LCD_P6x8Str(0,4,">");
               
                   LCD_P6x8Str(0,5," ");
               
                   LCD_P6x8Str(0,6," ");
                
                   LCD_P6x8Str(0,7," ");

                       if(key_check(KEY4)==0)                //       
            {
          
             
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
          
               
                         while(!key_check(KEY3));
                
            }  
                      break;
                   case 10:                    //
                   LCD_P6x8Str(0,2," ");
                
                   LCD_P6x8Str(0,3," ");
               
                   LCD_P6x8Str(0,4," ");
               
                   LCD_P6x8Str(0,5,">");
              
                   LCD_P6x8Str(0,6," ");
                
                   LCD_P6x8Str(0,7," ");

                       if(key_check(KEY4)==0)                //       
            {
          
             
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
          
               
                         while(!key_check(KEY3));
                
            }  
                      break;         
                  case 11:                        //
                   LCD_P6x8Str(0,2," ");
                
                   LCD_P6x8Str(0,3," ");
               
                   LCD_P6x8Str(0,4," ");
               
                   LCD_P6x8Str(0,5," ");
               
                   LCD_P6x8Str(0,6,">");
                
                   LCD_P6x8Str(0,7," ");
                      if(key_check(KEY4)==0)                //       
            {
          
             
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
          
               
                         while(!key_check(KEY3));
                
            }  
                      break;   
                   case 12:                        //
                   LCD_P6x8Str(0,2," ");
                
                   LCD_P6x8Str(0,3," ");
               
                   LCD_P6x8Str(0,4," ");
               
                   LCD_P6x8Str(0,5," ");
               
                   LCD_P6x8Str(0,6," ");
                
                   LCD_P6x8Str(0,7,">");
                       if(key_check(KEY4)==0)                //       
            {
          
             
                         while(!key_check(KEY4));
                
            }  
                   if(key_check(KEY3)==0)                       
            {
          
               
                         while(!key_check(KEY3));
                
            }  
                      break;   

       
                 }  
      }
        
    }  
   LCD_Fill(0x00);               //清屏
  
}

//*******************************************************************




//  lptmr_pulse_init(LPT0_ALT2,0xFFFF,LPT_Rising);             //TPM脉冲计数编码器  PTC5
//  gpio_init(PTC9,GPI,LOW);                                   //方向
   


 



float abs_f(float x)       //绝对值函数
{
    if(x > 0)  return x;
    else return(-x);
}

