#include "telecontrol.h" 
#include "stdio.h"
#include "capture.h"
#include "usart3.h"
#include "delay.h"
#include "control.h"

static float ROLLoutP=0,ROLLoutI=0,ROLLoutD=0,ROLLinP=0,ROLLinI=0,ROLLinD=0;
static float PITCHoutP=0,PITCHoutI=0,PITCHoutD=0,PITCHinP=0,PITCHinI=0,PITCHinD=0;
static float YAWoutP=0,YAWoutI=0,YAWoutD=0,YAWinP=0,YAWinI=0,YAWinD=0;

 u16 left_right_throttle;
 u16 forward_back_throttle;
 u16 up_down_throttle;
 //u16 offset_throttle;

u32 Get_capture_1(void)
{
		if(TIM3CH1_CAPTURE_STA&0X80)//成功捕获到了一次上升沿
		{
			u32 temp1;
	    temp1=TIM3CH1_CAPTURE_VAL;//得到总的高电平时间
			//printf("HIGH1:%d us\r\n",temp1);//打印总的高点平时间
			TIM3CH1_CAPTURE_STA=0;//开启下一次捕获
			return temp1;
		}else return 0;		
}

u32 Get_capture_2(void)
{
	if(TIM3CH2_CAPTURE_STA&0X80)//成功捕获到了一次上升沿
	{
			u32 temp2;
	    temp2=TIM3CH2_CAPTURE_VAL;//得到总的高电平时间
			printf("HIGH2:%d us\r\n",temp2);//打印总的高点平时间
			TIM3CH2_CAPTURE_STA=0;//开启下一次捕获
			return temp2;
	}else return 0;
}

u32 Get_capture_3(void)
{
	if(TIM3CH3_CAPTURE_STA&0X80)//成功捕获到了一次上升沿
	{
			u32 temp3;
	    temp3=TIM3CH3_CAPTURE_VAL;//得到总的高电平时间
			printf("HIGH3:%d us\r\n",temp3);//打印总的高点平时间
			TIM3CH3_CAPTURE_STA=0;//开启下一次捕获
			return temp3;
	}else return 0;
}

void control_left_right(void)
{
	Get_capture_3();
}

void control_forward_back(void)
{
	 Get_capture_2();
}

void control_up_down(void)
{
	  u32 i;
	  float a;
  	i=Get_capture_1();
	if(i>=996&&i<=1890)
	{
		a=1000+1.0f*(i-996);
		up_down_throttle=(u16)a;
	}
}

//void throttle_test(void)
//{
//	  u32 i;
//	  float a;
//  	i=Get_capture_1();
//	if(i>=996&&i<=1890)
//	{
//		a=1000+1.0f*(i-996);
//		offset_throttle=(u16)a;
//	}
//}

