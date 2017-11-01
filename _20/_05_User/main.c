/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/

/**============================================================================
* @FileName    : main.c
* @Description : None
* @Date        : 2016/2/25
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/

/* ͷ�ļ����� -----------------------------------------------------------------*/ 
#include "My_Labrary.h"
#include "My_GPIO.h"   
#include "My_System.h"
#include "My_Timer.h"
#include "My_Delay.h" 
#include "My_LCD12864.h"
#include "My_LCD.h"
#include "My_Key.h" 
#include "My_TFT.h"	

/* ˽�к궨�� -----------------------------------------------------------------*/

/* ˽�б������� ---------------------------------------------------------------*/

/* ˽�У���̬���������� --------------------------------------------------------*/

/* ȫ�ֱ������� ---------------------------------------------------------------*/

/* ˽�У���̬��������д --------------------------------------------------------*/

/* ȫ�ֺ�����д ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : main()     
* @Description   : ������              
* @Data          : 2016/2/25  
* @Explain       : �ܶ��ļ����Ҷ������� "My_" �����ӿ��ܻ���ϵͳ�ļ���ͻ
------------------------------------------------------------------------------*/

int main(void)
{ 
    System_Init(); //ϵͳ��ʼ��         
	GPIO_Init();   //��ͨGPIO�ڳ�ʼ��                
	Timer0A_Init();  //��ʱ����ʼ��                   
//	LCD12864_Init();	//LCD12864��ʼ��   
	TFT_Init();	
//	Key_Init();   
	TFT_Clear(BLACK);
	TextColor = WHITE; 
	
	while (1) 
	{ 
		
		LCD_String_Show(FONT_1,FONT_1,(u8*)"Hello",FONT_1);
		LCD_String_Show(FONT_2,50,(u8*)"TFT ILI9341",FONT_2); 
		LCD_String_Show(20,100,(u8*)"0123456789",FONT_3);
		
		LCD_String_Show(100,150,(u8*)"XieYushen",FONT_3);
		LCD_String_Show(40,200,(u8*)"(C) COPYRIGHT 2016 WindRises",FONT_2); 
//		KeyBorad_Show(); 
	}
	 
}






/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/














