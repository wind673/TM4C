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
* @FunctionName  : Timer0A_IntHandler()     
* @Description   : 定时器服务函数 		
* @Programer     : WindRises（谢玉伸）				
* @Data          : 2016/2/27						
* @Explain       : None					
------------------------------------------------------------------------------*/
void Timer0A_IntHandler(void) 
{
	static u8 LED_SW = 0;         
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);   
	LED_SW = ~LED_SW;    
	
	if(LED_SW) LED4_ON();                           
	else LED4_OFF();               
	  
}

/**----------------------------------------------------------------------------
* @FunctionName  : GPIOB_IntHandler()     
* @Description   : GPIOB外部中断服务函数 		
* @Programer     : WindRises（谢玉伸）				
* @Data          : 2016/2/27						
* @Explain       : None					
------------------------------------------------------------------------------*/

void GPIOB_IntHandler(void)  
{           
	 
	static  u8 _bit = 0,_temp = {0},_exa = 0;
	
	if(GPIOB_1 == 0) //因为我设置这个IO口的中断为下降沿触发
	{
		_bit ++;//记录数据位
		if(_bit >= 1 && _bit <= 8)     
		{									
			_temp >>= 1;           
			if(KEY_DATA) _temp|= 0x80;  //存储键盘传来的数据     
		}																					
															
		/* 每个数据11位 ----------------------------*/	
		if(_bit >= 11)
		{	
			_bit= 0;    
			 
			if(_exa == 2) _exa = 0,_temp = 0; //收完一组数据，隔一个数据，再接收下一组
			
			if(_exa == 1)          
			{  					
				g_keyboard.Buff = _temp;  		
				g_keyboard.Flag = 1;			
				_temp = 0;  		
				_exa = 2;		
			}			
			                                   
			if(_temp == 224) _exa = 1;			
		}
		   
	}
  
	GPIOIntClear(GPIO_PORTB_BASE,GPIO_PIN_1);  //清除中断标志，一定要放后面（定时器放最前面定时比较准.但外部中断最好放后面，否则容易死机）       
	
}


/**----------------------------------------------------------------------------
* @FunctionName  : GPIOG_IntHandler()     
* @Description   : GPIOG外部中断服务函数 		
* @Programer     : WindRises（谢玉伸）				
* @Data          : 2016/3/5						
* @Explain       : 测试用					
------------------------------------------------------------------------------*/
void GPIOG_IntHandler(void)
{
	static u8 _sw;     				
	_sw = ~_sw;					
							
	if(_sw) LED2_ON();   
	else LED2_OFF();   
	                        
		 										
	GPIOIntClear(GPIO_PORTG_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);  //清除中断标志，一定要放后面 
}






/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/





