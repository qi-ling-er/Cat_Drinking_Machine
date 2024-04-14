#include "stm32f10x.h"                  // Device header
#include "Key.h"        
#include "FM.h"        
#include "Elect.h"        
#include "Delay.h"     


void Fixed_time_Mode(void)
{

		//接收键码标志
		uint8_t KeyNumber = 1;	

			
		
//定时出水模式（按键）
		//开启定时模式
		if(KeyNumber == Key_get())
		{
			KeyNumber = 0;
			uint64_t clo = 1;
			FM_sound_one();
			while(KeyNumber == 0)
			{
			//----------------------------
				if(clo == Key_get())					//--------------->退出定时模式（五个退出是为了提高灵敏度）
				{
					KeyNumber = 1;
					FM_sound_two();
					Elect_close();
					
				}	
			//----------------------------
				Elect_open();
			//----------------------------
				if(clo == Key_get())					//--------------->退出定时模式
				{
					KeyNumber = 1;
					FM_sound_two();
					Elect_close();
					
				}	
			//----------------------------
				uint8_t j = 1;
				uint8_t set_outwater_time = 1;		//--->设置每次出水持续多少分钟（可修改）
				while(j <= set_outwater_time)
				{
					Delay_s(60);
				}
			//----------------------------
				if(clo == Key_get())					//--------------->退出定时模式
				{
					KeyNumber = 1;
					FM_sound_two();
					Elect_close();
					
				}	
			//----------------------------
				Elect_close();
			//----------------------------
				if(clo == Key_get())					//--------------->退出定时模式
				{
					KeyNumber = 1;
					FM_sound_two();
					Elect_close();
					
				}	
			//----------------------------
				uint8_t i = 1;
				uint8_t set_interval_min = 60;		//--->设置每间隔多少分钟出水（可修改）
				while(i <= set_interval_min)
				{
					Delay_s(60);
				}
			//----------------------------
				if(clo == Key_get())					//--------------->退出定时模式
				{
					KeyNumber = 1;
					FM_sound_two();
					Elect_close();
					
				}
			//----------------------------
			}
		}
		
		
		

}
