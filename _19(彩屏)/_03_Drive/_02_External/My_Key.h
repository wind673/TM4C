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
#define GPIOH_5       (GPIOPinRead(GPIO_PORTH_BASE,GPIO_PIN_5) == GPIO_PIN_5)
#define KEY_CLK 	  (GPIOPinRead(GPIO_PORTH_BASE,GPIO_PIN_5) == GPIO_PIN_5)
#define KEY_DATA	  (GPIOPinRead(GPIO_PORTH_BASE,GPIO_PIN_4) == GPIO_PIN_4)

#define KEY_CLK_L()     GPIOPinWrite(GPIO_PORTH_BASE,GPIO_PIN_5,0)                             
#define KEY_CLK_H()     GPIOPinWrite(GPIO_PORTH_BASE,GPIO_PIN_5,GPIO_PIN_5)                        
    
#define KEY_DATA_L()    GPIOPinWrite(GPIO_PORTH_BASE,GPIO_PIN_4,0)   
#define KEY_DATA_H()    GPIOPinWrite(GPIO_PORTH_BASE,GPIO_PIN_4,GPIO_PIN_4)                          

/* 结构体声明 -----------------------------------------------------------------*/ 
typedef struct __Key_FSM //按键状态机
{
	volatile u8 Flag;  //标志
	volatile u8 Buff;  //缓冲键盘的数据
	volatile u8 Count; //计数 
} Type_Key;

/* 全局变量声明 ---------------------------------------------------------------*/ 
extern Type_Key g_keyboard;  

/* 全局函数声明 ---------------------------------------------------------------*/
void Key_Init(void);
u8 KeyBorad_Read(void);
void KeyWrite(u8 _data);
void KeyBorad_Show(void);

#endif 

/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/



