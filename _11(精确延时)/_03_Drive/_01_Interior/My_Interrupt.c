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

/* ˽�к궨�� -----------------------------------------------------------------*/

/* ˽�б������� ---------------------------------------------------------------*/

/* ˽�У���̬���������� --------------------------------------------------------*/

/* ȫ�ֱ������� ---------------------------------------------------------------*/

/* ˽�У���̬��������д --------------------------------------------------------*/

/* ȫ�ֺ�����д ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : My_TimerInit_0A()     
* @Description   : ��ʱ�����ú���
* @Parameter     : void
* @Return        : void
* @Programer     : WindRises��л���죩
* @Data          : 2016/2/27
* @Explain       : None
------------------------------------------------------------------------------*/
void My_TimerInit_0A(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0); //ʹ��ϵͳTimer0��ʱ��        
	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC); //��ʱ������ 		
	TimerLoadSet(TIMER0_BASE, TIMER_A, (SysCtlClockGet() / 10) / 2 -1); //    
	
	IntEnable(INT_TIMER0A); //ʹ��Timer0A�ж�  
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT); //ʹ�ܶ�ʱ��  
	IntMasterEnable(); //ʹ���жϽ���  
	TimerEnable(TIMER0_BASE, TIMER_A); //ʹ���ж�0A  
	  
}

/**----------------------------------------------------------------------------
* @FunctionName  : Timer0IntHandler()     
* @Description   : ��ʱ��������
* @Parameter     : void
* @Return        : void
* @Programer     : WindRises��л���죩
* @Data          : 2016/2/27
* @Explain       : None
------------------------------------------------------------------------------*/
void Timer0IntHandler(void)
{
	static u8 LED_SW;         
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);  
	
	LED_SW = ~LED_SW;       
	if(LED_SW) LED1_ON();  
	else LED1_OFF();  
	
	  
}


/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/
