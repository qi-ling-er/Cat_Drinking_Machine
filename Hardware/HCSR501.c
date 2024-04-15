#include "stm32f10x.h"                  // Device header



//GPIO引脚配置（可修改引脚）【红外传感器4个】
#define    GPIO_Pin_HC1     	GPIO_Pin_1	
#define    GPIO_Pin_HC2 			GPIO_Pin_2	
#define    GPIO_Pin_HC3     	GPIO_Pin_3	
#define    GPIO_Pin_HC4 			GPIO_Pin_4
#define    GPIO_APB2_SER   		RCC_APB2Periph_GPIOA	
#define    GPIO_Port_SER   		GPIO_PortSourceGPIOA	
#define    GPIO_SER   	   		GPIOA	




//AFIO引脚配置（可修改引脚）【红外传感器4个】
#define    GPIO_Pin_AFIO1     	GPIO_PinSource1	
#define    GPIO_Pin_AFIO2 			GPIO_PinSource2	
#define    GPIO_Pin_AFIO3     	GPIO_PinSource3	
#define    GPIO_Pin_AFIO4 			GPIO_PinSource4




//EXIT中断线配置（可修改引脚）【红外传感器4个】
#define    EXTI_L1   	 		EXTI_Line1	
#define    EXTI_L2 				EXTI_Line2	
#define    EXTI_L3    		EXTI_Line3	
#define    EXTI_L4 				EXTI_Line4	




//NVIC中断源成员配置（可修改引脚）【红外传感器4个】
#define    EXTI_IR1     	EXTI1_IRQn	
#define    EXTI_IR2 			EXTI2_IRQn	
#define    EXTI_IR3     	EXTI3_IRQn	
#define    EXTI_IR4 			EXTI4_IRQn	



/**********************
EXTI0_IRQn					包含0引脚
EXTI1_IRQn					包含1引脚
EXTI2_IRQn					包含2引脚
EXTI3_IRQn					包含3引脚
EXTI4_IRQn					包含4引脚
EXTI9_5_IRQn				包含5 - 9引脚
EXTI15_10_IRQn			包含10 - 15引脚
*********************/


int16_t res;
void SR501_init(void)
{
	//APB2总线GPIOA时钟配置
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);  
	//APB2总线AFIO时钟配置
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);   
	
	
	
	
	//定于结构体GPIO
	GPIO_InitTypeDef GPIO_InitStructure; 
	//传属性
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;       //--->低电平输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_HC1|GPIO_Pin_HC2|GPIO_Pin_HC3|GPIO_Pin_HC4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	
	
	//初始化GPIOA
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
	
	
	
	
	//初始化AFIO针脚选择
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO1);
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO2);
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO3);
	GPIO_EXTILineConfig(GPIO_Port_SER,GPIO_Pin_AFIO4);
	
	
	
	
	//定于结构体EXIT
	EXTI_InitTypeDef EXTI_InitStruct;
	//传属性
	EXTI_InitStruct.EXTI_Line = EXTI_L1|EXTI_L2|EXTI_L3|EXTI_L4;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	
	
	
	//初始化EXIT
	EXTI_Init(&EXTI_InitStruct);
	
	
	//NVIC选组 2 2分
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//NVIC结构体
	NVIC_InitTypeDef NVIC_InitStruct;
	
	
	//传属性1
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	//初始化NVIC1
	NVIC_Init(&NVIC_InitStruct);
	
	//传属性2
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR2;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	//初始化NVIC2
	NVIC_Init(&NVIC_InitStruct);
	
	//传属性3
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR3;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	//初始化NVIC3
	NVIC_Init(&NVIC_InitStruct);
	
	//传属性4
	NVIC_InitStruct.NVIC_IRQChannel = EXTI_IR4;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
	//初始化NVIC4
	NVIC_Init(&NVIC_InitStruct);
}



//获取中断标志
int16_t res_get(void)
{
	int16_t tep;
	tep = res;
	res = 0;
	return tep;

}


/**********************
EXTI0_IRQHandler    		内包含 EXTI_Line0
EXTI1_IRQHandler				内包含 EXTI_Line1
EXTI2_IRQHandler				内包含 EXTI_Line2
EXTI3_IRQHandler				内包含 EXTI_Line3
EXTI4_IRQHandler				内包含 EXTI_Line4
EXTI9_5_IRQHandler			内包含 EXTI_Line5 - EXTI_Line9
EXTI15_10_IRQHandler		内包含 EXTI_Line10 - EXTI_Line15

*********************/




//中断函数EXTI1（红外传感器A1引脚）
void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1) == SET)
	{
		res = 1;
	
	}
	EXTI_ClearITPendingBit(EXTI_Line1);

}




//中断函数EXTI2（红外传感器A2引脚）
void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2) == SET)
		{
			res = 2;
		
		}
		EXTI_ClearITPendingBit(EXTI_Line2);

}





//中断函数EXTI3（红外传感器A3引脚）
void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3) == SET)
		{
			res = 3;
		
		}
		EXTI_ClearITPendingBit(EXTI_Line3);


}





//中断函数EXTI4（红外传感器A4引脚）
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4) == SET)
		{
		res = 4;
		
		}
		EXTI_ClearITPendingBit(EXTI_Line4);


}
