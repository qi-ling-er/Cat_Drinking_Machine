#include "stm32f10x.h"                  // Device header



/*GPIO引脚配置（4个红外出传感）*/
#define    GPIO_Pin_HC1     	GPIO_Pin_1	
#define    GPIO_Pin_HC2 			GPIO_Pin_2	
#define    GPIO_Pin_HC3     	GPIO_Pin_3	
#define    GPIO_Pin_HC4 			GPIO_Pin_4
#define    GPIO_APB2_SER   		RCC_APB2Periph_GPIOA	
#define    GPIO_Port_SER   		GPIO_PortSourceGPIOA	
#define    GPIO_SER   	   		GPIOA	

/*AFIO线配置*/
#define    GPIO_Pin_AFIO1     	GPIO_PinSource1	
#define    GPIO_Pin_AFIO2 			GPIO_PinSource2	
#define    GPIO_Pin_AFIO3     	GPIO_PinSource3	
#define    GPIO_Pin_AFIO4 			GPIO_PinSource4

/*EXTI中断线配置*/
#define    EXTI_L1   	 		EXTI_Line1	
#define    EXTI_L2 				EXTI_Line2	
#define    EXTI_L3    		EXTI_Line3	
#define    EXTI_L4 				EXTI_Line4

/*NVIC线成员配置*/
#define    EXTI_IR1     	EXTI1_IRQn	
#define    EXTI_IR2 			EXTI2_IRQn	
#define    EXTI_IR3     	EXTI3_IRQn	
#define    EXTI_IR4 			EXTI4_IRQn	

/**
	* EXTI0_IRQn					包含0引脚
  * EXTI1_IRQn					包含1引脚
  * EXTI2_IRQn					包含2引脚
	* EXTI3_IRQn					包含3引脚
	* EXTI4_IRQn					包含4引脚
	* EXTI9_5_IRQn				包含5 - 9引脚
	* EXTI15_10_IRQn			包含10 - 15引脚
	*/
	
/*全局变量，返回中断标志*/
int16_t res;

/**
  * 函    数：红外传感初始化
  * 参    数：无
  * 返 回 值：无
  */
void SR501_init(void)
{
	/*开启GPIOA时钟输入*/
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);  
	
	/*开启AFIO时钟输入*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);   
	
	/*GPIOA初始化*/
	GPIO_InitTypeDef GPIO_InitStructure; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;       //--->低电平输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_HC1|GPIO_Pin_HC2|GPIO_Pin_HC3|GPIO_Pin_HC4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
	
	/*AFIO初始化*/
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO1);
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO2);
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO3);
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO4);
	
	/*EXTII初始化*/
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line = EXTI_L1|EXTI_L2|EXTI_L3|EXTI_L4;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStruct);
	
	/*NVIC分组*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	/*NVIC结构体*/
	NVIC_InitTypeDef NVIC_InitStruct;
	
	/*NVIC 1线初始化*/
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStruct);
	
	/*NVIC 2线初始化*/
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR2;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
	
	/*NVIC 3线初始化*/
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR3;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	/*NVIC 4线初始化*/
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR4;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
	NVIC_Init(&NVIC_InitStruct);
}

/**
  * 函    数：中断标志获取
  * 参    数：无
	* 返 回 值：中断标志
  */
int16_t res_get(void)
{
	int16_t tep;
	tep = res;
	res = 0;
	return tep;

}

/**
	* EXTI0_IRQHandler    		包含EXTI_Line0
	* EXTI1_IRQHandler				包含EXTI_Line1
	* EXTI2_IRQHandler				包含EXTI_Line2
	* EXTI3_IRQHandler				包含EXTI_Line3
	* EXTI4_IRQHandler				包含EXTI_Line4
	* EXTI9_5_IRQHandler			包含EXTI_Line5 - EXTI_Line9
	* EXTI15_10_IRQHandler		包含EXTI_Line10 - EXTI_Line15
	*/

/**
  * 函    数：中断函数1
  * 参    数：无
  * 返 回 值：无
  */
void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1) == SET)
	{
		res = 1;
	}
	EXTI_ClearITPendingBit(EXTI_Line1);
}

/**
  * 函    数：中断函数2
  * 参    数：无
  * 返 回 值：无
  */
void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2) == SET)
		{
			res = 2;
		}
		EXTI_ClearITPendingBit(EXTI_Line2);
}

/**
  * 函    数：中断函数3
  * 参    数：无
  * 返 回 值：无
  */
void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3) == SET)
		{
			res = 3;
		}
		EXTI_ClearITPendingBit(EXTI_Line3);
}

/**
  * 函    数：中断函数4
  * 参    数：无
  * 返 回 值：无
  */
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4) == SET)
		{
		res = 4;
		}
		EXTI_ClearITPendingBit(EXTI_Line4);
}
