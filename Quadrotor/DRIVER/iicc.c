#include "iicc.h"
#include "delay.h"

 
 //MPU IIC ��ʱ����
void IICC_Delay(void)
{
	delay_us(2);
}

//��ʼ��IIC
void IICC_Init(void)
{					     
  GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//��ʹ������IO PORTBʱ�� 
		
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15;	 // �˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIO 
	
  GPIO_SetBits(GPIOC,GPIO_Pin_14|GPIO_Pin_15);						
 
}
//����IIC��ʼ�ź�
void IICC_Start(void)
{
	IICC_SDA_OUT();     //sda�����
	IICC_SDA=1;	  	  
	IICC_SCL=1;
	IICC_Delay();
 	IICC_SDA=0;//START:when CLK is high,DATA change form high to low 
	IICC_Delay();
	IICC_SCL=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//����IICֹͣ�ź�
void IICC_Stop(void)
{
	IICC_SDA_OUT();//sda�����
	IICC_SCL=0;
	IICC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	IICC_Delay();
	IICC_SCL=1; 
	IICC_SDA=1;//����I2C���߽����ź�
	IICC_Delay();							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IICC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	IICC_SDA_IN();      //SDA����Ϊ����  
	IICC_SDA=1;IICC_Delay();	   
	IICC_SCL=1;IICC_Delay();	 
	while(IICC_READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IICC_Stop();
			return 1;
		}
	}
	IICC_SCL=0;//ʱ�����0 	   
	return 0;  
} 
//����ACKӦ��
void IICC_Ack(void)
{
	IICC_SCL=0;
	IICC_SDA_OUT();
	IICC_SDA=0;
	IICC_Delay();
	IICC_SCL=1;
	IICC_Delay();
	IICC_SCL=0;
}
//������ACKӦ��		    
void IICC_NAck(void)
{
	IICC_SCL=0;
	IICC_SDA_OUT();
	IICC_SDA=1;
	IICC_Delay();
	IICC_SCL=1;
	IICC_Delay();
	IICC_SCL=0;
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IICC_Send_Byte(u8 txd)
{                        
    u8 t;   
	IICC_SDA_OUT(); 	    
    IICC_SCL=0;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        IICC_SDA=(txd&0x80)>>7;
        txd<<=1; 	  
		    IICC_SCL=1;
		    IICC_Delay(); 
		    IICC_SCL=0;	
		    IICC_Delay();
    }	 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 IICC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	IICC_SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        IICC_SCL=0; 
        IICC_Delay();
		    IICC_SCL=1;
        receive<<=1;
        if(IICC_READ_SDA)receive++;   
		IICC_Delay(); 
    }					 
    if (!ack)
        IICC_NAck();//����nACK
    else
        IICC_Ack(); //����ACK   
    return receive;
}


























