#include "iicc.h"
#include "delay.h"
#include "bmp085.h"

short ac1,ac2,ac3,b1,b2,mb,mc,md;

unsigned short ac4;
unsigned short ac5;
unsigned short ac6;

long  temperature3;
long  pressure3;

//***************************************************

void Single_Write_BMP085(u8 REG_Address,u8 REG_data)
{
    IICC_Start();                 //��ʼ�ź�
    IICC_Send_Byte(BMP085_ADDRESS);   //�����豸��ַ+д�ź�
	  IICC_Wait_Ack();
    IICC_Send_Byte(REG_Address);    //�ڲ��Ĵ�����ַ����ο�����pdf
	  IICC_Wait_Ack(); 
    IICC_Send_Byte(REG_data);       //�ڲ��Ĵ������ݣ���ο�����pdf
	  IICC_Wait_Ack();
    IICC_Stop();                   //����ֹͣ�ź�
}

//********���ֽڶ�ȡ�ڲ��Ĵ���*************************
u8 Single_Read_BMP085(u8 REG_Address)
{   u8 REG_data;
    IICC_Start();                         //��ʼ�ź�
    IICC_Send_Byte(BMP085_ADDRESS);           //�����豸��ַ+д�ź�
	  IICC_Wait_Ack();
    IICC_Send_Byte(REG_Address);                   //���ʹ洢��Ԫ��ַ����0��ʼ
	  IICC_Wait_Ack();	
    IICC_Start();                         //��ʼ�ź�
    IICC_Send_Byte(BMP085_ADDRESS+1);         //�����豸��ַ+���ź�
	  IICC_Wait_Ack();
    REG_data=IICC_Read_Byte(0);              //�����Ĵ�������  
	  IICC_Stop();                         //ֹͣ�ź�
    return REG_data; 
}

//******************************************************
//
//��������HMC5883�ڲ��Ƕ����ݣ���ַ��Χ0x3~0x5
//
//******************************************************
short Multiple_read_BMP085(u8 REG_Address)
{   u8 msb,lsb;
    short _data;
    IICC_Start();                          //��ʼ�ź�
    IICC_Send_Byte(BMP085_ADDRESS);           //�����豸��ַ+д�ź�
	  IICC_Wait_Ack();
    IICC_Send_Byte(REG_Address);                   //���ʹ洢��Ԫ��ַ����0x3��ʼ
	  IICC_Wait_Ack();	
    IICC_Start();                          //��ʼ�ź�
    IICC_Send_Byte(BMP085_ADDRESS+1);         //�����豸��ַ+���ź�
	  IICC_Wait_Ack();
    msb=IICC_Read_Byte(1);
	  lsb=IICC_Read_Byte(0);
    IICC_Stop();                          //ֹͣ�ź�
	  delay_ms(3);
	_data=(msb<<8)|lsb;
	return(_data);	
}
//********************************************************************
long BMP085ReadTemp(void)
{

    IICC_Start();                  //��ʼ�ź�
    IICC_Send_Byte(BMP085_ADDRESS);   //�����豸��ַ+д�ź�
	  IICC_Wait_Ack();
    IICC_Send_Byte(0xF4);	          // write register address
	  IICC_Wait_Ack();
    IICC_Send_Byte(0x2E);       	// write register data for temp
	  IICC_Wait_Ack();
    IICC_Stop();                    //����ֹͣ�ź�
	
	return (long) Multiple_read_BMP085(0xF6);
}
//*************************************************************
long BMP085ReadPressure(void)
{
	long pressure = 0;

    IICC_Start();                   //��ʼ�ź�
    IICC_Send_Byte(BMP085_ADDRESS);   //�����豸��ַ+д�ź�
	  IICC_Wait_Ack();
    IICC_Send_Byte(0xF4);	          // write register address
	  IICC_Wait_Ack();
    IICC_Send_Byte(0x34);       	  // write register data for pressure
	  IICC_Wait_Ack();
    IICC_Stop(); 
	
	pressure = Multiple_read_BMP085(0xF6);
	pressure &= 0x0000FFFF;
	
	return pressure;	
}

