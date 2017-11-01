/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/

/**============================================================================
* @FileName    : My_GPIO.c
* @Description : None
* @Date        : 2016/2/25
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/

/* 头文件包含 -----------------------------------------------------------------*/
#include "My_GPIO.h"      

/* 私有宏定义 -----------------------------------------------------------------*/

/* 私有变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数声明 --------------------------------------------------------*/

/* 全局变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数编写 --------------------------------------------------------*/

/* 全局函数编写 ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : GPIO_Init()     
* @Description   : 主函数
* @Parameter     : void
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/2/25
* @Explain       : None
------------------------------------------------------------------------------*/
void GPIO_Init(void)
{
	/* Step 1 ------------------------------*/       
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);       // 使能LED所在端口PF  
	
	/* Step 2 ------------------------------*/  
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 1;  
	
	/* Step 3 ------------------------------*/ 
  	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_6|GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5);   
	LED_ALL_OFF(); 
	
	
	
}

void GPIOInterrupt_Init(void)
{
	/* Step 1 使能 ------------------------------*/       
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);  //使能IO口     
	
	/* Step 2 配置成输入 ------------------------*/ 
  	GPIOPinTypeGPIOInput(GPIO_PORTG_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);   //配置成输入
	GPIODirModeSet(GPIO_PORTG_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5, GPIO_DIR_MODE_HW);
	
	/* Step 3 配置中断方式 ----------------------*/ 
    GPIOIntTypeSet(GPIO_PORTG_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5,GPIO_FALLING_EDGE);  //配置成下降沿 
	
	/* Step 4 配置中断IO口 ----------------------*/ 
    GPIOIntEnable(GPIO_PORTG_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);   //配置中断的IO口  
	
	/* Step 5 使能中断 --------------------------*/ 
	IntEnable(INT_GPIOG);   //使能IO口
	IntMasterEnable();   	
	
	
}


/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
