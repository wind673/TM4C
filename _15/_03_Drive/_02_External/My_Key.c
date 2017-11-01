/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/

/**============================================================================
* @FileName    : My_Key.c
* @Description : LCD12864������ʾ����
* @Date        : 2016/2/28
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/

/* ͷ�ļ����� -----------------------------------------------------------------*/ 
#include "My_Key.h"  

/* ˽�к궨�� -----------------------------------------------------------------*/

/* ˽�б������� ---------------------------------------------------------------*/

/* ˽�У���̬���������� --------------------------------------------------------*/

/* ȫ�ֱ������� ---------------------------------------------------------------*/

/* ȫ�ֽṹ�嶨�� -------------------------------------------------------------*/
Key_TypeDef g_keyboard = {0};  //g_ ����ȫ�ֱ���
																	
/* ˽�У���̬��������д --------------------------------------------------------*/

/* ȫ�ֺ�����д ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : My_KeyInit()     
* @Description   : ���ڼ��̳�ʼ������    
* @Programer     : WindRises��л���죩   
* @Data          : 2016/2/28     
* @Explain       : None   
------------------------------------------------------------------------------*/
void My_KeyInit(void)
{
	
	/* Step 1 ʹ�� ------------------------------*/       
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);  //ʹ��IO��     
	
	/* Step 2 ���ó����� ------------------------*/ 
  	GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,GPIO_PIN_0|GPIO_PIN_1);   //���ó�����
	GPIODirModeSet(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_DIR_MODE_IN);
	
	/* Step 3 �����жϷ�ʽ ----------------------*/ 
    GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_FALLING_EDGE);  //���ó��½��� 
	
	/* Step 4 �����ж�IO�� ----------------------*/ 
    GPIOIntEnable(GPIO_PORTB_BASE,GPIO_PIN_1);   //�����жϵ�IO��  
	
	/* Step 5 ʹ���ж� --------------------------*/ 
	IntEnable(INT_GPIOB);   //ʹ��IO��
	IntMasterEnable();             
	
}




/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/




