#include "stm32f10x.h"                  // Device header
#include "Delay.h" 


/*蜂鸣器引脚配置*/
#define    GPIO_Pin_Buzzer    GPIO_Pin_7	
#define    GPIO_APB2_SER   	  RCC_APB2Periph_GPIOA	
#define    GPIO_SER   	   	  GPIOA	

/**
  * 函    数：蜂鸣器初始化
  * 参    数：无
  * 返 回 值：无
  */
void FM_init(void)
{
	/*开启GPIOA时钟输入*/
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);  

	/*GPIOA初始化*/
	GPIO_InitTypeDef GPIO_InitStructure; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //--->推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_Buzzer;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
	
	/*上电默认蜂鸣器关闭*/
	GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);
}

/**
  * 函    数：蜂鸣器连续鸣
  * 参    数：无
  * 返 回 值：无
  */
void FM_sound_continue(void)
{
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);
}

/**
  * 函    数：蜂鸣器断式鸣
  * 参    数：无
  * 返 回 值：无
  */
void FM_sound_break(void)
{
	while(1)
	{
			GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);
			Delay_ms(50);
			GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);
			Delay_ms(50);
	}
}

/**
  * 函    数：蜂鸣器关闭
  * 参    数：无
  * 返 回 值：无
  */
void FM_sound_close(void)
{
		GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);
}

/**
  * 函    数：蜂鸣器鸣一声
  * 参    数：无
  * 返 回 值：无
  */
void FM_sound_one(void)
{
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);
	Delay_ms(50);
	GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);
}

/**
  * 函    数：蜂鸣器鸣两声
  * 参    数：无
  * 返 回 值：无
  */
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
