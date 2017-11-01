/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
/**============================================================================
* @FileName    : My_LCD.h
* @Description : LCD12864自用显示程序
* @Date        : 2016/3/1
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/
/* 防止重调用 -----------------------------------------------------------------*/
#ifndef __MY_KEY_H_
#define __MY_KEY_H_

/* 全局文件调用 ---------------------------------------------------------------*/
#include "My_Labrary.h"

/* 全局宏定义 -----------------------------------------------------------------*/
#define GPIOB_1       (GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_1) == GPIO_PIN_1)
#define KEY_CLK 	  (GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_1) == GPIO_PIN_1)
#define KEY_DATA	  (GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_0) == GPIO_PIN_0)

#define KEY_CLK_L()     GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_1,0)                             
#define KEY_CLK_H()     GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_PIN_1)                        
    
#define KEY_DATA_L()    GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0,0)   
#define KEY_DATA_H()    GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0,GPIO_PIN_0)                          

/* 结构体声明 -----------------------------------------------------------------*/ 
typedef struct __Key_FSM //按键状态机
{
	volatile u8 Flag;  //标志
	volatile u8 Buff;  //缓冲键盘的数据
	volatile u8 Count; //计数 
} Key_TypeDef;

/* 全局变量声明 ---------------------------------------------------------------*/ 
extern Key_TypeDef g_keyboard;  

/* 全局函数声明 ---------------------------------------------------------------*/
void Key_Init(void);
u8 Key_Read(void); 
void KeyWrite(u8 _data);
	
#endif 

/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/



