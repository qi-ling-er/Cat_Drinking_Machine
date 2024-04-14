#include "stm32f10x.h"                  // Device header
#include "Delay.h"


//按键引脚配置（可修改引脚）【按键切换模式】
#define    GPIO_Pin_KEY    GPIO_Pin_6			
#define    GPIO_APB2_SER   RCC_APB2Periph_GPIOA	
#define    GPIO_SER   	   GPIOA	




//按键初始化
void Key_init(void)
{
	//APB2总线GPIOA时钟配置
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);   
	
	
	//定于结构体
	GPIO_InitTypeDef GPIO_InitStructure;    
	
	
	//传属性
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;       // --->高电平输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_KEY;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	//初始化GPIOA
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
}




//键码返回
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


