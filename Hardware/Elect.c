#include "stm32f10x.h"                  // Device header
#include "Delay.h" 



//模块引脚配置（可修改引脚）【继电器】
#define    GPIO_Pin_ELECT     GPIO_Pin_5
#define    GPIO_APB2_SER   	  RCC_APB2Periph_GPIOA	
#define    GPIO_SER   	   	  GPIOA	


//继电器初始化
void Elect_init(void)
{
	//APB2总线GPIOA时钟配置
	RCC_APB2PeriphClockCmd(GPIO_APB2_SER,ENABLE);  

	
	//定于结构体GPIO
	GPIO_InitTypeDef GPIO_InitStructure; 
	//传属性
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //--->推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_ELECT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	
	
	//初始化GPIOA
	GPIO_Init(GPIO_SER,&GPIO_InitStructure);
}



//开启继电器（高电平开启）
void Elect_open(void)
{
	GPIO_SetBits(GPIO_SER,GPIO_Pin_ELECT);

}


//关闭继电器（低电平关闭）
void Elect_close(void)
{
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_ELECT);

}

//开启继电器5秒
void Elect_open5s(void)
{
	GPIO_SetBits(GPIO_SER,GPIO_Pin_ELECT);
	Delay_s(4);
	GPIO_ResetBits(GPIO_SER,GPIO_Pin_ELECT);

}


