
          /*                   LYLG_MOUSE                          */

#include "common.h"
#include "include.h"

       
extern uint8 imgbuff1[CAMERA_SIZE];                             //定义存储接收图像的数组
extern uint8 imgbuff2[CAMERA_SIZE];                             //定义存储接收图像的数组
extern uint8 Picture_Finish;                              //图像传输完成标志位
extern uint8 ov7725_eagle_odd_even_flag;                        //奇偶场标志位
extern uint8   *ov7725_eagle_img_buff;


//uint8 imgbuff[CAMERA_SIZE];                             //定义存储接收图像的数组
uint8 img[CAMERA_H][CAMERA_W];                           //由于鹰眼摄像头是一字节8个像素，因而需要解压为 1字节1个像素，方便处理
  
 int speed_in=0,speed_out=0,speed=0,speed_ref=0,speed_adjust=0;
 int angle=0,angle_old=0,angle_out;
 int8 road_flag;
 uint8 mode; 
  uint8 safe=1;
  int8 dangerous=0;
//  extern uint8 medium_line[CAMERA_H];   
  extern int8 left_line[CAMERA_H];
  extern int8 right_line[CAMERA_H];
 extern int count;
 extern int8 stop,cross;  
  

 
  
//函数声明
void vcan_sendimg(uint8 *imgaddr, uint32 imgsize);
void img_extract(uint8 *dst, uint8 *src, uint32 srclen);
void PORTA_IRQHandler();
void PORTC_PORTD_IRQHandler();
void DMA0_IRQHandler();
void show_img();
void nrf_send_img();
void nrf_send_ware();
void oled_show_img();

void check_speed();       

void  main(void)
{
      
  uint8 t=230; 
      /************   初始化    *************/
      init ();                                    
                           
     //配置中断服务函数      
    pit_init_ms(PIT0,8);                                         //设置PIT中断 8ms     
//    pit_init_ms(PIT1,1000);                                          //设置PIT中断 17ms     
    set_vector_handler(PIT_VECTORn,check_speed);                 //设置中断服务函数 
    enable_irq(PIT_IRQn);                                    //使能PIT中断      
               
    set_vector_handler(PORTC_PORTD_VECTORn ,PORTC_PORTD_IRQHandler);                //设置 PORTE 的中断服务函数为 PORTE_VECTORn
    enable_irq(PORTC_PORTD_IRQn);  

    set_vector_handler(PORTA_VECTORn ,PORTA_IRQHandler);    //设置LPTMR的中断服务函数为 PORTA_IRQHandler
    set_vector_handler(DMA0_VECTORn ,DMA0_IRQHandler);      //设置LPTMR的中断服务函数为 PORTA_IRQHandler
    
      uint8 mode = PTC_B0_IN%16;   //模式判断   
          
      OLEDdissign(48,0,mode);  
      LCD_Print(0,0,"mode:");  //OLED显示   
      
      camera_init(imgbuff1);                                                    

      while(key_check(KEY6));    
      
   LCD_Fill(0x00);               //清屏
   
//   run(6000,0);  
//   DELAY_MS(400);
//   run(9000,0);
   DELAY_MS(1000);
  
      /*******************  循环  *********************/
   while(1) 
    { 
      if(Picture_Finish == 1)
      { 
               Picture_Finish = 0;                        //清除  场中断图像采集完成标志位
              
               
         if(ov7725_eagle_odd_even_flag == 1)    //奇场图像
        {
            ov7725_eagle_odd_even_flag = 2;        //标志位反转
            ov7725_eagle_img_buff = imgbuff1;      //指针交换
        }
        else                              //偶场图像 
        { 
            ov7725_eagle_odd_even_flag = 1;       //标志位反转
            ov7725_eagle_img_buff = imgbuff2;     //指针交换
        } 
        
               if(ov7725_eagle_odd_even_flag == 1 )      //处理奇场图像
               {
                 img_extract((uint8 *)img, imgbuff1,600);          //解压图像到  imgbuff1  数组
               }
               else                              //处理偶场图像 
               {
                 img_extract( (uint8 *)img, imgbuff2,600);          //解压图像到  imgbuff2  数组
               }
        // 由进到远扫描中线，每次扫描中点反馈到下一行扫描起始点//
        //               中线重写入数据 8                      //
        scan_line();
       /*  起跑线检测 & 保护程序  */
          if(t>0)
            t--;
          else 
        if(  (img[CAMERA_H-9][left_line[CAMERA_H-9]+16]==0
             ||img[CAMERA_H-13][left_line[CAMERA_H-13]+15]==0
               ||img[CAMERA_H-16][left_line[CAMERA_H-16]+14]==0
                 ||img[CAMERA_H-18][left_line[CAMERA_H-18]+15]==0
                   ||img[CAMERA_H-20][left_line[CAMERA_H-20]+14]==0
                     ||img[CAMERA_H-22][left_line[CAMERA_H-22]+13]==0) 
           && 
             (img[CAMERA_H-9][right_line[CAMERA_H-9]-16]==0
              ||img[CAMERA_H-13][right_line[CAMERA_H-13]-15]==0
                ||img[CAMERA_H-16][right_line[CAMERA_H-16]-14]==0
                  ||img[CAMERA_H-18][right_line[CAMERA_H-18]-15]==0
                    ||img[CAMERA_H-20][right_line[CAMERA_H-20]-14]==0
                      ||img[CAMERA_H-22][right_line[CAMERA_H-22]-13]==0)  
//              && right_line[49]-left_line[49]>40
//              && right_line[47]-left_line[47]>40
//              && right_line[45]-left_line[45]>40
//              && right_line[43]-left_line[43]>40
//              && right_line[41]-left_line[41]>40
//              && right_line[39]-left_line[39]>40
                 && safe==1  && road_flag!=0)                                           //safe==1  
        {
          safe=3; 
        }
        /**********  障碍检测  *************/
    if(road_flag==1) 
    {      
      if( ( img[12][check_medium(0,12,12)-8]==0
           || img[15][check_medium(0,15,15)-8]==0
             || img[18][check_medium(0,18,18)-8]==0 
               || img[24][check_medium(0,24,24)-8]==0 ) 
         && right_line[12]-left_line[12]>20
          && right_line[15]-left_line[15]>20
           && right_line[18]-left_line[18]>20
            && right_line[24]-left_line[24]>20
                 && safe==1 && dangerous==0 ) 
        { 
          safe=2;                                            //0
//          speed_adjust-=200;
          led(LED0,0);
           pit_init_ms(PIT1,500);                                         //设置PIT中断 800ms               
        }
      if( ( img[12][check_medium(2,12,12)+8]==0
           || img[15][check_medium(2,15,15)+8]==0
             || img[18][check_medium(2,18,18)+8]==0 
               || img[24][check_medium(2,24,24)+8]==0 )
         && right_line[12]-left_line[12]>20
          && right_line[15]-left_line[15]>20
           && right_line[18]-left_line[18]>20
            && right_line[24]-left_line[24]>20
                 && safe==1 && dangerous==0 )  
        { 
          safe=0;                                               //2
//          speed_adjust-=200; 
          led(LED1,0);
           pit_init_ms(PIT1,500);                                         //设置PIT中断 800ms               
        }
    }
//        OLEDdissign(0,5,safe);
        
           //计算        
        computer();       
        
       run(speed_out,angle_out); 
       
                       
        if(mode%8<4)
        {
          safe=3;
          nrf_send_img(); 
        }
        if(mode%4<2)
          nrf_send_ware();
         
        if(mode<8)
          oled_show_img();
      }
    }
}

         //上位机二值化输出显示

 void show_img()
       {
         uint8 img_h;
          uint8 img_w;
        for(img_h=0;img_h<CAMERA_H;img_h++)
        {
          for(img_w=0;img_w<CAMERA_W;img_w++)
          {  
        printf("%d",img[img_h][img_w]);
          }
          printf(" %5.d%5.d%5.d%5.d\n ",left_line[img_h],medium_line[img_h],right_line[img_h],img_h);
        } 
        printf("\n");        
       }

