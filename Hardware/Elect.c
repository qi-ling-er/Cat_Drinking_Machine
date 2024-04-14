#include "stm32f10x.h"                  // Device header
#include "Delay.h" 



//ģ���������ã����޸����ţ����̵�����
#define    GPIO_Pin_ELECT     GPIO_Pin_5
#define    GPIO_APB2_SER   	  RCC_APB2Periph_GPIOA	
#define    GPIO_SER   	   	  GPIOA	


//�̵�����ʼ��
void Elect_init(void)
{
	//APB2����GPIOAʱ������
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);  

	
	//���ڽṹ��GPIO
	GPIO_InitTypeDef GPIO_InitStructure; 
	//������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //--->�������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_ELECT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	
	
	//��ʼ��GPIOA
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
}



//�����̵������ߵ�ƽ������
void Elect_open(void)
{
	GPIO_SetBits(GPIO_SER,GPIO_Pin_ELECT);

}


//�رռ̵������͵�ƽ�رգ�
void Elect_close(void)
{
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_ELECT);

}

//�����̵���5��
void Elect_open5s(void)
{
	GPIO_SetBits(GPIO_SER,GPIO_Pin_ELECT);
	Delay_s(4);
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_ELECT);

}