void Get_bluetoothdate(void)
{
	   u8 reclen=0;
			if(USART3_RX_STA&0X8000)			//接收到一次数据了
		{
		
 			reclen=USART3_RX_STA&0X7FFF;	//得到数据长度
		  USART3_RX_BUF[reclen]=0;	 	//加入结束符
			//u3_printf("%d\r\n",USART3_RX_BUF[0]);
 			//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
			if(USART3_RX_BUF[0]==51)			//3
			{
				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
				ROLLoutI=ROLLoutI+0.1f;
	      PID_Init_OUT_I(PITCHoutI,ROLLoutI,YAWoutI);
			  printf("\r\nROLLoutI:%f\r\n",ROLLoutI);
			}
			if(USART3_RX_BUF[0]==52)			//4
			{
				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
				ROLLoutI=ROLLoutI-0.1f;
	      PID_Init_OUT_I(PITCHoutI,ROLLoutI,YAWoutI);
			  printf("\r\nROLLoutI:%f\r\n",ROLLoutI);
			}
			if(USART3_RX_BUF[0]==53)			//5
			{
				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
				ROLLoutD=ROLLoutD+0.1f;
	      PID_Init_OUT_D(PITCHoutD,ROLLoutD,YAWoutD);
			  printf("\r\nROLLoutD:%f\r\n",ROLLoutD);
			}
			if(USART3_RX_BUF[0]==54)			//6
			{
				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
				ROLLoutD=ROLLoutD-0.1f;
	      PID_Init_OUT_D(PITCHoutD,ROLLoutD,YAWoutD);
			  printf("\r\nROLLoutD:%f\r\n",ROLLoutD);
			}
			if(USART3_RX_BUF[0]==55)			//7
			{
				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
				ROLLinP=ROLLinP+0.1f;
	      PID_Init_IN_P(PITCHinP,ROLLinP,YAWinP);
			  printf("\r\rROLLinP:%f\r\n",ROLLinP);
			}
			if(USART3_RX_BUF[0]==56)			//8
			{
				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
				ROLLinP=ROLLinP-0.1f;
	      PID_Init_IN_P(PITCHinP,ROLLinP,YAWinP);
			  printf("\r\rROLLinP:%f\r\n",ROLLinP);
			}
			if(USART3_RX_BUF[0]==57)			//9
			{
				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
				ROLLinI=ROLLinI+0.1f;
	      PID_Init_IN_I(PITCHinI,ROLLinI,YAWinI);
			  printf("\r\rROLLinI:%f\r\n",ROLLinI);
			}
			if(USART3_RX_BUF[0]==49&&USART3_RX_BUF[1]==50)			//12
			{
				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
					ROLLinD=ROLLinD-0.1f;
					PID_Init_IN_D(PITCHinD,ROLLinD,YAWinD);
					printf("\r\rROLLinD:%f\r\n",ROLLinD);
			}else if(USART3_RX_BUF[0]==49&&USART3_RX_BUF[1]==49)			//11
							{
								//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
								//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
									ROLLinD=ROLLinD+0.1f;
									PID_Init_IN_D(PITCHinD,ROLLinD,YAWinD);
									printf("\r\rROLLinD:%f\r\n",ROLLinD);
							}else if(USART3_RX_BUF[0]==49&&USART3_RX_BUF[1]==48)			//10
											{
												//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
								        //printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
													ROLLinI=ROLLinI-0.1f;
													PID_Init_IN_I(PITCHinI,ROLLinI,YAWinI);
													printf("\r\rROLLinI:%f\r\n",ROLLinI);
											}else if(USART3_RX_BUF[0]==49&&USART3_RX_BUF[1]==51)			//13
																			{
																				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																			 // printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
																					PITCHoutP=PITCHoutP+0.1f;
																					PID_Init_OUT_P(PITCHoutP,ROLLoutP,YAWoutP);
																					printf("\r\rPITCHoutP:%f\r\n",PITCHoutP);
																			}else if(USART3_RX_BUF[0]==49&&USART3_RX_BUF[1]==52)			//14
																							{
																								//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																							 // printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
																								PITCHoutP=PITCHoutP-0.1f;
																								PID_Init_OUT_P(PITCHoutP,ROLLoutP,YAWoutP);
																								printf("\r\rPITCHoutP:%f\r\n",PITCHoutP);
																							}else if(USART3_RX_BUF[0]==49&&USART3_RX_BUF[1]==53)			//15
																											{
																												//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																											  //printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
																												PITCHoutI=PITCHoutI+0.1f;
																												PID_Init_OUT_I(PITCHoutI,ROLLoutI,YAWoutI);
																												printf("\r\rPITCHoutI:%f\r\n",PITCHoutI);
																											}else if(USART3_RX_BUF[0]==49&&USART3_RX_BUF[1]==54)			//16
																															{
																																//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																															  //printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
																																PITCHoutI=PITCHoutI-0.1f;
																																PID_Init_OUT_I(PITCHoutI,ROLLoutI,YAWoutI);
																																printf("\r\rPITCHoutI:%f\r\n",PITCHoutI);
																															}else if(USART3_RX_BUF[0]==49&&USART3_RX_BUF[1]==55)			//17
																																			{
																																				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																																			  //printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
																																				PITCHoutD=PITCHoutD+0.1f;
																																				PID_Init_OUT_D(PITCHoutD,ROLLoutD,YAWoutD);
																																				printf("\r\rPITCHoutD:%f\r\n",PITCHoutD);
																																			}else if(USART3_RX_BUF[0]==49&&USART3_RX_BUF[1]==56)			//18
																																							{
																																								//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																																							 // printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
																																								PITCHoutD=PITCHoutD-0.1f;
																																								PID_Init_OUT_D(PITCHoutD,ROLLoutD,YAWoutD);
																																								printf("\r\rPITCHoutD:%f\r\n",PITCHoutD);
																																							}else if(USART3_RX_BUF[0]==49&&USART3_RX_BUF[1]==57)			//19
																																											{
																																												//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																																											  //printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
																																												PITCHinP=PITCHinP+0.1f;
																																												PID_Init_IN_P(PITCHinP,ROLLinP,YAWinP);
																																												printf("\r\rPITCHinP:%f\r\n",PITCHinP);
																																											}else if(USART3_RX_BUF[0]==49)			//1
																																															{
																																																//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																																																ROLLoutP=ROLLoutP+0.1f;
																																																PID_Init_OUT_P(PITCHoutP,ROLLoutP,YAWoutP);
																																																printf("\r\nROLLoutP:%f\r\n",ROLLoutP);
																																															}
																																														
      if(USART3_RX_BUF[0]==50&&USART3_RX_BUF[1]==48)			//20
					{
						//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
					  //printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
						PITCHinP=PITCHinP-0.1f;
						PID_Init_IN_P(PITCHinP,ROLLinP,YAWinP);
						printf("\r\rPITCHinP:%f\r\n",PITCHinP);
					}else if(USART3_RX_BUF[0]==50&&USART3_RX_BUF[1]==49)			//21
							{
								//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
								//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
								PITCHinI=PITCHinI+0.1f;
								PID_Init_IN_I(PITCHinI,ROLLinI,YAWinI);
								printf("\r\rPITCHinI:%f\r\n",PITCHinI);
							}else if(USART3_RX_BUF[0]==50&&USART3_RX_BUF[1]==50)			//22
											{
												//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
												//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
												PITCHinI=PITCHinI-0.1f;
												PID_Init_IN_I(PITCHinI,ROLLinI,YAWinI);
												printf("\r\rPITCHinI:%f\r\n",PITCHinI);
											}else if(USART3_RX_BUF[0]==50&&USART3_RX_BUF[1]==51)			//23
															{
																//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
																PITCHinD=PITCHinD+0.1f;
																PID_Init_IN_D(PITCHinD,ROLLinD,YAWinD);
																printf("\r\rPITCHinD:%f\r\n",PITCHinD);
															}else if(USART3_RX_BUF[0]==50&&USART3_RX_BUF[1]==52)			//24
																			{
																				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																				//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[1]);
																				PITCHinD=PITCHinD-0.1f;
																				PID_Init_IN_D(PITCHinD,ROLLinD,YAWinD);
																				printf("\r\rPITCHinD:%f\r\n",PITCHinD);
																			}else if(USART3_RX_BUF[0]==50)			//2
																							{
																								//printf("\r\n接受到的数据:%d\r\n",USART3_RX_BUF[0]);
																								ROLLoutP=ROLLoutP-0.1f;
																								PID_Init_OUT_P(PITCHoutP,ROLLoutP,YAWoutP);
																								printf("\r\nROLLoutP:%f\r\n",ROLLoutP);
																							}
 			USART3_RX_STA=0;	 
		}	 											
}

void bluetoothdate_process(void)
{
	Get_bluetoothdate();
}


