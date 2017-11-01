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


/* ˽�к궨�� -----------------------------------------------------------------*/

/* ˽�б������� ---------------------------------------------------------------*/

/* ˽�У���̬���������� --------------------------------------------------------*/

/* ȫ�ֱ������� ---------------------------------------------------------------*/

/* ˽�У���̬��������д --------------------------------------------------------*/

/* ȫ�ֺ�����д ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : main()     
* @Description   : ������       
* @Parameter     : void     
* @Return        : void        
* @Programer     : WindRises��л���죩     
* @Data          : 2016/2/25  
* @Explain       : �ܶ��ļ����Ҷ������� "My_" �����ӿ��ܻ���ϵͳ�ļ���ͻ
------------------------------------------------------------------------------*/
int main(void)
{
    My_SystemInit(); //ϵͳ��ʼ��
	My_GPIOInit();   //��ͨGPIO�ڳ�ʼ��
  
	while (1) 
	{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,  GPIO_PIN_0); //��PF0�� PF4��PF5��PF6�ر�
		SysCtlDelay(2000000);
		
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,  GPIO_PIN_4);
		SysCtlDelay(2000000);
		
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,  GPIO_PIN_5);
		SysCtlDelay(2000000);
		
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,  GPIO_PIN_6);	
		SysCtlDelay(2000000);
	}
	 
}




/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/
