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
#include "My_Key.h"  
#include "My_LCD.h"
#include "My_Delay.h" 

/* 私有宏定义 -----------------------------------------------------------------*/

/* 私有变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数声明 --------------------------------------------------------*/
 
/* 全局变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数编写 --------------------------------------------------------*/

/* 全局函数编写 ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : Timer0AIntHandler()     
* @Description   : 定时器服务函数 		
* @Programer     : WindRises（谢玉伸）				
* @Data          : 2016/2/27						
* @Explain       : None					
------------------------------------------------------------------------------*/
void Timer0AIntHandler(void) 
{
	static u8 LED_SW = 0;         
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);   
	LED_SW = ~LED_SW;    
	
	if(LED_SW) LED4_ON();                           
	else LED4_OFF();               
	  
}

/**----------------------------------------------------------------------------
* @FunctionName  : GPIOBIntHandler()     
* @Description   : GPIOB外部中断服务函数 		
* @Programer     : WindRises（谢玉伸）				
* @Data          : 2016/2/27						
* @Explain       : None					
------------------------------------------------------------------------------*/
void GPIOBIntHandler(void)  
{                          
	static u8 _temp = 0,_bit = 0; 
	
	if(GPIOB_1 == 0) //因为我设置这个IO口的中断为下降沿触发
	{
		_bit ++;//记录数据位
		if(_bit >= 1 && _bit <= 8)     
		{		
			_temp >>= 1;           
			if(KEY_DATA) _temp |= 0x80;  //存储键盘传来的数据     
		}		
			
		if(_bit >= 11)
		{	//每组数据11位
			g_keyboard.Buff = _temp; //将数据存入   
			g_keyboard.Flag =1; //将标志位置1    
			_bit= 0;    
		}
	}
	GPIOIntClear(GPIO_PORTB_BASE,GPIO_PIN_1);  //清除中断标志，一定要放后面       
	
}








/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
