/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/
/**============================================================================
* @FileName    : My_GPIO.h
* @Description : None
* @Date        : 2016/2/25
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/
/* ��ֹ�ص��� -----------------------------------------------------------------*/
#ifndef __MY_GPIO_H 
#define __MY_GPIO_H

/* ȫ���ļ����� ---------------------------------------------------------------*/
#include "My_Labrary.h"

/* ȫ�ֺ궨�� -----------------------------------------------------------------*/
/* LED���� ----------------------------------------*/
#define LED1_ON() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_6,GPIO_PIN_6)
#define LED1_OFF() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_6,0)
#define LED2_ON() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_5,GPIO_PIN_5)
#define LED2_OFF() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_5,0)
#define LED3_ON() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_PIN_4)
#define LED3_OFF() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,0)
#define LED4_ON() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_PIN_0)
#define LED4_OFF() GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0)
#define LED_ALL_ON() GPIOPinWrite(GPIO_PORTF_BASE , GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,\
													GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6) 
													
#define LED_ALL_OFF() GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,0) 

/* �ṹ������ -----------------------------------------------------------------*/ 

/* ȫ�ֱ������� ---------------------------------------------------------------*/ 

/* ȫ�ֺ������� ---------------------------------------------------------------*/
void GPIO_Init(void);



	







#endif
/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/


