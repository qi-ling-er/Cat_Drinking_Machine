#include "stm32f10x.h"                  // Device header
#include "Delay.h" 



//模块引脚配置（可修改引脚）【蜂鸣器】
#define    GPIO_Pin_Buzzer    GPIO_Pin_7	
#define    GPIO_APB2_SER   	  RCC_APB2Periph_GPIOA	
#define    GPIO_SER   	   	  GPIOA	




void FM_init(void)
{
	//APB2总线GPIOA时钟配置
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);  
	
	
	//定于结构体GPIO
	GPIO_InitTypeDef GPIO_InitStructure; 
	//传属性
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //--->推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_Buzzer;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	
	
	//初始化GPIOA
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
	
	
	//设置默认蜂鸣器高电平
	GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);

}


//连续音
void FM_sound_continue(void)
{
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);

}



//断式音
void FM_sound_break(void)
{
	while(1)
	{
			GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);
			Delay_ms(50);
			GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);
			Delay_ms(50);
		//水位监测时用这个函数
		//要在此添加if，以跳出循环
	}

}



//关闭音
void FM_sound_close(void)
{
		GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);

}

//单音
void FM_sound_one(void)
{
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_Buzzer);
	Delay_ms(50);
	GPIO_SetBits(GPIO_SER,GPIO_Pin_Buzzer);

}

//双音
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