//**************************************************************

//��ʼ��BMP085��������Ҫ��ο�pdf�����޸�**************
void Init_BMP085()
{
	ac1 = Multiple_read_BMP085(0xAA);
	ac2 = Multiple_read_BMP085(0xAC);
	ac3 = Multiple_read_BMP085(0xAE);
	ac4 = Multiple_read_BMP085(0xB0);
	ac5 = Multiple_read_BMP085(0xB2);
	ac6 = Multiple_read_BMP085(0xB4);
	b1 =  Multiple_read_BMP085(0xB6);
	b2 =  Multiple_read_BMP085(0xB8);
	mb =  Multiple_read_BMP085(0xBA);
	mc =  Multiple_read_BMP085(0xBC);
	md =  Multiple_read_BMP085(0xBE);
}

//***********************************************************************
void BMP085Convert(void)
{
	long ut;
	long up;
	long x1, x2, b5, b6, x3, b3, p;
	unsigned long b4, b7;
	
	
	ut = BMP085ReadTemp();
	ut = BMP085ReadTemp();	   // ��ȡ�¶�
	up = BMP085ReadPressure();
	up = BMP085ReadPressure();  // ��ȡѹǿ
	
	x1 = ((long)ut - ac6) * ac5 >> 15;
	x2 = ((long) mc << 11) / (x1 + md);
	b5 = x1 + x2;
	temperature3 = (b5 + 8) >> 4;
	//printf("BMP�¶ȣ�%f��  ",(double)((double)temperature3/10));
	
	b6 = b5 - 4000;
	x1 = (b2 * (b6 * b6 >> 12)) >> 11;
	x2 = ac2 * b6 >> 11;
	x3 = x1 + x2;
	b3 = (((long)ac1 * 4 + x3) + 2)/4;
	x1 = ac3 * b6 >> 13;
	x2 = (b1 * (b6 * b6 >> 12)) >> 16;
	x3 = ((x1 + x2) + 2) >> 2;
	b4 = (ac4 * (unsigned long) (x3 + 32768)) >> 15;
	b7 = ((unsigned long) up - b3) * (50000 >> OSS);
	if( b7 < 0x80000000)
	     p = (b7 * 2) / b4 ;
           else  
		    p = (b7 / b4) * 2;
	x1 = (p >> 8) * (p >> 8);
	x1 = (x1 * 3038) >> 16;
	x2 = (-7357 * p) >> 16;
	pressure3 = p + ((x1 + x2 + 3791) >> 4);
	//printf("��ѹ��%fKpa\r\n",(double)((double)pressure3/1000));

}

float Get_High(void)      //   Z2-Z1=18400(1+t/273)log( P1/P2) 
{

	float high;
	float ture_temp;
	float ture_presure1,ture_presure_ref;//     ture_presure_ref=Pre!!!
	ture_presure_ref=Preref;
	ture_presure1=(double)((double)pressure3/1000);
  ture_temp=(double)((double)temperature3/10);
	high=18400*(1+ture_temp/273)*log(ture_presure_ref/ture_presure1);
	
	//printf("\r\n��ǰ�¶�ֵ:%f \r\n",(float)ture_temp);
//	delay_ms(10);
	//printf("\r\n��׼��ѹֵ:%f \r\n",ture_presure_ref);
//  delay_ms(10);
//	printf("\r\n�߶�ֵ:%f \r\n",(float)high);
	
	return high;
  
}

float test_ref(void)
{
	float Pre,Preee;
	Preee=(double)((double)pressure3/1000);
	Pre=(float)Preee;
	//printf("/r/n��׼��ѹֵΪ:%f Pa",Pre);
	return Pre;
	
}



