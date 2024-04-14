#include "stm32f10x.h"                  // Device header
#include "Delay.h"


//�����������ã����޸����ţ��������л�ģʽ��
#define    GPIO_Pin_KEY    GPIO_Pin_6			
#define    GPIO_APB2_SER   RCC_APB2Periph_GPIOA	
#define    GPIO_SER   	   GPIOA	




//������ʼ��
void Key_init(void)
{
	//APB2����GPIOAʱ������
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);   
	
	
	//���ڽṹ��
	GPIO_InitTypeDef GPIO_InitStructure;    
	
	
	//������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;       // --->�ߵ�ƽ����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_KEY;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	//��ʼ��GPIOA
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
}




//���뷵��
uint8_t Key_get(void)
{
	uint8_t keynumber = 0;
	
	if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_KEY) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_KEY) == 0)
		Delay_ms(20);
		keynumber = 1;
	}
	return keynumber;
}


