/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/

/**============================================================================
* @FileName    : My_Key.c
* @Description : LCD12864自用显示程序
* @Date        : 2016/3/1
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : 该驱动移植注意：除了My_Key.c和My_Key.h文件以外，
*								还需要移植My_Interrupt.c中的
*								中断服务函数GPIOBIntHandler();
*=============================================================================*/

/* 头文件包含 -----------------------------------------------------------------*/ 
#include "My_Key.h"  
#include "My_LCD.h"
#include "My_Delay.h" 
#include "My_LCD12864.h"

/* 私有宏定义 -----------------------------------------------------------------*/

/* 私有变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数声明 --------------------------------------------------------*/


/* 全局变量定义 ---------------------------------------------------------------*/

/* 全局结构体定义 -------------------------------------------------------------*/
Key_TypeDef g_keyboard = {0};  //g_ 代表全局变量
																	
/* 私有（静态）函数编写 --------------------------------------------------------*/

/* 全局函数编写 ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : Key_Init()     
* @Description   : 小键盘初始化函数    
* @Programer     : WindRises（谢玉伸）   
* @Data          : 2016/3/1     
* @Explain       : None   
------------------------------------------------------------------------------*/
void Key_Init(void)
{
	
	/* Step 1 使能 ------------------------------*/       
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);  //使能IO口     
	
	/* Step 2 配置成输入 ------------------------*/ 
  	GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,GPIO_PIN_0|GPIO_PIN_1);   //配置成输入
	GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_DIR_MODE_HW);
	
	/* Step 3 配置中断方式 ----------------------*/ 
    GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_FALLING_EDGE);  //配置成下降沿 
	
	/* Step 4 配置中断IO口 ----------------------*/ 
    GPIOIntEnable(GPIO_PORTB_BASE,GPIO_PIN_1);   //配置中断的IO口  
	
	/* Step 5 使能中断 --------------------------*/ 
	IntEnable(INT_GPIOB);   //使能IO口
	IntMasterEnable();   
	 
}

/**----------------------------------------------------------------------------
* @FunctionName  : KeyBorad_Read()     
* @Description   : 小键盘读取函数    
* @Programer     : WindRises（谢玉伸）   
* @Data          : 2016/3/1     
* @Explain       : 返回的是ASCII码   
------------------------------------------------------------------------------*/
u8 KeyBorad_Read(void)
{
	u8 _temp = 0;
	if(g_keyboard.Flag == 1)
	{
		g_keyboard.Flag = 0; //清除标志
		switch(g_keyboard.Buff)
		{
			case 238: _temp = 'N'; break;
			case 148: _temp = '/'; break;
			case 248: _temp = '*'; break;
			case 246: _temp = '-'; break; 
			case 216: _temp = '7'; break;
			case 234: _temp = '8'; break;
			case 250: _temp = '9'; break; 
			case 242: _temp = '+'; break;
			case 214: _temp = '4'; break;
			case 230: _temp = '5'; break; 
			case 232: _temp = '6'; break;
			case 210: _temp = '1'; break;
			case 228: _temp = '2'; break; 
			case 244: _temp = '3'; break;
			case 180: _temp = 'E'; break;
			case 224: _temp = '0'; break;
			case 204: _temp = 'B'; break;
			case 226: _temp = '.'; break;
			default : _temp = 0; break;
		}
		 
		return _temp;
	}
	else return 0;
}

void KeyBorad_Show(void)
{
	static u8 _ch[16] = {0},_x = 0;
	_ch[_x] = KeyBorad_Read();	
	if(_ch[_x] != 0) _x++;	
	
	if(_ch[_x-1] == 'B') //清屏
	{
		while(_x) _ch[--_x] = 0; 
		LCD_Clear();
	}
	
	if(_x >= 16) //清屏
	{	
		while(_x) _ch[--_x] = 0; 
		LCD_Clear();
	}	
		 	
	LCD_String(0,1,_ch);  
	
}


/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/





