/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/

/**============================================================================
* @FileName    : My_GPIO.c
* @Description : None
* @Date        : 2016/2/25
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/

/* ͷ�ļ����� -----------------------------------------------------------------*/
#include "My_GPIO.h"      

/* ˽�к궨�� -----------------------------------------------------------------*/

/* ˽�б������� ---------------------------------------------------------------*/

/* ˽�У���̬���������� --------------------------------------------------------*/

/* ȫ�ֱ������� ---------------------------------------------------------------*/

/* ˽�У���̬��������д --------------------------------------------------------*/

/* ȫ�ֺ�����д ---------------------------------------------------------------*/

/**----------------------------------------------------------------------------
* @FunctionName  : GPIO_Init()     
* @Description   : ������
* @Parameter     : void
* @Return        : void
* @Programer     : WindRises��л���죩
* @Data          : 2016/2/25
* @Explain       : None
------------------------------------------------------------------------------*/
void GPIO_Init(void)
{
	/* Step 1 ------------------------------*/       
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);       // ʹ��LED���ڶ˿�PF  
	
	/* Step 2 ------------------------------*/  
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 1;  
	
	/* Step 3 ------------------------------*/ 
  	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_6|GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5);   
	LED_ALL_OFF(); 
	
	
	
}

void GPIOInterrupt_Init(void)
{
	/* Step 1 ʹ�� ------------------------------*/       
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);  //ʹ��IO��     
	
	/* Step 2 ���ó����� ------------------------*/ 
  	GPIOPinTypeGPIOInput(GPIO_PORTG_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);   //���ó�����
	GPIODirModeSet(GPIO_PORTG_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5, GPIO_DIR_MODE_HW);
	
	/* Step 3 �����жϷ�ʽ ----------------------*/ 
    GPIOIntTypeSet(GPIO_PORTG_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5,GPIO_FALLING_EDGE);  //���ó��½��� 
	
	/* Step 4 �����ж�IO�� ----------------------*/ 
    GPIOIntEnable(GPIO_PORTG_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);   //�����жϵ�IO��  
	
	/* Step 5 ʹ���ж� --------------------------*/ 
	IntEnable(INT_GPIOG);   //ʹ��IO��
	IntMasterEnable();   	
	
	
}


/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/
