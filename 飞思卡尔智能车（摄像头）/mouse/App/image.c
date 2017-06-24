            #include "common.h"
            #include "include.h"
       
        extern   uint8 img[CAMERA_H][CAMERA_W];  //图像数组
        extern   uint8 dangerous; 
        int min,max;         //比较变量   赋初值
        int8 img_h;         //行循环变量 赋初值
        int8 img_w;         //列循环变量 赋初值
        int8 stop=0,cross=0,wide=0;            //越过中线   停止行
        int8 lim_left,lim_right;//极值点
   
        int8 medium_line[CAMERA_H],medium_line_old[CAMERA_H];  //中线
        int8 left_line[CAMERA_H];    //左边线
        int8 right_line[CAMERA_H];   //右边线
//        uint8 road_width[CAMERA_H];   //路宽    

 // 由进到远  横向  扫描边线，每次扫描中点反馈到下一行扫描起始点//
 //          求中线     中线重写入数据 8                      //
//                     标注行数 、 中线列数       //
 void scan_line()
{  
int8  img_m=CAMERA_W/2;
int8 Left_Black=0,Right_Black=CAMERA_W;
int8 left_start=0,left_stop=0,right_start=0,right_stop=0;
//int8 d_left=0,d_right=0;

//int8 left_edge=0,right_edge=0; 
int8 left_flag=0,right_flag=0;

 stop=0; cross=0;wide=0;
dangerous=0;                
  for(img_h=CAMERA_H-1;img_h>=0;img_h--)                //扫描行
  { 
          if(img[img_h][Left_Black]==0)                 //扫描左边
            for(img_w=Left_Black+1;img_w<CAMERA_W;img_w++)    
             { 
               if(img[img_h][img_w]==1) 
               break; 
             }
          else
            for(img_w=Left_Black;img_w>=0;img_w--)
            {
            if(img[img_h][img_w-1]==0)
              break; 
            } 
          if(img_w<0)img_w=0;
          if(img_w>=CAMERA_W) img_w=CAMERA_W-1;
            Left_Black=img_w;        
         /************   补线条件   **********************/
         if(  (left_line[img_h+3]+left_line[img_h+6]            
                -left_line[img_h+9]-Left_Black>=5                    //预计偏差
             &&   2*left_line[img_h+6]-left_line[img_h+2]            
                -left_line[img_h+10]<=2                            //曲率
           && img_h<CAMERA_H-10     && img_h>=6                                //补线范围
          && right_line[img_h+1]- right_line[img_h+6]>=-6              //矫正
         && left_line[img_h+1]*left_line[img_h+9]!=0)              //丢线不补
          || (Left_Black==0 
               && left_flag) )
           
         {
           left_flag=1;
           if(  left_start-img_h>=1 
            && CAMERA_H-left_start>left_start-img_h )
           {
           Left_Black=2*left_line[left_start]-left_line[2*left_start-img_h];
           }
           else
           { 
           if(abs(left_line[img_h+3]+left_line[img_h+9]
              -2*left_line[img_h+6])<=4) 
            Left_Black=left_line[img_h+3]+left_line[img_h+6]
                -left_line[img_h+9]; 
           else
            Left_Black=left_line[img_h+2]+left_line[img_h+5] 
                -left_line[img_h+7];   
           }
         
         if(Left_Black<0) Left_Black=0;
         if(Left_Black>CAMERA_W-1) Left_Black=CAMERA_W-1;
         
         if(img[img_h][Left_Black]==0)                                 //
         {
          for(int8 i=1;i<=img_h+5;i++)
          {
          if(img[img_h][Left_Black+i]==1)
          {
            Left_Black=Left_Black+i;
           break;
          }
          }           
         }
         else
         {
          for(int8 i=1;i<=8;i++)
          {
            if(img[img_h][Left_Black-i]==1)
            {
            Left_Black=Left_Black+i;
             break;
            }
          }           
         }
           
          if(left_start==0)
          {                       
          left_line[img_h+1]=(left_line[img_h+3]+2*Left_Black)/3;
          left_line[img_h+2]=(2*left_line[img_h+3]+Left_Black)/3;
                                              
          left_start=img_h;
          }
         }
         else
         {
           left_flag=0;
         if(left_start!=0 && left_stop==0)
           left_stop=img_h;
         }
        /**********************************************/         
         if(img[img_h][Right_Black]==0)
     for(img_w=Right_Black-1;img_w>=0;img_w--)          // 扫描右边
     {                              
       if(img[img_h][img_w]==1)
        break;  
     } 
     else
       for(img_w=Right_Black;img_w<CAMERA_W;img_w++)
       {
       if(img[img_h][img_w+1]==0)
         break;
       }
          if(img_w<0)img_w=0;
          if(img_w>=CAMERA_W)img_w=CAMERA_W-1;       
         Right_Black=img_w;
         /**************    补线条件    *****************/ 
         if(  (right_line[img_h+3]+right_line[img_h+6]
                  -right_line[img_h+9]-Right_Black<=-6           //
          &&  2*right_line[img_h+6]-right_line[img_h+2]
                -right_line[img_h+10>=-2]                          //
         && left_line[img_h+1]- left_line[img_h+6]<=6              //矫正
            && img_h<CAMERA_H-10   && img_h>=5                            //
        && right_line[img_h+1]!=CAMERA_W-1                     //
        && right_line[img_h+9]!=CAMERA_W-1)
           || (Right_Black==CAMERA_W-1 
               && right_flag) )                      //
         {     
           right_flag=1;
          if( right_start-img_h>=1    
            && CAMERA_H-right_start>right_start-img_h ) 
           {  
          Right_Black=2*right_line[right_start]-right_line[2*right_start-img_h];
           } 
          else
          { 
             if(abs(right_line[img_h+3]+right_line[img_h+9]
                -right_line[img_h+6])<=4) 
         Right_Black=right_line[img_h+3]+right_line[img_h+6]
                -right_line[img_h+9];
           else    
         Right_Black=right_line[img_h+2]+right_line[img_h+5]
                -right_line[img_h+7];
          }
         
         if(Right_Black<0) Right_Black=0;
         if(Right_Black>CAMERA_W-1) Right_Black=CAMERA_W-1;
         
         if(img[img_h][Right_Black]==0)                                 //
         {
          for(int8 i=1;i<=img_h+5;i++)
          {
          if(img[img_h][Right_Black-i]==1)
          {
            Right_Black=Right_Black-i;
           break;
          }
          }           
         }
         else
         {
          for(int8 i=1;i<=8;i++)
          {
          if(img[img_h][Right_Black+i]==1)
          {
            Right_Black=Right_Black-i;
           break; 
          }
          }           
         }
           
          if(right_start==0)
          {                       
         right_line[img_h+1]=(right_line[img_h+3]+2*Right_Black+2)/3;
         right_line[img_h+2]=(2*right_line[img_h+3]+Right_Black+2)/3;
         
         right_start==img_h;
          }
         }
           else
         {
           right_flag=0;
         if(right_start!=0 && right_stop==0)
           right_stop=img_h;
         }


     /****       补线        ****/
//         if(Right_Black-Left_Black>img_h+20)
                          
     if(Left_Black!=0 && Right_Black!=CAMERA_W-1)      //左右正常
     {
     img_m = (Left_Black + Right_Black)/2; 
     }
     
     if(Left_Black==0 && Right_Black==CAMERA_W-1)     //左右丢失
     { 
       if(img_h<CAMERA_H-6)                          //正常补线
       {  
       if(left_line[img_h-1]>=6) 
         Left_Black=(3*left_line[img_h+2]-left_line[img_h+6])/2; 
       if(right_line[img_h-1]<CAMERA_W-6)
         Right_Black=(3*right_line[img_h+2]-right_line[img_h+6])/2;
        }       
     img_m = (Left_Black + Right_Black)/2;
     }
     
     if(Left_Black==0 && Right_Black!=CAMERA_W-1)     //左丢线
     { 
      img_m = Right_Black-img_h/2-12;
     if(img_m<0)
       img_m=0;        
     }
     
     if(Left_Black!=0 && Right_Black==CAMERA_W-1)     //右丢线
     {       
     img_m = Left_Black+img_h/2+12;      
      if(img_m>CAMERA_W-1)
        img_m=CAMERA_W-1;
     }
     
     if( left_flag || right_flag )
       dangerous=1;
     
         left_line[img_h]=Left_Black;
         right_line[img_h]=Right_Black;                                          
         medium_line[img_h]=img_m; 
         
         if(Left_Black)
         img[img_h][Left_Black-1] = 0;
         else
         img[img_h][Left_Black] = 0; 
         
         if(79-Right_Black)
         img[img_h][Right_Black+1] = 0; 
         else
         img[img_h][Right_Black] = 0;  
         
         img[img_h][img_m] = 0;                   
         
      
     if(Left_Black>=Right_Black && stop==0)    
     {
     stop=img_h;
//     OLEDdissign(0,4,stop); 
     for(img_h=stop;img_h>=0;img_h--)
     {
         left_line[img_h]=left_line[stop+1];
         right_line[img_h]=right_line[stop+1];                                          
         medium_line[img_h]=medium_line[stop+1]; 
     }      
       break;
     }      
     
     if( (Left_Black>=36 || Right_Black<44)
        && cross==0 )                           //越过中线
      {  
     cross=img_h;
//     OLEDdissign(0,3,cross);     
       }
     
  }
} 
/******************************************************************************/
    
     /*******  求中点  ***********/
     //第h1行到第h2行平均值
     uint8 check_medium(uint8 flag,uint8 h1,uint8 h2)  //左：0 右：2 中：1
     {
       uint16 m=0;
       switch (flag)
       {case 0:
       for(uint8 i=h1;i<=h2;i++)
         m+=left_line[i]+img_h/3+12;
         break;
       case 1:
       for(uint8 i=h1;i<=h2;i++)
         m+=medium_line[i];
         break;
       case 2:
       for(uint8 i=h1;i<=h2;i++)
         m+=right_line[i]-img_h/3-12;       
         break;  
       case 3:
       for(uint8 i=h1;i<=h2;i++)
         m+=medium_line[i];
         break;
       } 
       return m/(h2-h1+1);   
     }
          
     /*******  求斜率  ***********/
         //第h1到第h2行的斜率//          
     float slope(uint8 flag,uint8 h1,uint8 h2)  //左：0 右：2 中：1 
     {
       switch(flag)
       {
       case 0:
           return ((float)(left_line[h2]-left_line[h1])/(float)(h2-h1));
           break;
       case 1:            
           return ((float)(medium_line[h2]-medium_line[h1])/(float)(h2-h1));
           break;
       case 2:     
           return ((float)(right_line[h2]-right_line[h1])/(float)(h2-h1));
           break; 
       default:
         return 0;  
       }
     }
              
     
     /********    路形判断   **********
       直道：1       入左弯：2    入右弯：3    左弯：4 
               右弯：5   S弯：6    十字弯：10     错误：0 */
     
     uint8 check_road_flag()
     {   
       uint8 flag=0;
       
//      check_lim(); 
               
       if(flag==0)                                //直道  范围 1.2 米
       {
       if((abs(medium_line[5]+2*medium_line[35]-3*medium_line[25])<=9)
         && (abs(2*medium_line[5]+medium_line[35]-3*medium_line[15])<=9)  )
       {
//     if((abs(medium_line[0]+3*medium_line[40]-4*medium_line[30])<=8) 
//       && (abs(medium_line[0]+medium_line[40]-2*medium_line[20])<=4) 
//       && (abs(3*medium_line[0]+medium_line[40]-4*medium_line[10])<=8) ) 
           if(3*medium_line[0]+medium_line[40]-4*medium_line[10]<=-8)
             flag=2;
             else if(3*medium_line[0]+medium_line[40]-4*medium_line[10]>=8)
              flag=3; 
              else
         flag=1; 
       }
       }
           
               
//       LCD_P8x16Str(16,6,"flag:");           //LED显示道路标志
//       switch(flag)
//       {
//       case 10: LCD_P8x16Str(64,6,"+ "); break;
//       
//       case 1: LCD_P8x16Str(64,6,"^ "); break; 
//       
//       case 2: LCD_P8x16Str(64,6,"<\\"); break;
//       case 4: LCD_P8x16Str(64,6,"<-"); break;
//       
//       case 3: LCD_P8x16Str(64,6,"/>"); break;
//       case 5: LCD_P8x16Str(64,6,"->"); break;
//       
//       case 6: LCD_P8x16Str(64,6,"S "); break;
//       
//       case 0: LCD_P8x16Str(64,6,"  "); break;
//       }       
      
       return flag;
     } 
     