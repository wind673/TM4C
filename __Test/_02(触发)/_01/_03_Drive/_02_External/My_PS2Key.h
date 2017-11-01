/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/
/**============================================================================
* @FileName    : My_PS2Key.h
* @Description : PS2��������
* @Date        : 2016/4/9
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : ��������ֲע�⣺My_PS2Key.cMy_PS2Key.h�ļ����⣬
*								����Ҫ��ֲMy_Interrupt.c�е�
*								�жϷ�����GPIOHIntHandler();
*=============================================================================*/
/* ��ֹ�ص��� -----------------------------------------------------------------*/
#ifndef __MY_KEY_H_
#define __MY_KEY_H_

/* ȫ���ļ����� ---------------------------------------------------------------*/
#include "My_Labrary.h"

/* ȫ�ֺ궨�� -----------------------------------------------------------------*/
#define PS2_IO        (GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_1) == GPIO_PIN_1)
#define PS2_CLK 	   PS2_IO
#define PS2_DATA	  (GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_0) == GPIO_PIN_0)

#define PS2_CLK_L()     GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_1,0)                             
#define PS2_CLK_H()     GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_1,GPIO_PIN_1)                        
    
#define PS2_DATA_L()    GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_0,0)   
#define PS2_DATA_H()    GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_0,GPIO_PIN_0)                          
 
/* �ṹ������ -----------------------------------------------------------------*/ 
typedef struct __PS2Key_FSM //����״̬��   
{
	volatile u8 Flag;  //��־ 
	volatile u8 Buff;  //������̵����� 
	volatile u8 Count; //����  
} PS2Key_TypeDef;

/* ȫ�ֱ������� ---------------------------------------------------------------*/ 
extern PS2Key_TypeDef g_keyboard;  

/* ȫ�ֺ������� ---------------------------------------------------------------*/
void PS2Key_Init(void);
u8 PS2KeyBorad_Read(void); 
void PS2KeyBorad_Show(void);
void PS2DataSend(u8 _data);

#endif 

/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/



