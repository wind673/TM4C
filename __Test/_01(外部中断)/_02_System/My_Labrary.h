/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
/**============================================================================
* @FileName    : My_Labrary.h
* @Description : None
* @Date        : 2016/2/26
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : 包含了这个文件就可以用所有的库文件了
*=============================================================================*/
/* 防止重调用 -----------------------------------------------------------------*/
#ifndef __MY_LABRARY_H 
#define __MY_LABRARY_H

#ifndef PART_TM4C123GH6PZ
#define PART_TM4C123GH6PZ
#endif

 
/* 全局文件调用 ---------------------------------------------------------------*/
/* 调用系统自带的文件 ------------------------------*/
#include <stdint.h>            //定义字符内型
#include <stdbool.h>           //0/1的定义

/* 调用宏定义文件 ------------------------------------*/
#include "inc/tm4c123gh6pz.h"  //tm4c123gh6pz专用宏定义
#include "inc/hw_types.h"      //一些位带操作的宏定义
#include "inc/hw_memmap.h"     //外设基地址的定义
#include "inc/hw_gpio.h"	   //一些IO口的宏定义
#include "inc/hw_uart.h"       //串口宏定义


/* 调用驱动文件 ------------------------------------*/
#include "driverlib/gpio.h"    //gpio驱动
#include "driverlib/sysctl.h"  //MCU控制相关系统驱动
#include "driverlib/timer.h"   //定时器驱动
#include "driverlib/interrupt.h"//中断驱动
#include "driverlib/systick.h"  //定时器相关系统驱动
#include "driverlib/uart.h"     //串口驱动
#include "driverlib/pin_map.h" 
#include "utils/uartstdio.h" 

/* 全局宏定义 -----------------------------------------------------------------*/
/* 定义变量的习惯用法 ------------------------------*/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32; 
typedef unsigned long int u64; 

typedef unsigned char uchar;
typedef unsigned short int usint;
typedef unsigned int uint;
typedef unsigned long int ulint;


/* 结构体声明 -----------------------------------------------------------------*/ 

/* 全局变量声明 ---------------------------------------------------------------*/ 

/* 全局函数声明 ---------------------------------------------------------------*/




	







#endif
/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/