//无线串口发送
void nrf_send_img() 
{
  uint8 i,j;
         uint8 img_h;
         uint8 img_w;
         uint8 nrf_buff[100],nrf[26],*buff;
  buff=nrf;
  
  for(img_h=0;img_h<CAMERA_H;img_h++)
  {
    nrf_buff[0]='>';
    for(img_w=0;img_w<CAMERA_W;img_w++)
    {
      if(img_w==medium_line[img_h])  
      nrf_buff[img_w+1]='*';
      else
      if(img_w==left_line[img_h] || img_w==right_line[img_h])
        nrf_buff[img_w+1]='#';
      else        
      nrf_buff[img_w+1]=img[img_h][img_w]+0x30;
    }
    nrf_buff[81]=' ';
    nrf_buff[82]=' ';
    nrf_buff[85]=' ';
    nrf_buff[86]=' ';
    nrf_buff[89]=' ';
    nrf_buff[90]=' ';
    nrf_buff[93]=' ';
    nrf_buff[94]=' ';
    nrf_buff[97]=' ';
    nrf_buff[98]=' ';
    nrf_buff[99]=10;
    
    nrf_buff[83]=left_line[img_h]/10+0x30;
    nrf_buff[84]=left_line[img_h]%10+0x30;
    nrf_buff[87]=medium_line[img_h]/10+0x30;
    nrf_buff[88]=medium_line[img_h]%10+0x30;
    nrf_buff[91]=right_line[img_h]/10+0x30;
    nrf_buff[92]=right_line[img_h]%10+0x30;
    nrf_buff[95]=img_h/10+0x30;    
    nrf_buff[96]=img_h%10+0x30;   
    


  for(i=0;i<4;i++)
  {
    nrf[0]=25;
    for(j=0;j<25;j++)
    {
       nrf[j+1]=nrf_buff[25*i+j];
    }
    
  if(nrf_tx(buff,26)==1)
  while(nrf_tx_state()==NRF_TXING);
  DELAY_MS(2);
  }
 }
}

