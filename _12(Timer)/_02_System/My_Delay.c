/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
/**============================================================================
* @FileName    : My_Delay.c
* @Description : None
* @Date        : 2016/2/25
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/

/* 头文件包含 -----------------------------------------------------------------*/
#include "My_Delay.h" 

/* 私有宏定义 -----------------------------------------------------------------*/

/* 私有变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数声明 --------------------------------------------------------*/

/* 全局变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数编写 --------------------------------------------------------*/

/* 全局函数编写 ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : delay_ms()     
* @Description   : ms延时函数
* @Parameter     : _ms :延时ms
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/2/25
* @Explain       : None
------------------------------------------------------------------------------*/
void delay_ms(u32 _ms)
{
	SysCtlDelay(SysCtlClockGet( )/4000*_ms);     
}

/**----------------------------------------------------------------------------
* @FunctionName  : delay_us()     
* @Description   : us延时函数
* @Parameter     : _us :延时us
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/2/25
* @Explain       : None
------------------------------------------------------------------------------*/
void delay_us(u32 _us)
{
	 
	 SysCtlDelay(SysCtlClockGet( )/4000000*_us);
}



/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/

