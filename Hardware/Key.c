#include "stm32f10x.h"                  // Device header
#include "Delay.h"


/*按键引脚配置*/
#define    GPIO_Pin_KEY    GPIO_Pin_6			
#define    GPIO_APB2_SER   RCC_APB2Periph_GPIOA	
#define    GPIO_SER   	   GPIOA	

/**
  * 函    数：按键初始化
  * 参    数：无
  * 返 回 值：无
  */
void Key_init(void)
{
	/*开启GPIOA时钟输入*/
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);  
	
	/*GPIOA初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;    
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;       // --->高电平输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_KEY;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
}

/**
  * 函    数：按键获取键码
  * 参    数：无
  * 返 回 值：按下按键的键码值，范围：1，返回0代表没有按键按下
  * 注    意：此函数长按3秒能返回键码
  */
uint8_t Key_get(void)
{
	uint8_t keynumber = 0;
	
	if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_KEY) == 0)
	{
		Delay_s(1);
		if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_KEY) == 0)
		{
			Delay_s(1);
			if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_KEY) == 0)
			{
				Delay_s(1);
				if(GPIO_ReadInputDataBit(GPIO_SER,GPIO_Pin_KEY) == 0)
				{
						keynumber = 1;
				}
			}
		}
	}
	return keynumber;
}


