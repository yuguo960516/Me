#include "cpu_reg.h"

int ADbuf[500];
extern int DA_rptr;
extern int play_mode;


void write_subreg0(unsigned int addr,unsigned int val);
unsigned int read_subreg0(unsigned int addr);

unsigned int read_subreg0(unsigned int addr)
{
       *(SPSA0)=addr;
       return(*SPSD0);
} 
    
void write_subreg0(unsigned int addr,unsigned int val)
{
      *(SPSA0)=addr;
      *(SPSD0)=val;
}  

void McBsp0_init()
{

     write_subreg0(SPCR1,0);
     write_subreg0(SPCR2,0);

     write_subreg0(SPCR1,SPCR10_VAL);
     write_subreg0(SPCR2,SPCR20_VAL);
     write_subreg0(PCR,PCR0_VAL);

     write_subreg0(RCR1,RCR10_VAL);
     write_subreg0(RCR2,RCR20_VAL);
     write_subreg0(XCR1,XCR10_VAL);
     write_subreg0(XCR2,XCR20_VAL);
     delay(10);
     
     *(DXR10)=0;
     
     /*now enable McBSP transmit and receive*/
     write_subreg0(SPCR1,SPCR10_VAL|1);
     write_subreg0(SPCR2,SPCR20_VAL|1);
     delay(10);
     
     *(IMR)|=0x0010;    //开接收0中断
     
}     

void delay(int k)
{
   while(k--);
}

interrupt void  codec_ch0_in() //接收0中断
{
      int temp;
        
      temp=*DRR10;
        
      DA_rptr++;
      if(DA_rptr>=500)
            DA_rptr=0;

      ADbuf[DA_rptr]=temp;   //保存录音数据
      
      if(play_mode==0)
      {

      }
      else
        *DXR10=temp;        //放音

}