//oled显示图像
void oled_show_img()
{ 
uint8 img_h=0,img_w=0,date=0,i=0;
while(img_h<56) 
{
  img_h+=8;  
     LCD_Set_Pos(24,img_h/8); 
  for(img_w=0;img_w<CAMERA_W;img_w++)
  {    
   date=0;
   for(i=1;i<8;i++) 
   {    
     date+=img[img_h-i][img_w];
     date=date<<1; 
   } 
     date+=img[img_h-8][img_w];
   
     LCD_WrDat(date); 
  }
}
} 
//无线串口虚拟示波器
void nrf_send_ware()
{
  int8 ware[9];
  ware[1]=0x03;
  ware[2]=0xfc;
    ware[3]=count/2;
    ware[4]=speed_ref/24;
    ware[5]=speed_out/24;
    ware[6]=angle_out/28;
  ware[7]=0xfc;
  ware[8]=0x03;  
    ware[0]=8;
    int8 *re;re=ware;
  
  if(nrf_tx(re,8)==1)
  while(nrf_tx_state()==NRF_TXING);
  DELAY_MS(1); 
}

//发送图像到上位机显示
//不同的上位机，不同的命令
//如果使用其他上位机，则需要修改代码
void vcan_sendimg(uint8 *imgaddr, uint32 imgsize)
{
#define CMD_IMG     1 
    uint8 cmdf[2] = {CMD_IMG, ~CMD_IMG};    //山外上位机 使用的命令
    uint8 cmdr[2] = {~CMD_IMG, CMD_IMG};    //山外上位机 使用的命令

    uart_putbuff(VCAN_PORT, cmdf, sizeof(cmdf));    //先发送命令

    uart_putbuff(VCAN_PORT, imgaddr, imgsize); //再发送图像

    uart_putbuff(VCAN_PORT, cmdr, sizeof(cmdr));    //先发送命令
}


/*!
 *  @brief      二值化图像解压（空间 换 时间 解压）
 *  @param      dst             图像解压目的地址
 *  @param      src             图像解压源地址
 *  @param      srclen          二值化图像的占用空间大小
 *  @since      v5.0            img_extract(img, imgbuff,CAMERA_SIZE);
 *  Sample usage:
 */
void img_extract(uint8 *dst, uint8 *src,uint32 srclen)
{
    uint8 colour[2] = {1, 0}; //0 和 1 分别对应的颜色
    //注：山外的摄像头 0 表示 白色，1表示 黑色
    uint8 tmpsrc;
    while(srclen --)
    {
        tmpsrc = *src++;
        *dst++ = colour[ (tmpsrc >> 7 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 6 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 5 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 4 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 3 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 2 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 1 ) & 0x01 ];
        *dst++ = colour[ (tmpsrc >> 0 ) & 0x01 ];
    }
}

//           定时器中断函数
   void check_speed()
   {
      if(PIT_TFLG(PIT0)==1)
   {
         /****编码器***********/
     if(!gpio_get(PTC7))
         count =  lptmr_pulse_get();                           //保存脉冲计数器计算值 
     else
         count = - lptmr_pulse_get(); 

     lptmr_pulse_clean();                                      //清空脉冲计数器计算值（开始新的计数）
          
        PIT_Flag_Clear(PIT0); 
        
//         OLEDdissign(0,2,count);        
        

   } 
   
      if(PIT_TFLG(PIT1)==1)
      {
        safe=1;
//        speed_adjust+=200;
//          led(LED0,1);
//         led(LED1,1);

        pit_close(PIT1);    
         }
      }
   

void PORTC_PORTD_IRQHandler()
{
    uint8  n = 0;    //引脚号

    //PTC18
    n = 18;
    if(PORTC_ISFR & (1 << n))           //PTC18触发中断
    {
        PORTC_ISFR  = (1 << n);        //写1清中断标志位

        //  以下为用户任务  
        nrf_handler();           
        //  以上为用户任务  
    }
}


/*!
 *  @brief      PORTA中断服务函数
 *  @since      v5.0
 */
void PORTA_IRQHandler()
{
    uint8  n = 0;    //引脚号
    uint32 flag = PORTA_ISFR;
    PORTA_ISFR  = ~0;                                   //清中断标志位

    n = 6;                                              //场中断
    if(flag & (1 << n))                                 //PTA6触发中断
    {
        camera_vsync();                                 //采集图像
    }
}

/*!
 *  @brief      DMA0中断服务函数
 *  @since      v5.0
 */
void DMA0_IRQHandler()
{
    camera_dma();
}