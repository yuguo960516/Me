
          /*                   LYLG_MOUSE                          */

#include "common.h"
#include "include.h"

       
extern uint8 imgbuff1[CAMERA_SIZE];                             //����洢����ͼ�������
extern uint8 imgbuff2[CAMERA_SIZE];                             //����洢����ͼ�������
extern uint8 Picture_Finish;                              //ͼ������ɱ�־λ
extern uint8 ov7725_eagle_odd_even_flag;                        //��ż����־λ
extern uint8   *ov7725_eagle_img_buff;


//uint8 imgbuff[CAMERA_SIZE];                             //����洢����ͼ�������
uint8 img[CAMERA_H][CAMERA_W];                           //����ӥ������ͷ��һ�ֽ�8�����أ������Ҫ��ѹΪ 1�ֽ�1�����أ����㴦��
  
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
  

 
  
//��������
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
      /************   ��ʼ��    *************/
      init ();                                    
                           
     //�����жϷ�����      
    pit_init_ms(PIT0,8);                                         //����PIT�ж� 8ms     
//    pit_init_ms(PIT1,1000);                                          //����PIT�ж� 17ms     
    set_vector_handler(PIT_VECTORn,check_speed);                 //�����жϷ����� 
    enable_irq(PIT_IRQn);                                    //ʹ��PIT�ж�      
               
    set_vector_handler(PORTC_PORTD_VECTORn ,PORTC_PORTD_IRQHandler);                //���� PORTE ���жϷ�����Ϊ PORTE_VECTORn
    enable_irq(PORTC_PORTD_IRQn);  

    set_vector_handler(PORTA_VECTORn ,PORTA_IRQHandler);    //����LPTMR���жϷ�����Ϊ PORTA_IRQHandler
    set_vector_handler(DMA0_VECTORn ,DMA0_IRQHandler);      //����LPTMR���жϷ�����Ϊ PORTA_IRQHandler
    
      uint8 mode = PTC_B0_IN%16;   //ģʽ�ж�   
          
      OLEDdissign(48,0,mode);  
      LCD_Print(0,0,"mode:");  //OLED��ʾ   
      
      camera_init(imgbuff1);                                                    

      while(key_check(KEY6));    
      
   LCD_Fill(0x00);               //����
   
//   run(6000,0);  
//   DELAY_MS(400);
//   run(9000,0);
   DELAY_MS(1000);
  
      /*******************  ѭ��  *********************/
   while(1) 
    { 
      if(Picture_Finish == 1)
      { 
               Picture_Finish = 0;                        //���  ���ж�ͼ��ɼ���ɱ�־λ
              
               
         if(ov7725_eagle_odd_even_flag == 1)    //�泡ͼ��
        {
            ov7725_eagle_odd_even_flag = 2;        //��־λ��ת
            ov7725_eagle_img_buff = imgbuff1;      //ָ�뽻��
        }
        else                              //ż��ͼ�� 
        { 
            ov7725_eagle_odd_even_flag = 1;       //��־λ��ת
            ov7725_eagle_img_buff = imgbuff2;     //ָ�뽻��
        } 
        
               if(ov7725_eagle_odd_even_flag == 1 )      //�����泡ͼ��
               {
                 img_extract((uint8 *)img, imgbuff1,600);          //��ѹͼ��  imgbuff1  ����
               }
               else                              //����ż��ͼ�� 
               {
                 img_extract( (uint8 *)img, imgbuff2,600);          //��ѹͼ��  imgbuff2  ����
               }
        // �ɽ���Զɨ�����ߣ�ÿ��ɨ���е㷴������һ��ɨ����ʼ��//
        //               ������д������ 8                      //
        scan_line();
       /*  �����߼�� & ��������  */
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
        /**********  �ϰ����  *************/
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
           pit_init_ms(PIT1,500);                                         //����PIT�ж� 800ms               
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
           pit_init_ms(PIT1,500);                                         //����PIT�ж� 800ms               
        }
    }
//        OLEDdissign(0,5,safe);
        
           //����        
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

         //��λ����ֵ�������ʾ

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

//���ߴ��ڷ���
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

//oled��ʾͼ��
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
//���ߴ�������ʾ����
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

//����ͼ����λ����ʾ
//��ͬ����λ������ͬ������
//���ʹ��������λ��������Ҫ�޸Ĵ���
void vcan_sendimg(uint8 *imgaddr, uint32 imgsize)
{
#define CMD_IMG     1 
    uint8 cmdf[2] = {CMD_IMG, ~CMD_IMG};    //ɽ����λ�� ʹ�õ�����
    uint8 cmdr[2] = {~CMD_IMG, CMD_IMG};    //ɽ����λ�� ʹ�õ�����

    uart_putbuff(VCAN_PORT, cmdf, sizeof(cmdf));    //�ȷ�������

    uart_putbuff(VCAN_PORT, imgaddr, imgsize); //�ٷ���ͼ��

    uart_putbuff(VCAN_PORT, cmdr, sizeof(cmdr));    //�ȷ�������
}


/*!
 *  @brief      ��ֵ��ͼ���ѹ���ռ� �� ʱ�� ��ѹ��
 *  @param      dst             ͼ���ѹĿ�ĵ�ַ
 *  @param      src             ͼ���ѹԴ��ַ
 *  @param      srclen          ��ֵ��ͼ���ռ�ÿռ��С
 *  @since      v5.0            img_extract(img, imgbuff,CAMERA_SIZE);
 *  Sample usage:
 */
void img_extract(uint8 *dst, uint8 *src,uint32 srclen)
{
    uint8 colour[2] = {1, 0}; //0 �� 1 �ֱ��Ӧ����ɫ
    //ע��ɽ�������ͷ 0 ��ʾ ��ɫ��1��ʾ ��ɫ
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

//           ��ʱ���жϺ���
   void check_speed()
   {
      if(PIT_TFLG(PIT0)==1)
   {
         /****������***********/
     if(!gpio_get(PTC7))
         count =  lptmr_pulse_get();                           //�����������������ֵ 
     else
         count = - lptmr_pulse_get(); 

     lptmr_pulse_clean();                                      //����������������ֵ����ʼ�µļ�����
          
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
    uint8  n = 0;    //���ź�

    //PTC18
    n = 18;
    if(PORTC_ISFR & (1 << n))           //PTC18�����ж�
    {
        PORTC_ISFR  = (1 << n);        //д1���жϱ�־λ

        //  ����Ϊ�û�����  
        nrf_handler();           
        //  ����Ϊ�û�����  
    }
}


/*!
 *  @brief      PORTA�жϷ�����
 *  @since      v5.0
 */
void PORTA_IRQHandler()
{
    uint8  n = 0;    //���ź�
    uint32 flag = PORTA_ISFR;
    PORTA_ISFR  = ~0;                                   //���жϱ�־λ

    n = 6;                                              //���ж�
    if(flag & (1 << n))                                 //PTA6�����ж�
    {
        camera_vsync();                                 //�ɼ�ͼ��
    }
}

/*!
 *  @brief      DMA0�жϷ�����
 *  @since      v5.0
 */
void DMA0_IRQHandler()
{
    camera_dma();
}