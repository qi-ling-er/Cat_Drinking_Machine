#include "stm32f10x.h"                  // Device header



//GPIO�������ã����޸����ţ������⴫����4����
#define    GPIO_Pin_HC1     	GPIO_Pin_1	
#define    GPIO_Pin_HC2 			GPIO_Pin_2	
#define    GPIO_Pin_HC3     	GPIO_Pin_3	
#define    GPIO_Pin_HC4 			GPIO_Pin_4
#define    GPIO_APB2_SER   		RCC_APB2Periph_GPIOA	
#define    GPIO_Port_SER   		GPIO_PortSourceGPIOA	
#define    GPIO_SER   	   		GPIOA	




//AFIO�������ã����޸����ţ������⴫����4����
#define    GPIO_Pin_AFIO1     	GPIO_PinSource1	
#define    GPIO_Pin_AFIO2 			GPIO_PinSource2	
#define    GPIO_Pin_AFIO3     	GPIO_PinSource3	
#define    GPIO_Pin_AFIO4 			GPIO_PinSource4




//EXIT�ж������ã����޸����ţ������⴫����4����
#define    EXTI_L1   	 		EXTI_Line1	
#define    EXTI_L2 				EXTI_Line2	
#define    EXTI_L3    		EXTI_Line3	
#define    EXTI_L4 				EXTI_Line4	




//NVIC�ж�Դ��Ա���ã����޸����ţ������⴫����4����
#define    EXTI_IR1     	EXTI1_IRQn	
#define    EXTI_IR2 			EXTI2_IRQn	
#define    EXTI_IR3     	EXTI3_IRQn	
#define    EXTI_IR4 			EXTI4_IRQn	



/**********************
EXTI0_IRQn					����0����
EXTI1_IRQn					����1����
EXTI2_IRQn					����2����
EXTI3_IRQn					����3����
EXTI4_IRQn					����4����
EXTI9_5_IRQn				����5 - 9����
EXTI15_10_IRQn			����10 - 15����
*********************/


int16_t res;
void SR501_init(void)
{
	//APB2����GPIOAʱ������
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);  
	//APB2����AFIOʱ������
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);   
	
	
	
	
	//���ڽṹ��GPIO
	GPIO_InitTypeDef GPIO_InitStructure; 
	//������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;       //--->�͵�ƽ����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_HC1|GPIO_Pin_HC2|GPIO_Pin_HC3|GPIO_Pin_HC4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	
	
	//��ʼ��GPIOA
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
	
	
	
	
	//��ʼ��AFIO���ѡ��
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO1);
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO2);
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO3);
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO4);
	
	
	
	
	//���ڽṹ��EXIT
	EXTI_InitTypeDef EXTI_InitStruct;
	//������
	EXTI_InitStruct.EXTI_Line = EXTI_L1|EXTI_L2|EXTI_L3|EXTI_L4;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	
	
	
	//��ʼ��EXIT
	EXTI_Init(&EXTI_InitStruct);
	
	
	//NVICѡ�� 2 2��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//NVIC�ṹ��
	NVIC_InitTypeDef NVIC_InitStruct;
	
	
	//������1
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	//��ʼ��NVIC1
	NVIC_Init(&NVIC_InitStruct);
	
	//������2
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR2;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	//��ʼ��NVIC2
	NVIC_Init(&NVIC_InitStruct);
	
	//������3
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR3;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	//��ʼ��NVIC3
	NVIC_Init(&NVIC_InitStruct);
	
	//������4
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR4;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
	//��ʼ��NVIC4
	NVIC_Init(&NVIC_InitStruct);
}



//��ȡ�жϱ�־
int16_t res_get(void)
{
	int16_t tep;
	tep = res;
	res = 0;
	return tep;

}


/**********************
EXTI0_IRQHandler    		�ڰ��� EXTI_Line0
EXTI1_IRQHandler				�ڰ��� EXTI_Line1
EXTI2_IRQHandler				�ڰ��� EXTI_Line2
EXTI3_IRQHandler				�ڰ��� EXTI_Line3
EXTI4_IRQHandler				�ڰ��� EXTI_Line4
EXTI9_5_IRQHandler			�ڰ��� EXTI_Line5 - EXTI_Line9
EXTI15_10_IRQHandler		�ڰ��� EXTI_Line10 - EXTI_Line15

*********************/




//�жϺ���EXTI1�����⴫����A1���ţ�
void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1) == SET)
	{
		res = 1;
	
	}
	EXTI_ClearITPendingBit(EXTI_Line1);

}




//�жϺ���EXTI2�����⴫����A2���ţ�
void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2) == SET)
		{
			res = 2;
		
		}
		EXTI_ClearITPendingBit(EXTI_Line2);

}





//�жϺ���EXTI3�����⴫����A3���ţ�
void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3) == SET)
		{
			res = 3;
		
		}
		EXTI_ClearITPendingBit(EXTI_Line3);


}





//�жϺ���EXTI4�����⴫����A4���ţ�
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4) == SET)
		{
		res = 4;
		
		}
		EXTI_ClearITPendingBit(EXTI_Line4);


}
