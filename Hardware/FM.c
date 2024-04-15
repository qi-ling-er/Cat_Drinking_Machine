#include "stm32f10x.h"                  // Device header
#include "Delay.h" 



//ģ���������ã����޸����ţ�����������
#define    GPIO_Pin_Buzzer    GPIO_Pin_7	
#define    GPIO_APB2_SER   	  RCC_APB2Periph_GPIOA	
#define    GPIO_SER   	   	  GPIOA	




void FM_init(void)
{
	//APB2����GPIOAʱ������
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);  
	
	
	//���ڽṹ��GPIO
	GPIO_InitTypeDef GPIO_InitStructure; 
	//������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //--->�������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_Buzzer;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	
	
	//��ʼ��GPIOA
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
	
	
	//����Ĭ�Ϸ������ߵ�ƽ
	GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);

}


//������
void FM_sound_continue(void)
{
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);

}



//��ʽ��
void FM_sound_break(void)
{
	while(1)
	{
			GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);
			Delay_ms(50);
			GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);
			Delay_ms(50);
		//ˮλ���ʱ���������
		//Ҫ�ڴ����if��������ѭ��
	}

}



//�ر���
void FM_sound_close(void)
{
		GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);

}

//����
void FM_sound_one(void)
{
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);
	Delay_ms(50);
	GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);

}

//˫��
void FM_sound_two(void)
{
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);
	Delay_ms(50);
	GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);
	Delay_ms(50);
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);
	Delay_ms(50);
	GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);

}


