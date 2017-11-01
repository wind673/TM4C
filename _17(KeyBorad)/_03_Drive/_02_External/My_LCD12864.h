#ifndef __MY_LCD12864_H_
#define __MY_LCD12864_H_
#include "My_Labrary.h"
#include "My_Delay.h" 

void Init_LCD12864s(void);
void Test_LCD12864s(void);
void Show_LCD12864s(char address,char length,char str[]);
void WriteData_LCD12864s(char value);
void WriteCmd_LCD12864s(char value);
void LCD12864_Init(void);
void LCD_Grap_Init(void);
void LCD_ClenGrap(void) ;
void LCD_Clear_Gdrom(void);
void LCD_Clear(void);
void LCD_LineClear(uint8_t Line);
void LCD_Pos(uint8_t Line,uint8_t Column);
void Display_Str(uint8_t Line,uint8_t Column, uint8_t *ptr);
void LCD_Display_Point8(uint8_t Column,uint8_t *a);
void LCD_Display_Y(void);
void LCD_Display_X(void);
void LCD_Display_line(uint8_t Column);
void LCD_Display_vertical4(uint8_t Column,uint8_t a,uint8_t b,uint8_t c,uint8_t d);
void LCD_DisplayNum(uint8_t Line,uint8_t Column, uint16_t num,uint8_t Size);
void LCD_Display_FloatNum(uint8_t Line,uint8_t Column, float num,uint8_t Size);
void LCD_WriteGrap(int8_t Ver , int8_t Hor , int8_t Data1, int8_t Data2) ;
void LCD_ClenGrap(void) ;

#endif 


