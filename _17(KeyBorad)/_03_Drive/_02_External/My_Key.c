/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/

/**============================================================================
* @FileName    : My_Key.c
* @Description : LCD12864������ʾ����
* @Date        : 2016/3/1
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : ��������ֲע�⣺����My_Key.c��My_Key.h�ļ����⣬
*								����Ҫ��ֲMy_Interrupt.c�е�
*								�жϷ�����GPIOBIntHandler();
*=============================================================================*/

/* ͷ�ļ����� -----------------------------------------------------------------*/ 
#include "My_Key.h"  
#include "My_LCD.h"
#include "My_Delay.h" 
#include "My_LCD12864.h"

/* ˽�к궨�� -----------------------------------------------------------------*/

/* ˽�б������� ---------------------------------------------------------------*/

/* ˽�У���̬���������� --------------------------------------------------------*/


/* ȫ�ֱ������� ---------------------------------------------------------------*/

/* ȫ�ֽṹ�嶨�� -------------------------------------------------------------*/
Key_TypeDef g_keyboard = {0};  //g_ ����ȫ�ֱ���
																	
/* ˽�У���̬��������д --------------------------------------------------------*/

/* ȫ�ֺ�����д ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : Key_Init()     
* @Description   : С���̳�ʼ������    
* @Programer     : WindRises��л���죩   
* @Data          : 2016/3/1     
* @Explain       : None   
------------------------------------------------------------------------------*/
void Key_Init(void)
{
	
	/* Step 1 ʹ�� ------------------------------*/       
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);  //ʹ��IO��     
	
	/* Step 2 ���ó����� ------------------------*/ 
  	GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,GPIO_PIN_0|GPIO_PIN_1);   //���ó�����
	GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_DIR_MODE_HW);
	
	/* Step 3 �����жϷ�ʽ ----------------------*/ 
    GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_FALLING_EDGE);  //���ó��½��� 
	
	/* Step 4 �����ж�IO�� ----------------------*/ 
    GPIOIntEnable(GPIO_PORTB_BASE,GPIO_PIN_1);   //�����жϵ�IO��  
	
	/* Step 5 ʹ���ж� --------------------------*/ 
	IntEnable(INT_GPIOB);   //ʹ��IO��
	IntMasterEnable();   
	 
}

/**----------------------------------------------------------------------------
* @FunctionName  : KeyBorad_Read()     
* @Description   : С���̶�ȡ����    
* @Programer     : WindRises��л���죩   
* @Data          : 2016/3/1     
* @Explain       : ���ص���ASCII��   
------------------------------------------------------------------------------*/
u8 KeyBorad_Read(void)
{
	u8 _temp = 0;
	if(g_keyboard.Flag == 1)
	{
		g_keyboard.Flag = 0; //�����־
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
	
	if(_ch[_x-1] == 'B') //����
	{
		while(_x) _ch[--_x] = 0; 
		LCD_Clear();
	}
	
	if(_x >= 16) //����
	{	
		while(_x) _ch[--_x] = 0; 
		LCD_Clear();
	}	
		 	
	LCD_String(0,1,_ch);  
	
}


/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/





