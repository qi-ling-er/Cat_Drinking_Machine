#include "stm32f10x.h"                  // Device header
#include "Delay.h" 
#include "Key.h"
#include "HCSR501.h"
#include "FM.h"
#include "Elect.h"
#include "Fixed_time_mode.h"


/*同HCSR501.c文件的GPIO引脚配置一定要相同*/
#define    GPIO_Pin_HC1     	GPIO_Pin_1	
#define    GPIO_Pin_HC2 			GPIO_Pin_2	
#define    GPIO_Pin_HC3     	GPIO_Pin_3	
#define    GPIO_Pin_HC4 			GPIO_Pin_4	
#define    GPIO_SER   	  		GPIOA	

/**
  * 函    数：感应供水模式
  * 参    数：无
	* 返 回 值：无
	* 注		意：可修改感应供水时间
  */
int main(void)
{
	/*按键初始化*/
	Key_init();
	/*红外传感初始化*/
	SR501_init();
	/*继电器初始化*/
	Elect_init();
	/*蜂鸣器初始化*/
	FM_init();

	/*接收HCSR501的返回中断标志*/
	int16_t temp = 0;
	/*无感应时的标志位*/
	uint8_t HCSR1,HCSR2,HCSR3,HCSR4;
	/*感应模式的供水时间*/
	uint16_t i;
	uint16_t Induction_SetTime;
	Induction_SetTime = 8000;			//8000为毫秒，可修改数值
	/*继电器关闭标志位*/
	uint16_t Close_Elect;
	
	while(1)
	{
		/******感应模式开启******/									/******多次检测是否申请进入定时供水模式，只为提高进入定时供水模式的灵敏度******/
		
		/*有一个红外感应到目标，即可开启供水*/
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		temp = res_get();
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		if(temp == 1 || temp == 2 || temp == 3 || temp == 4)
		{
			HCSR1 = 0;
			HCSR2 = 0;
			HCSR3 = 0;
			HCSR4 = 0;
			Close_Elect = 0;
			Elect_open();
		}
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		/*一号传感器未感应到目标，设置无感应标志位赋值*/
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC1) == 0)
		{
			HCSR1 = 1;
		}
		
		/*有一个红外感应到目标，即可开启供水*/
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		temp = res_get();
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		if(temp == 1 || temp == 2 || temp == 3 || temp == 4)
		{
			HCSR1 = 0;
			HCSR2 = 0;
			HCSR3 = 0;
			HCSR4 = 0;
			Close_Elect = 0;
			Elect_open();
		}
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		/*二号传感器未感应到目标，设置无感应标志位赋值*/
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC2) == 0)
		{
			HCSR2 = 2;
		}
		
		/*有一个红外感应到目标，即可开启供水*/
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		temp = res_get();
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		if(temp == 1 || temp == 2 || temp == 3 || temp == 4)
		{
			HCSR1 = 0;
			HCSR2 = 0;
			HCSR3 = 0;
			HCSR4 = 0;
			Close_Elect = 0;
			Elect_open();
		}
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		/*三号传感器未感应到目标，设置无感应标志位赋值*/
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC3) == 0)
		{
			HCSR3 = 3;
		}	
		
		/*有一个红外感应到目标，即可开启供水*/
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		temp = res_get();
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		if(temp == 1 || temp == 2 || temp == 3 || temp == 4)
		{
			HCSR1 = 0;
			HCSR2 = 0;
			HCSR3 = 0;
			HCSR4 = 0;
			Close_Elect = 0;
			Elect_open();
		}
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		/*四号传感器未感应到目标，设置无感应标志位赋值*/
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC4) == 0)
		{
			HCSR4 = 4;
		}
		
		/*有一个红外感应到目标，即可开启供水*/
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		temp = res_get();
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		if(temp == 1 || temp == 2 || temp == 3 || temp == 4)
		{
			HCSR1 = 0;
			HCSR2 = 0;
			HCSR3 = 0;
			HCSR4 = 0;
			Close_Elect = 0;
			Elect_open();
		}
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
		
		/** 介		绍：四个传感器均未感应到目标，关闭供水
			* 注    意：因为传感器的问题，目标未移动也会判断为无目标，所以下面设置感应到目标会
			* 					持续供水8秒（可修改数值），且在持续供水期间，若目标移动，会自动保持供水
			* 					不间断，但真正无目标的情况下，也会供水8秒后再关闭供水
			* 					
		  */
		if(HCSR1 == 1 && HCSR2 == 2 && HCSR3 == 3 && HCSR4 == 4)
		{
			temp = 0;
			i = 1;
			Close_Elect = 1;
			/*供水8秒，修改Induction_SetTime值可修改供水时间*/
			while(i <= Induction_SetTime)
			{
				Fixed_time_Mode();		//----------------------------------------->检测是否申请进入定时供水模式
				Delay_ms(1);
				/*有一个红外感应到目标，即可开启供水*/
				Fixed_time_Mode();		//----------------------------------------->检测是否申请进入定时供水模式
				temp = res_get();
				Fixed_time_Mode();		//----------------------------------------->检测是否申请进入定时供水模式
				if(temp == 1 || temp == 2 || temp == 3 || temp == 4)
				{
					HCSR1 = 0;
					HCSR2 = 0;
					HCSR3 = 0;
					HCSR4 = 0;
					Close_Elect = 0;
					break;
				}
				Fixed_time_Mode();		//----------------------------------------->检测是否申请进入定时供水模式
				i++;
			}
			/*真正无目标，关闭供水*/
			if(Close_Elect == 1)
			{
				Elect_close();
			}
			/*有一个红外感应到目标，即可开启供水*/
			Fixed_time_Mode();			//----------------------------------------->检测是否申请进入定时供水模式
			temp = res_get();
			Fixed_time_Mode();			//----------------------------------------->检测是否申请进入定时供水模式
			if(temp == 1 || temp == 2 || temp == 3 || temp == 4)
			{
				HCSR1 = 0;
				HCSR2 = 0;
				HCSR3 = 0;
				HCSR4 = 0;
				Close_Elect = 0;
				Elect_open();
			}
		}
		Fixed_time_Mode();				//----------------------------------------->检测是否申请进入定时供水模式
	}
}

