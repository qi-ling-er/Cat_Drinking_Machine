#include "stm32f10x.h"                  // Device header
#include "Key.h"        
#include "FM.h"        
#include "Elect.h"        
#include "Delay.h"     


void Fixed_time_Mode(void)
{

		//���ռ����־
		uint8_t KeyNumber = 1;	
		//�ж��Ƿ�һ���˳�
		uint16_t z = 0;

			
		
//��ʱ��ˮģʽ��������
		//������ʱģʽ
		if(KeyNumber == Key_get())
		{
			//���ñ�־
			KeyNumber = 0;
			uint8_t clo = 1;
			
			
			uint16_t j;
			uint8_t set_outwater_time = 1;		//--->����ÿ�γ�ˮ�������ٷ��ӣ����޸ģ�
			uint16_t x;
			
			
			uint16_t i;
			uint8_t set_interval_min = 60;		//--->����ÿ������ٷ��ӳ�ˮ�����޸ģ�
			uint16_t y;

			//һ�η���
			FM_sound_one();
			while(KeyNumber == 0)
			{
				//������ˮ
				Elect_open();
				j = 1;
				//��ˮ��ʱһ���ӣ�ÿ�ι�ˮ����ʱ�䣩
				while(j <= set_outwater_time)
				{
					x = 1;
					while(x <=  60000)
					{
						//----------------------------
							if(clo == Key_get())					//--------------->�˳���ʱģʽ��4���˳�����˳������ȣ�
							{
								KeyNumber = 1;
								FM_sound_two();
								Elect_close();
								//��x������ѭ�� 
								x = 60007;
								//��j������ѭ��
								j = 700;
								//��zȷ���Ƿ�һ���˳�
								z = 700;
							}	
						//----------------------------
						Delay_ms(1);
						//----------------------------
							if(clo == Key_get())					//--------------->�˳���ʱģʽ
							{
								KeyNumber = 1;
								FM_sound_two();
								Elect_close();
								//��x������ѭ�� 
								x = 60007;
								//��j������ѭ��
								j = 700;
								//��zȷ���Ƿ�һ���˳�
								z = 700;
							}	
						//----------------------------
						x++;
					}
					j++;
				}
				//�رչ�ˮ
				Elect_close();
				i = 1;
				//�ж��Ƿ��Ѿ�һ���˳�
				if(z == 700)
				{
					i = 70;
				}
				//�رչ�ˮ��ʱ60���ӣ������ˮʱ�䣩
				while(i <= set_interval_min)
				{
					y = 1;
					while(y <=  60000)
					{
						//----------------------------
							if(clo == Key_get())					//--------------->�˳���ʱģʽ
							{
								KeyNumber = 1;
								FM_sound_two();
								Elect_close();
								//��y������ѭ��
								y = 60007;
								//��i������ѭ��
								i = 700;
							}	
						//----------------------------
						Delay_ms(1);
						//----------------------------
							if(clo == Key_get())					//--------------->�˳���ʱģʽ
							{
								KeyNumber = 1;
								FM_sound_two();
								Elect_close();
								//��y������ѭ��
								y = 60007;
								//��i������ѭ��
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
