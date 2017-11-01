/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/
/**============================================================================
* @FileName    : My_LCD.h
* @Description : LCD12864������ʾ����
* @Date        : 2016/3/1
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/
/* ��ֹ�ص��� -----------------------------------------------------------------*/
#ifndef __MY_KEY_H_
#define __MY_KEY_H_

/* ȫ���ļ����� ---------------------------------------------------------------*/
#include "My_Labrary.h"

/* ȫ�ֺ궨�� -----------------------------------------------------------------*/
#define GPIOB_1       (GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_1) == GPIO_PIN_1)
#define KEY_CLK 	  (GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_1) == GPIO_PIN_1)
#define KEY_DATA	  (GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_0) == GPIO_PIN_0)

#define KEY_CLK_L()     GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_1,0)                             
#define KEY_CLK_H()     GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_PIN_1)                        
    
#define KEY_DATA_L()    GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0,0)   
#define KEY_DATA_H()    GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0,GPIO_PIN_0)                          

/* �ṹ������ -----------------------------------------------------------------*/ 
typedef struct __Key_FSM //����״̬��
{
	volatile u8 Flag;  //��־
	volatile u8 Buff;  //������̵�����
	volatile u8 Count; //���� 
} Key_TypeDef;

/* ȫ�ֱ������� ---------------------------------------------------------------*/ 
extern Key_TypeDef g_keyboard;  

/* ȫ�ֺ������� ---------------------------------------------------------------*/
void Key_Init(void);
u8 KeyBorad_Read(void);
void KeyWrite(u8 _data);
void KeyBorad_Show(void);

#endif 

/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/



