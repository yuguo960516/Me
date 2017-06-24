#include "cpu_reg.h"
#include "exsram.h"

int 	ms;
int 	DA_rptr;
int     play_mode;


void main()
{

     asm("  STM #0000h,CLKMD ");  
     while(*CLKMD & 0x01 );
     asm("  STM #40c7h,CLKMD ");
     
/*  40C7h:5*clkin  =100M
    30c7h:4*clkin  =80M
    20c7h:3*clkin  =60M
    10C7h:2*clkin  =40M
*/

     asm("  stm   #4240h, SWWSR ");
     //2 wait except for on-chip program 1
     asm("  stm   #00a0h, PMST  "); //MP/MC = 0, IPTR = 001,ovly=1  
     asm("  stm   #0802h, BSCR  "); 
     asm("  STM #0h,IMR ");
     
     asm("  STM #0010h,TCR  "); //关定时器
     asm("  STM #0186ah,PRD  ");//1ms
     asm("  STM #0C2fh,TCR  "); //TCR=最后四位
     asm("  STM #0008h,IFR  ");
     asm("  ORM #0008h,*(IMR) ");/*开时间中断*/
 
     DA_rptr=0;
     
     McBsp0_init();//串口初始化
     clear_exsram();
     
     asm("  RSBX  INTM ");      /*开中断*/ 
     
     play_mode=0;              //发警报声
     
     while(1)
     {

     }
}  


interrupt void  timer0()
{
     ms++;    	
}

