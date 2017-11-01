/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
/**============================================================================
* @FileName    : My_PS2Key.h
* @Description : PS2按键程序
* @Date        : 2016/4/9
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : 该驱动移植注意：My_PS2Key.cMy_PS2Key.h文件以外，
*								还需要移植My_Interrupt.c中的
*								中断服务函数GPIOHIntHandler();
*=============================================================================*/
/* 防止重调用 -----------------------------------------------------------------*/
#ifndef __MY_KEY_H_
#define __MY_KEY_H_

/* 全局文件调用 ---------------------------------------------------------------*/
#include "My_Labrary.h"

/* 全局宏定义 -----------------------------------------------------------------*/
#define PS2_IO        (GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_1) == GPIO_PIN_1)
#define PS2_CLK 	   PS2_IO
#define PS2_DATA	  (GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_0) == GPIO_PIN_0)

#define PS2_CLK_L()     GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_1,0)                             
#define PS2_CLK_H()     GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_1,GPIO_PIN_1)                        
    
#define PS2_DATA_L()    GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_0,0)   
#define PS2_DATA_H()    GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_0,GPIO_PIN_0)                          
 
/* 结构体声明 -----------------------------------------------------------------*/ 
typedef struct __PS2Key_FSM //按键状态机   
{
	volatile u8 Flag;  //标志 
	volatile u8 Buff;  //缓冲键盘的数据 
	volatile u8 Count; //计数  
} PS2Key_TypeDef;

/* 全局变量声明 ---------------------------------------------------------------*/ 
extern PS2Key_TypeDef g_keyboard;  

/* 全局函数声明 ---------------------------------------------------------------*/
void PS2Key_Init(void);
u8 PS2KeyBorad_Read(void); 
void PS2KeyBorad_Show(void);
void PS2DataSend(u8 _data);

#endif 

/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/



