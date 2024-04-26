#include "stm32f10x.h"                  // Device header
#include "Delay.h" 


/*蜂鸣器引脚配置*/
#define    GPIO_Pin_ELECT     GPIO_Pin_5
#define    GPIO_APB2_SER   	  RCC_APB2Periph_GPIOA	
#define    GPIO_SER   	   	  GPIOA	

/**
  * 函    数：继电器初始化
  * 参    数：无
  * 返 回 值：无
  */
void Elect_init(void)
{
	/*开启GPIOA时钟输入*/
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);  

	/*GPIOA初始化*/
	GPIO_InitTypeDef GPIO_InitStructure; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //--->推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_ELECT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
}

/**
  * 函    数：继电器开启
  * 参    数：无
  * 返 回 值：无
  */
void Elect_open(void)
{
	GPIO_SetBits(GPIO_SER,GPIO_Pin_ELECT);
}

/**
  * 函    数：继电器关闭
  * 参    数：无
  * 返 回 值：无
  */
void Elect_close(void)
{
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_ELECT);
}

/**
  * 函    数：继电器开启两秒
  * 参    数：无
  * 返 回 值：无
  */
void Elect_open2s(void)
{
	GPIO_SetBits(GPIO_SER,GPIO_Pin_ELECT);
	Delay_s(2);
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_ELECT);
}


