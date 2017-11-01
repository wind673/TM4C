/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
/**============================================================================
* @FileName    : My_TFT.h
* @Description : TFT2.8寸(ILI9341 IC驱动)
* @Date        : 2016/4/2
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/
/* 防止重调用 -----------------------------------------------------------------*/
#ifndef __MY_TFT_H
#define __MY_TFT_H	 

/* 全局文件调用 ---------------------------------------------------------------*/
#include "My_Labrary.h"

/* 全局宏定义 -----------------------------------------------------------------*/
#define USE_HORIZONTAL  	1	//定义是否使用横屏 		0,不使用.1,使用. 

/* IO口定义 ------------------------------------*/
#define	TFT_LED_ON() 	GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_2,GPIO_PIN_2)    //TFT背光  	PJ2 
#define	TFT_LED_OFF() 	GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_2,0)   		   //TFT背光  	PJ2 

#define	TFT_CS_H() 	GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_3,GPIO_PIN_3)    //片选端口  	PE3 
#define	TFT_RS_H() 	GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2,GPIO_PIN_2)    //数据/命令  PE2   
#define	TFT_WR_H() 	GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1,GPIO_PIN_1)    //写数据		PE1 
#define	TFT_RD_H()	GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_0,GPIO_PIN_0)    //读数据		PE0 
								    
#define	TFT_CS_L()  GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_3,0)     //片选端口  	PE3
#define	TFT_RS_L() 	GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2,0)     //数据/命令  PE2	   
#define	TFT_WR_L() 	GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1,0)     //写数据		PE1
#define	TFT_RD_L() 	GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_0,0)     //读数据		PE0 							    
 
/* 扫描方向定义 ------------------------------------*/
#define L2R_U2D  0 //从左到右,从上到下
#define L2R_D2U  1 //从左到右,从下到上
#define R2L_U2D  2 //从右到左,从上到下
#define R2L_D2U  3 //从右到左,从下到上

#define U2D_L2R  4 //从上到下,从左到右
#define U2D_R2L  5 //从上到下,从右到左
#define D2U_L2R  6 //从下到上,从左到右
#define D2U_R2L  7 //从下到上,从右到左

#define DFT_SCAN_DIR  L2R_U2D  //默认的扫描方向

/* 字体尺寸 ---------------------------------------*/
#define FONT_1   12				
#define FONT_2   16			
#define FONT_3   24 

/* 画笔颜色 ---------------------------------------*/
#define WHITE       0xFFFF
#define BLACK      	0x0000	  
#define BLUE       	0x001F  
#define BRED        0XF81F
#define GRED 		0XFFE0
#define GBLUE		0X07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define BROWN 		0XBC40 //棕色
#define BRRED 		0XFC07 //棕红色
#define GRAY  		0X8430 //灰色  
#define DARKBLUE    0X01CF	//深蓝色
#define LIGHTBLUE   0X7D7C	//浅蓝色  
#define GRAYBLUE    0X5458 //灰蓝色  
#define LIGHTGREEN  0X841F //浅绿色 
#define LGRAY 		0XC618 //浅灰色(PANNEL),窗体背景色 
#define LGRAYBLUE   0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE      0X2B12 //浅棕蓝色(选择条目的反色)

/* 9320/9325 TFT寄存器   --------------------------*/
#define R0             0x00
#define R1             0x01
#define R2             0x02
#define R3             0x03
#define R4             0x04
#define R5             0x05
#define R6             0x06
#define R7             0x07
#define R8             0x08
#define R9             0x09
#define R10            0x0A
#define R12            0x0C
#define R13            0x0D
#define R14            0x0E
#define R15            0x0F
#define R16            0x10
#define R17            0x11
#define R18            0x12
#define R19            0x13
#define R20            0x14
#define R21            0x15
#define R22            0x16
#define R23            0x17
#define R24            0x18
#define R25            0x19
#define R26            0x1A
#define R27            0x1B
#define R28            0x1C
#define R29            0x1D
#define R30            0x1E
#define R31            0x1F
#define R32            0x20
#define R33            0x21
#define R34            0x22
#define R36            0x24
#define R37            0x25
#define R40            0x28
#define R41            0x29
#define R43            0x2B
#define R45            0x2D
#define R48            0x30
#define R49            0x31
#define R50            0x32
#define R51            0x33
#define R52            0x34
#define R53            0x35
#define R54            0x36
#define R55            0x37
#define R56            0x38
#define R57            0x39
#define R59            0x3B
#define R60            0x3C
#define R61            0x3D
#define R62            0x3E
#define R63            0x3F
#define R64            0x40
#define R65            0x41
#define R66            0x42
#define R67            0x43
#define R68            0x44
#define R69            0x45
#define R70            0x46
#define R71            0x47
#define R72            0x48
#define R73            0x49
#define R74            0x4A
#define R75            0x4B
#define R76            0x4C
#define R77            0x4D
#define R78            0x4E
#define R79            0x4F
#define R80            0x50
#define R81            0x51
#define R82            0x52
#define R83            0x53
#define R96            0x60
#define R97            0x61
#define R106           0x6A
#define R118           0x76
#define R128           0x80
#define R129           0x81
#define R130           0x82
#define R131           0x83
#define R132           0x84
#define R133           0x85
#define R134           0x86
#define R135           0x87
#define R136           0x88
#define R137           0x89
#define R139           0x8B
#define R140           0x8C
#define R141           0x8D
#define R143           0x8F
#define R144           0x90
#define R145           0x91
#define R146           0x92
#define R147           0x93
#define R148           0x94
#define R149           0x95
#define R150           0x96
#define R151           0x97
#define R152           0x98
#define R153           0x99
#define R154           0x9A
#define R157           0x9D
#define R192           0xC0
#define R193           0xC1
#define R229           0xE5							  		 
 
 

/* 结构体声明 -----------------------------------------------------------------*/ 
typedef struct  __LCD_PARAMETER
{										    
	u16 width;			//TFT 宽度
	u16 height;			//TFT 高度
	u16 id;				//TFT ID
	u8  dir;			//横屏还是竖屏控制：0，竖屏；1，横屏。	
	u16	 wramcmd;		//开始写gram指令
	u16  setxcmd;		//设置x坐标指令
	u16  setycmd;		//设置y坐标指令	 
}Type_LCD; 	

/* 全局变量声明 ---------------------------------------------------------------*/ 
extern Type_LCD LCD_Param;	//管理TFT重要参数		   
extern u16  TextColor; //文字颜色
extern u16  BackColor; //背景颜色

/* 全局函数声明 ---------------------------------------------------------------*/ 
void TFT_Init(void); 
void TFT_Clear(u16 Color);	  
void TFT_Point_Draw(u16 x,u16 y,u16 color);//画点  
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size);//显示一个字符 
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size);
void LCD_Show0Num(u16 x,u16 y,u32 num,u8 len,u8 size);
void LCD_ShowDecim(u16 x,u16 y,double num,u8 digit,u8 len,u8 size);//长度 包括.在内
void LCD_String_Show(u16 x,u16 y,u8 *p,u8 size);
	
#endif  

/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/





