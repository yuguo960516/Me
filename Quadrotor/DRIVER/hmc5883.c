#include "hmc5883.h"
#include "iicc.h"
#include "delay.h"
#include "mpu6050.h"


#define SlaveAddress 0x3C


void Init_HMC5883(void)
{
     
   //  MPU_IIC_Init();
//    Write_HMC5883(0x00, 0x78);        
//    Write_HMC5883(0x01, 0x00);       
//  Write_HMC5883(0x02, 0x00);      
 
   Write_HMC5883(0x00, 0x70);      
   Write_HMC5883(0x01, 0xA0);      
   Write_HMC5883(0x02, 0x00);     
	
     
}
 
 
void Write_HMC5883(u8 add, u8 da)
{
    IICC_Start();                  
    IICC_Send_Byte(SlaveAddress);   
    IICC_Wait_Ack();
 
    IICC_Send_Byte(add);    
    IICC_Wait_Ack();
 
    IICC_Send_Byte(da);       
    IICC_Wait_Ack();
 
    IICC_Stop();                  
   // delay_ms(10);
}
 
 
 
u8 Read_HMC5883(u8 REG_Address)
{   
    u8 REG_data;
    IICC_Start();                         
    IICC_Send_Byte(SlaveAddress);           
    IICC_Wait_Ack();
 
    IICC_Send_Byte(REG_Address);                     
    IICC_Wait_Ack();
 
    IICC_Start();                         
    IICC_Send_Byte(SlaveAddress+1);         
    IICC_Wait_Ack();
 
    REG_data=IICC_Read_Byte(0);              
    IICC_Stop();                           
    delay_ms(5);
    return REG_data; 
}
 

void Multiple_read_HMC5883(u8* BUF)
{   u8 i;
    IICC_Start();                          
    IICC_Send_Byte(SlaveAddress);           
    IICC_Wait_Ack();
    IICC_Send_Byte(0x03);                     
    IICC_Wait_Ack();
    IICC_Start();                          
    IICC_Send_Byte(SlaveAddress+1);         
    IICC_Wait_Ack();
     for (i=0; i<6; i++)                      
    {
         
        if (i == 5)
        {
           BUF[i] = IICC_Read_Byte(0);         
        }
        else
        {
          BUF[i] = IICC_Read_Byte(1);        
       }
   }
    IICC_Stop();                       
  
}


/*void hmc5883_Get_geomagnetism(short *mx,short *my,short *mz)
{
	      u8 BUF[6];
				Init_HMC5883();
				delay_ms(10);
	      Multiple_read_HMC5883(BUF);
        *mx=BUF[0] << 8 | BUF[1]; //Combine MSB and LSB of X Data output register
        *mz=BUF[2] << 8 | BUF[3]; //Combine MSB and LSB of Z Data output register
        *my=BUF[4] << 8 | BUF[5]; //Combine MSB and LSB of Y Data output register

}*/















