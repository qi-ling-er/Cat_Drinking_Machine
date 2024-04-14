#include "stm32f10x.h"                  // Device header
#include "Delay.h" 
#include "Key.h"
#include "HCSR501.h"
#include "FM.h"
#include "Elect.h"
#include "Fixed_time_mode.h"



//ͬHCSR501��GPIO����������ͬ�����޸�����,һ��Ҫ��֤ main.c��HCSR501.c GPIO����������ͬ�� 
#define    GPIO_Pin_HC1     	GPIO_Pin_1	
#define    GPIO_Pin_HC2 			GPIO_Pin_2	
#define    GPIO_Pin_HC3     	GPIO_Pin_3	
#define    GPIO_Pin_HC4 			GPIO_Pin_4	
#define    GPIO_SER   	  		GPIOA	




int main(void)
{
	
	
	
	//������ʼ��
	Key_init();
	//HCSR501*4 ��ʼ��
	SR501_init();
	//�̵�����ʼ��
	Elect_init();
	//��������ʼ��
	FM_init();


	
	//����HCSR501�жϱ�־
	uint16_t temp = 0;

	//�����޸�Ӧ����
	uint8_t HCSR1,HCSR2,HCSR3,HCSR4;
	
	
	
	
	
	while(1)
	{
		
		
		
		
		
		Fixed_time_Mode();				//----------------------------------------->��ʱ��ˮģʽ���˸���ʱ��ˮ��������ȣ�
//��Ӧģʽ
		//��Ӧ�� ������ˮ
		temp = res_get();
		Fixed_time_Mode();				//----------------------------------------->��ʱ��ˮģʽ
		if(temp == 1 || temp == 2 || temp == 3 || temp == 4)
		{
			HCSR1 = 0;
			HCSR2 = 0;
			HCSR3 = 0;
			HCSR4 = 0;
			Elect_open();
		
		}
		Fixed_time_Mode();				//----------------------------------------->��ʱ��ˮģʽ
		
		//δ��Ӧ�� �رչ�ˮ
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC1) == 0)
		{
			HCSR1 = 1;
			
		}
		Fixed_time_Mode();				//----------------------------------------->��ʱ��ˮģʽ
		
		
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC2) == 0)
		{
			HCSR2 = 2;
			
		}
		Fixed_time_Mode();				//----------------------------------------->��ʱ��ˮģʽ

		
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC3) == 0)
		{
			HCSR3 = 3;
			
		}		
		Fixed_time_Mode();				//----------------------------------------->��ʱ��ˮģʽ
		
		
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_HC4) == 0)
		{
			HCSR4 = 4;
			
		}
		Fixed_time_Mode();				//----------------------------------------->��ʱ��ˮģʽ
		
		
		if(HCSR1 == 1 && HCSR2 == 2 && HCSR3 == 3 && HCSR4 == 4)
		{
			temp = 0;
			Elect_close();
		
		}
		Fixed_time_Mode();				//----------------------------------------->��ʱ��ˮģʽ
		
		
		
		

		
		
		
	}

}

