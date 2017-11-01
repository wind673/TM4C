/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/
/**============================================================================
* @FileName    : My_Interrupt.c
* @Description : �ж�����
* @Date        : 2016/2/25
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/
/* ͷ�ļ����� -----------------------------------------------------------------*/
#include "My_Interrupt.h"
#include "My_GPIO.h"   
#include "My_Key.h"  
#include "My_LCD.h"
#include "My_Delay.h" 

/* ˽�к궨�� -----------------------------------------------------------------*/

/* ˽�б������� ---------------------------------------------------------------*/

/* ˽�У���̬���������� --------------------------------------------------------*/
 
/* ȫ�ֱ������� ---------------------------------------------------------------*/

/* ˽�У���̬��������д --------------------------------------------------------*/

/* ȫ�ֺ�����д ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : Timer0A_IntHandler()     
* @Description   : ��ʱ�������� 		
* @Programer     : WindRises��л���죩				
* @Data          : 2016/2/27						
* @Explain       : None					
------------------------------------------------------------------------------*/
void Timer0A_IntHandler(void) 
{
	static u8 LED_SW = 0;         
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT); //(��ǰ��ʱ��׼)  
	
	LED_SW = ~LED_SW;    
	
	if(LED_SW) LED4_ON();                           
	else LED4_OFF();               
	  
}

/**----------------------------------------------------------------------------
* @FunctionName  : GPIOB_IntHandler()     
* @Description   : GPIOB�ⲿ�жϷ����� 		
* @Programer     : WindRises��л���죩				
* @Data          : 2016/2/27						
* @Explain       : None					
------------------------------------------------------------------------------*/

void GPIOB_IntHandler(void)  
{           
	 
	static  u8 _bit = 0,_temp = {0},_exa = 0;
	
	if(GPIOH_5 == 0) //��Ϊ���������IO�ڵ��ж�Ϊ�½��ش���
	{
		_bit ++;//��¼����λ
		if(_bit >= 1 && _bit <= 8)     
		{									
			_temp >>= 1;           
			if(KEY_DATA) _temp|= 0x80;  //�洢���̴���������     
		}																					
															
		/* ÿ������11λ ----------------------------*/	
		if(_bit >= 11)
		{	
			_bit= 0;    
			 
			if(_exa == 2) _exa = 0,_temp = 0; //����һ�����ݣ���һ�����ݣ��ٽ�����һ��
			
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
 
	 
	
	GPIOIntClear(GPIO_PORTH_BASE,GPIO_PIN_4);  //����жϱ�־��һ��Ҫ�ź���(��ǰ����������)       
	
}








/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/