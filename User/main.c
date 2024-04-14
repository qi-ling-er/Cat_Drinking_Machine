#include "stm32f10x.h"                  // Device header
#include "Delay.h" 
#include "Key.h"
#include "HCSR501.h"
#include "FM.h"
#include "Elect.h"
#include "Fixed_time_mode.h"



//同HCSR501的GPIO引脚配置相同（若修改引脚,一定要保证 main.c和HCSR501.c GPIO引脚配置相同） 
#define    GPIO_Pin_HC1     	GPIO_Pin_1	
#define    GPIO_Pin_HC2 			GPIO_Pin_2	
#define    GPIO_Pin_HC3     	GPIO_Pin_3	
#define    GPIO_Pin_HC4 			GPIO_Pin_4	
#define    GPIO_SER   	  		GPIOA	




int main(void)
{
	
	
	
	//按键初始化
	Key_init();
	//HCSR501*4 初始化
	SR501_init();
	//继电器初始化
	Elect_init();
	//蜂鸣器初始化
	FM_init();


	
	//接收HCSR501中断标志
	uint16_t temp = 0;

	//接收无感应参数
	uint8_t HCSR1,HCSR2,HCSR3,HCSR4;
	
	
	
	
	
	while(1)
	{
		
		
		
		
		
		Fixed_time_Mode();				//----------------------------------------->定时出水模式（八个定时出水提高灵敏度）
//感应模式
		//感应到 开启供水
		temp = res_get();
		Fixed_time_Mode();				//----------------------------------------->定时出水模式
		if(temp == 1 || temp == 2 || temp == 3 || temp == 4)
		{
			HCSR1 = 0;
			HCSR2 = 0;
			HCSR3 = 0;
			HCSR4 = 0;
			Elect_open();
		
		}
		Fixed_time_Mode();				//----------------------------------------->定时出水模式
		
		//未感应到 关闭供水
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC1) == 0)
		{
			HCSR1 = 1;
			
		}
		Fixed_time_Mode();				//----------------------------------------->定时出水模式
		
		
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC2) == 0)
		{
			HCSR2 = 2;
			
		}
		Fixed_time_Mode();				//----------------------------------------->定时出水模式

		
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC3) == 0)
		{
			HCSR3 = 3;
			
		}		
		Fixed_time_Mode();				//----------------------------------------->定时出水模式
		
		
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC4) == 0)
		{
			HCSR4 = 4;
			
		}
		Fixed_time_Mode();				//----------------------------------------->定时出水模式
		
		
		if(HCSR1 == 1 && HCSR2 == 2 && HCSR3 == 3 && HCSR4 == 4)
		{
			temp = 0;
			Elect_close();
		
		}
		Fixed_time_Mode();				//----------------------------------------->定时出水模式
		
		
		
		

		
		
		
	}

}

