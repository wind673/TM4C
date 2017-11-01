/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/

/**============================================================================
* @FileName    : main.c
* @Description : None
* @Date        : 2016/2/25
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/

/* 头文件包含 -----------------------------------------------------------------*/ 
#include "My_Labrary.h"
#include "My_GPIO.h"   
#include "My_System.h"
#include "My_Interrupt.h"
#include "My_Delay.h" 
#include "My_LCD12864.h"
#include "My_LCD.h"

/* 私有宏定义 -----------------------------------------------------------------*/

/* 私有变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数声明 --------------------------------------------------------*/

/* 全局变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数编写 --------------------------------------------------------*/

/* 全局函数编写 ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : main()     
* @Description   : 主函数          
* @Programer     : WindRises（谢玉伸）     
* @Data          : 2016/2/25  
* @Explain       : 很多文件名我都加上了 "My_" ，不加可能会与系统文件冲突
------------------------------------------------------------------------------*/
 
int main(void)
{
	  
    My_SystemInit(); //系统初始化         
	My_GPIOInit();   //普通GPIO口初始化               
	My_TimerInit_0A();  //定时器初始化                  
	LCD12864_Init();	//LCD12864初始化
	
	LCD_String(0,0,"▲△");
	LCD_Decimal(0,1,3.1415,5);
	
	while (1) 
	{
		  
                  
		 
	}
	 
}




/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/





