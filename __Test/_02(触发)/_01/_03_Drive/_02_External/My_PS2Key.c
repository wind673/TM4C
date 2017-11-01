/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/
/**============================================================================
* @FileName    : My_PS2Key.c
* @Description : PS2��������
* @Date        : 2016/4/9
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : ��������ֲע�⣺My_PS2Key.cMy_PS2Key.h�ļ����⣬
*								����Ҫ��ֲMy_Interrupt.c�е�
*								�жϷ�����GPIOHIntHandler();
*=============================================================================*/

/* ͷ�ļ����� -----------------------------------------------------------------*/ 
#include "My_PS2Key.h"  
#include "My_LCD.h"
#include "My_Delay.h" 
#include "My_LCD12864.h"

/* ˽�к궨�� -----------------------------------------------------------------*/

/* ˽�б������� ---------------------------------------------------------------*/

/* ˽�У���̬���������� --------------------------------------------------------*/


/* ȫ�ֱ������� ---------------------------------------------------------------*/

/* ȫ�ֽṹ�嶨�� -------------------------------------------------------------*/
PS2Key_TypeDef g_keyboard = {0};  //g_ ����ȫ�ֱ���
																	
/* ˽�У���̬��������д --------------------------------------------------------*/

/* ȫ�ֺ�����д ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : Key_Init()     
* @Description   : С���̳�ʼ������    
* @Programer     : WindRises��л���죩   
* @Data          : 2016/3/1     
* @Explain       : None   
------------------------------------------------------------------------------*/
void PS2Key_Init(void)
{
	
	/* Step 1 ʹ�� ------------------------------*/       
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);  //ʹ��IO��     
	
	/* Step 2 ���ó����� ------------------------*/ 
  	GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE,GPIO_PIN_0|GPIO_PIN_1);   //���ó�����
	GPIODirModeSet(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_DIR_MODE_IN);
	
	/* Step 3 �����жϷ�ʽ ----------------------*/ 
    GPIOIntTypeSet(GPIO_PORTJ_BASE,GPIO_PIN_1,GPIO_FALLING_EDGE);  //���ó��½��� 
	
	/* Step 4 �����ж�IO�� ----------------------*/ 
    GPIOIntEnable(GPIO_PORTJ_BASE,GPIO_PIN_1);   //�����жϵ�IO��  
	
	/* Step 5 ʹ���ж� --------------------------*/ 
	IntEnable(INT_GPIOJ);   //ʹ��IO��
	IntMasterEnable();   
	
	
	
}

/**----------------------------------------------------------------------------
* @FunctionName  : PS2KeyBorad_Read()     
* @Description   : С���̶�ȡ����    
* @Programer     : WindRises��л���죩   
* @Data          : 2016/3/1     
* @Explain       : ���ص���ASCII��   
------------------------------------------------------------------------------*/
u8 PS2KeyBorad_Read(void)
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

/**----------------------------------------------------------------------------
* @FunctionName  : PS2KeyBorad_Show()     
* @Description   : С������ʾ����    
* @Programer     : WindRises��л���죩   
* @Data          : 2016/3/1     
* @Explain       : None
------------------------------------------------------------------------------*/
void PS2KeyBorad_Show(void)
{
	static u8 _ch[16] = {0},_x = 0;
	_ch[_x] = PS2KeyBorad_Read();	
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

/**----------------------------------------------------------------------------
* @FunctionName  : PS2DataSend()     
* @Description   : PS2��������   
* @Programer     : WindRises��л���죩   
* @Data          : 2016/4/9     
* @Explain       : None
------------------------------------------------------------------------------*/
void PS2DataSend(u8 _data)
{
	u8 i = 0;
	u8 _P = 1;//��żУ��λ(��У��)   
	
  	GPIOPinTypeGPIOOutput(GPIO_PORTJ_BASE,GPIO_PIN_0|GPIO_PIN_1);   //���ó�����
	GPIODirModeSet(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_DIR_MODE_OUT);  
    GPIOIntDisable(GPIO_PORTJ_BASE,GPIO_PIN_1);   //�����жϵ�IO��    
	
	delay_ms(10); 
	/* ��ʼλ 0 -----------------------*/ 
	PS2_CLK_L(); 
	delay_us(100); 	
	PS2_DATA_L();	 
	PS2_CLK_H();	
	PS2_DATA_L();	
	delay_us(20);	
	PS2_CLK_L();	
	delay_us(40);	
	
	/* ����λ -------------------------*/   
	for( i = 0; i < 8 ;i ++)
	{
		PS2_CLK_H();	
		if(_data & 0x01<<i) {PS2_DATA_H();_P = ~_P;}		
		else PS2_DATA_L();
		delay_us(20);	
		PS2_CLK_L(); 
		delay_us(40);   
	} 
	
	/* У��λ -------------------------*/ 
	PS2_CLK_H();	
	if(_P) PS2_DATA_H();		
	else PS2_DATA_L();	
	delay_us(20);	
	PS2_CLK_L(); 	
	delay_us(40);	
	
	/* ��ֹλ 1 -----------------------*/
	PS2_CLK_H();
	PS2_DATA_H(); 
	delay_us(20);	
	PS2_CLK_L();  
	delay_us(40);
	
	PS2_CLK_H();  
	PS2_DATA_H();   
	PS2Key_Init();
}


/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/





