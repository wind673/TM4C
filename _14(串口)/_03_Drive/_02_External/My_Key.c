/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/

/**============================================================================
* @FileName    : My_Key.c
* @Description : LCD12864自用显示程序
* @Date        : 2016/2/28
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/

/* 头文件包含 -----------------------------------------------------------------*/ 
#include "My_Key.h"  

/* 私有宏定义 -----------------------------------------------------------------*/

/* 私有变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数声明 --------------------------------------------------------*/

/* 全局变量定义 ---------------------------------------------------------------*/

/* 全局结构体定义 -------------------------------------------------------------*/
KEY_TypeDef Key = {0, 0xff};
																	
/* 私有（静态）函数编写 --------------------------------------------------------*/

/* 全局函数编写 ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : My_KeyInit()     
* @Description   : 串口键盘初始化函数 
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/2/28
* @Explain       : None
------------------------------------------------------------------------------*/
void My_KeyInit(void)
{
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
//	GPIOPinConfigure(GPIO_PC4_U4RX);
//	GPIOPinConfigure(GPIO_PC5_U4TX);
//	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART4);
//	UARTClockSourceSet(UART4_BASE, UART_CLOCK_PIOSC);
//	GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);		
//	UARTStdioConfig(4, 115200, 16000000);
//	
	
 
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1); 
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); 
	  
	GPIOPinConfigure(GPIO_PB0_U1RX);
	GPIOPinConfigure(GPIO_PB1_U1TX);
	GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	
	UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 9600,\
			           (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE)); 

	HWREG(UART1_BASE + UART_O_LCRH) &= ~(UART_LCRH_FEN);//	UARTFIFODisable ( UART1_BASE ) ;

	UARTIntEnable(UART1_BASE, UART_INT_RX);  
	IntEnable(INT_UART1);	
}




/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/





