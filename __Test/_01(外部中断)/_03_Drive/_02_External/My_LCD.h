/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
/**============================================================================
* @FileName    : My_LCD.h
* @Description : LCD12864自用显示程序
* @Date        : 2016/2/28
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/
/* 防止重调用 -----------------------------------------------------------------*/
#ifndef __MY_LCD_H_
#define __MY_LCD_H_

/* 全局文件调用 ---------------------------------------------------------------*/
#include "My_Labrary.h"
#include "My_LCD12864.h"

/* 全局宏定义 -----------------------------------------------------------------*/

/* 结构体声明 -----------------------------------------------------------------*/ 

/* 全局变量声明 ---------------------------------------------------------------*/ 

/* 全局函数声明 ---------------------------------------------------------------*/
void LCD_Num(u8 _x,u8 _y,u32 _num,u8 _size);
void LCD_Decimal(u8 _x,u8 _y,double _float_num,u8 _valid);
void LCD_String(u8 _x,u8 _y,u8 *_str);

 


#endif 

/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/



