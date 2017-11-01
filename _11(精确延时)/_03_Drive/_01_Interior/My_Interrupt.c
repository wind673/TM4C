/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
/**============================================================================
* @FileName    : My_Interrupt.c
* @Description : 中断驱动
* @Date        : 2016/2/25
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/
/* 头文件包含 -----------------------------------------------------------------*/
#include "My_Interrupt.h"
#include "My_GPIO.h"   

/* 私有宏定义 -----------------------------------------------------------------*/

/* 私有变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数声明 --------------------------------------------------------*/

/* 全局变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数编写 --------------------------------------------------------*/

/* 全局函数编写 ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : My_TimerInit_0A()     
* @Description   : 定时器配置函数
* @Parameter     : void
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/2/27
* @Explain       : None
------------------------------------------------------------------------------*/
void My_TimerInit_0A(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0); //使能系统Timer0定时器        
	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC); //定时器配置 		
	TimerLoadSet(TIMER0_BASE, TIMER_A, (SysCtlClockGet() / 10) / 2 -1); //    
	
	IntEnable(INT_TIMER0A); //使能Timer0A中断  
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT); //使能定时器  
	IntMasterEnable(); //使能中断进程  
	TimerEnable(TIMER0_BASE, TIMER_A); //使能中断0A  
	  
}

/**----------------------------------------------------------------------------
* @FunctionName  : Timer0IntHandler()     
* @Description   : 定时器服务函数
* @Parameter     : void
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/2/27
* @Explain       : None
------------------------------------------------------------------------------*/
void Timer0IntHandler(void)
{
	static u8 LED_SW;         
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);  
	
	LED_SW = ~LED_SW;       
	if(LED_SW) LED1_ON();  
	else LED1_OFF();  
	
	  
}


/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
