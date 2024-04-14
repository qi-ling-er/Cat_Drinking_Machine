#include "stm32f10x.h"                  // Device header
#include "Key.h"        
#include "FM.h"        
#include "Elect.h"        
#include "Delay.h"     


void Fixed_time_Mode(void)
{

		//���ռ����־
		uint8_t KeyNumber = 1;	

			
		
//��ʱ��ˮģʽ��������
		//������ʱģʽ
		if(KeyNumber == Key_get())
		{
			KeyNumber = 0;
			uint64_t clo = 1;
			FM_sound_one();
			while(KeyNumber == 0)
			{
			//----------------------------
				if(clo == Key_get())					//--------------->�˳���ʱģʽ������˳���Ϊ����������ȣ�
				{
					KeyNumber = 1;
					FM_sound_two();
					Elect_close();
					
				}	
			//----------------------------
				Elect_open();
			//----------------------------
				if(clo == Key_get())					//--------------->�˳���ʱģʽ
				{
					KeyNumber = 1;
					FM_sound_two();
					Elect_close();
					
				}	
			//----------------------------
				uint8_t j = 1;
				uint8_t set_outwater_time = 1;		//--->����ÿ�γ�ˮ�������ٷ��ӣ����޸ģ�
				while(j <= set_outwater_time)
				{
					Delay_s(60);
				}
			//----------------------------
				if(clo == Key_get())					//--------------->�˳���ʱģʽ
				{
					KeyNumber = 1;
					FM_sound_two();
					Elect_close();
					
				}	
			//----------------------------
				Elect_close();
			//----------------------------
				if(clo == Key_get())					//--------------->�˳���ʱģʽ
				{
					KeyNumber = 1;
					FM_sound_two();
					Elect_close();
					
				}	
			//----------------------------
				uint8_t i = 1;
				uint8_t set_interval_min = 60;		//--->����ÿ������ٷ��ӳ�ˮ�����޸ģ�
				while(i <= set_interval_min)
				{
					Delay_s(60);
				}
			//----------------------------
				if(clo == Key_get())					//--------------->�˳���ʱģʽ
				{
					KeyNumber = 1;
					FM_sound_two();
					Elect_close();
					
				}
			//----------------------------
			}
		}
		
		
		

}
