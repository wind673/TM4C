/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/
/**============================================================================
* @FileName    : My_Labrary.h
* @Description : None
* @Date        : 2016/2/26
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : ����������ļ��Ϳ��������еĿ��ļ���
*=============================================================================*/
/* ��ֹ�ص��� -----------------------------------------------------------------*/
#ifndef __MY_LABRARY_H 
#define __MY_LABRARY_H

#ifndef PART_TM4C123GH6PZ
#define PART_TM4C123GH6PZ
#endif

 
/* ȫ���ļ����� ---------------------------------------------------------------*/
/* ����ϵͳ�Դ����ļ� ------------------------------*/
#include <stdint.h>            //�����ַ�����
#include <stdbool.h>           //0/1�Ķ���

/* ���ú궨���ļ� ------------------------------------*/
#include "inc/tm4c123gh6pz.h"  //tm4c123gh6pzר�ú궨��
#include "inc/hw_types.h"      //һЩλ�������ĺ궨��
#include "inc/hw_memmap.h"     //�������ַ�Ķ���
#include "inc/hw_gpio.h"	   //һЩIO�ڵĺ궨��
#include "inc/hw_uart.h"       //���ں궨��


/* ���������ļ� ------------------------------------*/
#include "driverlib/gpio.h"    //gpio����
#include "driverlib/sysctl.h"  //MCU�������ϵͳ����
#include "driverlib/timer.h"   //��ʱ������
#include "driverlib/interrupt.h"//�ж�����
#include "driverlib/systick.h"  //��ʱ�����ϵͳ����
#include "driverlib/uart.h"     //��������
#include "driverlib/pin_map.h" 
#include "utils/uartstdio.h" 

/* ȫ�ֺ궨�� -----------------------------------------------------------------*/
/* ���������ϰ���÷� ------------------------------*/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32; 
typedef unsigned long int u64; 

typedef unsigned char uchar;
typedef unsigned short int usint;
typedef unsigned int uint;
typedef unsigned long int ulint;


/* �ṹ������ -----------------------------------------------------------------*/ 

/* ȫ�ֱ������� ---------------------------------------------------------------*/ 

/* ȫ�ֺ������� ---------------------------------------------------------------*/




	







#endif
/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/



