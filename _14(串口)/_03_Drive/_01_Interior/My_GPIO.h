/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
/**============================================================================
* @FileName    : My_GPIO.h
* @Description : None
* @Date        : 2016/2/25
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/
/* 防止重调用 -----------------------------------------------------------------*/
#ifndef __MY_GPIO_H 
#define __MY_GPIO_H

/* 全局文件调用 ---------------------------------------------------------------*/
#include "My_Labrary.h"

/* 全局宏定义 -----------------------------------------------------------------*/
/* LED控制 ----------------------------------------*/
#define LED1_ON() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_6,GPIO_PIN_6)
#define LED1_OFF() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_6,0)
#define LED2_ON() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_5,GPIO_PIN_5)
#define LED2_OFF() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_5,0)
#define LED3_ON() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_PIN_4)
#define LED3_OFF() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,0)
#define LED4_ON() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_PIN_0)
#define LED4_OFF() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0)
#define LED_ALL_ON() GPIOPinWrite(GPIO_PORTF_BASE , GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,\
													GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6) 
													
#define LED_ALL_OFF() GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,0) 

/* 结构体声明 -----------------------------------------------------------------*/ 

/* 全局变量声明 ---------------------------------------------------------------*/ 

/* 全局函数声明 ---------------------------------------------------------------*/
void My_GPIOInit(void);



	







#endif
/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/


