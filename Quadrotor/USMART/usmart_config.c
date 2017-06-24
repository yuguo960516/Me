#include "usmart.h"
#include "usmart_str.h"


////////////////////////////�û�������///////////////////////////////////////////////
//������Ҫ�������õ��ĺ�����������ͷ�ļ�(�û��Լ����) 
#include "delay.h"		
#include "sys.h"
#include "control.h"

												
 
//�������б��ʼ��(�û��Լ����)
//�û�ֱ������������Ҫִ�еĺ�����������Ҵ�
struct _m_usmart_nametab usmart_nametab[]=
{
#if USMART_USE_WRFUNS==1 	//���ʹ���˶�д����
	(void*)read_addr,"u32 read_addr(u32 addr)",
	(void*)write_addr,"void write_addr(u32 addr,u32 val)",	 
#endif
	(void*)delay_ms,"void delay_ms(u16 nms)",
	(void*)delay_us,"void delay_us(u32 nus)",	
	(void*)PID_Init_OUT_P,"void PID_Init_OUT_P(float Pitch_Angle_P,float Roll_Angle_P,float Yaw_Angle_P)",
	(void*)PID_Init_OUT_I,"void PID_Init_OUT_I(float Pitch_Angle_I,float Roll_Angle_I,float Yaw_Angle_I)",
	(void*)PID_Init_OUT_D,"void PID_Init_OUT_D(float Pitch_Angle_D,float Roll_Angle_D,float Yaw_Angle_D)",
	(void*)PID_Init_IN_P,"void PID_Init_IN_P(float Pitch_Rate_P,float Roll_Rate_P,float Yaw_Rate_P)",
	(void*)PID_Init_IN_I,"void PID_Init_IN_I(float Pitch_Rate_I,float Roll_Rate_I,float Yaw_Rate_I)",
	(void*)PID_Init_IN_D,"void PID_Init_IN_D(float Pitch_Rate_D,float Roll_Rate_D,float Yaw_Rate_D)",
  (void*)H_PID_Init_OUT_P,"void H_PID_Init_OUT_P(float PID_Height_P)",
  (void*)H_PID_Init_OUT_I,"void H_PID_Init_OUT_I(float PID_Height_I)",
  (void*)H_PID_Init_OUT_D,"void H_PID_Init_OUT_D(float PID_Height_D)",
  (void*)Z_PID_Init_IN_P,"void Z_PID_Init_IN_P(float PID_Acc_z_after_offset_P)",
  (void*)Z_PID_Init_IN_I,"void Z_PID_Init_IN_I(float PID_Acc_z_after_offset_I)",
  (void*)Z_PID_Init_IN_D,"void Z_PID_Init_IN_D(float PID_Acc_z_after_offset_D)",
	
};						  
///////////////////////////////////END///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//�������ƹ�������ʼ��
//�õ������ܿغ���������
//�õ�����������
struct _m_usmart_dev usmart_dev=
{
	usmart_nametab,
	usmart_init,
	usmart_cmd_rec,
	usmart_exe,
	usmart_scan,
	sizeof(usmart_nametab)/sizeof(struct _m_usmart_nametab),//��������
	0,	  	//��������
	0,	 	//����ID
	1,		//������ʾ����,0,10����;1,16����
	0,		//��������.bitx:,0,����;1,�ַ���	    
	0,	  	//ÿ�������ĳ����ݴ��,��ҪMAX_PARM��0��ʼ��
	0,		//�����Ĳ���,��ҪPARM_LEN��0��ʼ��
};   



















