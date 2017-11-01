/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
/**============================================================================
* @FileName    : My_System.c
* @Description : None
* @Date        : 2016/2/25
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/

/* 头文件包含 -----------------------------------------------------------------*/
#include "My_System.h"
#include <stdint.h>            //定义字符内型
#include <stdbool.h>       //0/1的定义
#include "inc/hw_memmap.h"   //外设基地址的定义
#include "driverlib/sysctl.h" //系统时钟

/* 私有宏定义 -----------------------------------------------------------------*/

/* 私有变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数声明 --------------------------------------------------------*/

/* 全局变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数编写 --------------------------------------------------------*/

/* 全局函数编写 ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : My_SystemInit()     
* @Description   : 系统初始化函数
* @Parameter     : void
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/2/25
* @Explain       : None
------------------------------------------------------------------------------*/
void My_SystemInit(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	
 
}




/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/

