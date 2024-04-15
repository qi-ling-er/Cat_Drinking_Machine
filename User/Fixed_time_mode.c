#include "stm32f10x.h"                  // Device header
#include "Key.h"        
#include "FM.h"        
#include "Elect.h"        
#include "Delay.h"     


void Fixed_time_Mode(void)
{

		//接收键码标志
		uint8_t KeyNumber = 1;	
		//判断是否一次退出
		uint16_t z = 0;

			
		
//定时出水模式（按键）
		//开启定时模式
		if(KeyNumber == Key_get())
		{
			//设置标志
			KeyNumber = 0;
			uint8_t clo = 1;
			
			
			uint16_t j;
			uint8_t set_outwater_time = 1;		//--->设置每次出水持续多少分钟（可修改）
			uint16_t x;
			
			
			uint16_t i;
			uint8_t set_interval_min = 60;		//--->设置每间隔多少分钟出水（可修改）
			uint16_t y;

			//一次蜂鸣
			FM_sound_one();
			while(KeyNumber == 0)
			{
				//开启供水
				Elect_open();
				j = 1;
				//供水延时一分钟（每次供水持续时间）
				while(j <= set_outwater_time)
				{
					x = 1;
					while(x <=  60000)
					{
						//----------------------------
							if(clo == Key_get())					//--------------->退出定时模式（4次退出提高退出灵敏度）
							{
								KeyNumber = 1;
								FM_sound_two();
								Elect_close();
								//用x跳出内循环 
								x = 60007;
								//用j跳出外循环
								j = 700;
								//用z确定是否一次退出
								z = 700;
							}	
						//----------------------------
						Delay_ms(1);
						//----------------------------
							if(clo == Key_get())					//--------------->退出定时模式
							{
								KeyNumber = 1;
								FM_sound_two();
								Elect_close();
								//用x跳出内循环 
								x = 60007;
								//用j跳出外循环
								j = 700;
								//用z确定是否一次退出
								z = 700;
							}	
						//----------------------------
						x++;
					}
					j++;
				}
				//关闭供水
				Elect_close();
				i = 1;
				//判断是否已经一次退出
				if(z == 700)
				{
					i = 70;
				}
				//关闭供水延时60分钟（间隔供水时间）
				while(i <= set_interval_min)
				{
					y = 1;
					while(y <=  60000)
					{
						//----------------------------
							if(clo == Key_get())					//--------------->退出定时模式
							{
								KeyNumber = 1;
								FM_sound_two();
								Elect_close();
								//用y跳出内循环
								y = 60007;
								//用i跳出外循环
								i = 700;
							}	
						//----------------------------
						Delay_ms(1);
						//----------------------------
							if(clo == Key_get())					//--------------->退出定时模式
							{
								KeyNumber = 1;
								FM_sound_two();
								Elect_close();
								//用y跳出内循环
								y = 60007;
								//用i跳出外循环
								i = 700;
							}	
						//----------------------------
						y++;
					}
					i++;
				}
			}
		}
		
		
		

}
