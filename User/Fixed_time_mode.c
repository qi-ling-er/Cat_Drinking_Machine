#include "stm32f10x.h"                  // Device header
#include "Key.h"        
#include "FM.h"        
#include "Elect.h"        
#include "Delay.h"     

/**
  * 函    数：定时供水模式
  * 参    数：无
	* 返 回 值：无
	* 注		意：可修改每次供水时间，供水间隔时间
  */
void Fixed_time_Mode(void)
{
	/*判断接收键码标志*/
	uint8_t KeyNumber = 1;	

	/******定时供水开启******/
	if(KeyNumber == Key_get())
	{
		/*判断是否供水期间申请进入感应模式的标志定义*/
		uint16_t z;
		/*复用KeyNumber进入感应模式标志，现默认0为定时模式*/
		KeyNumber = 0;
		uint8_t clo = 1;
		/*每次供水时间的设定*/
		uint16_t j;
		uint8_t set_outwater_time = 1;		//--->1为分钟，可修改数值
		uint16_t x;
		/*供水间隔时间的设定*/
		uint16_t i;
		uint8_t set_interval_min = 60;		//--->60为分钟，可修改数值
		uint16_t y;
		
		/*蜂鸣一声，正式进入定时供水*/
		FM_sound_one();
		while(KeyNumber == 0)
		{
			/*供水一分钟开始（每次供水时间），开启继电器*/
			Elect_open();
			j = 1;
			z = 0;
			while(j <= set_outwater_time)
			{
				x = 1;
				while(x <=  60000)
				{
					/*******检测是否申请进入感应模式*******/
					if(clo == Key_get())
					{
						/*复用KeyNumber进入感应模式标志赋值为1，进入感应模式*/
						KeyNumber = 1;
						FM_sound_two();
						Elect_close();
						/*跳出内循环标志*/
						x = 60007;
						/*跳出外循环标志*/
						j = 700;
						/*供水期间申请进入感应模式的标志赋值*/
						z = 700;
					}	
					/**************************************/
					Delay_ms(1);
					/*******检测是否申请进入感应模式*******/
					if(clo == Key_get())
					{
						/*复用KeyNumber进入感应模式标志赋值为1，进入感应模式*/
						KeyNumber = 1;
						FM_sound_two();
						Elect_close();
						/*跳出内循环标志*/
						x = 60007;
						/*跳出外循环标志*/
						j = 700;
						/*供水期间申请进入感应模式的标志赋值*/
						z = 700;
					}	
					/**************************************/
					x++;
				}
				j++;
			}
			/*供水一分钟结束，关闭继电器*/
			Elect_close();
			i = 1;
			/*是否供水期间申请进入感应模式*/
			if(z == 700)
			{
				i = 7000;
			}
			/*间隔供水开始，即继电器关闭*/
			while(i <= set_interval_min)
			{
				y = 1;
				while(y <=  60000)
				{		
					/*******检测是否申请进入感应模式*******/
					if(clo == Key_get())
					{
						/*复用KeyNumber进入感应模式标志赋值为1，进入感应模式*/
						KeyNumber = 1;
						FM_sound_two();
						Elect_close();
						/*跳出内循环标志*/
						y = 60007;
						/*跳出外循环标志*/
						i = 7000;
					}	
					/**************************************/
					Delay_ms(1);
					/*******检测是否申请进入感应模式*******/
					if(clo == Key_get())
					{
						/*复用KeyNumber进入感应模式标志赋值为1，进入感应模式*/
						KeyNumber = 1;
						FM_sound_two();
						Elect_close();
						/*跳出内循环标志*/
						y = 60007;
						/*跳出外循环标志*/
						i = 7000;
					}	
					/**************************************/
					y++;
				}		
				i++;
			}
		}
	}
}
