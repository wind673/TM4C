#include "My_LCD12864.h"

#define SysCtlPeriEnable      SysCtlPeripheralEnable
#define SysCtlPeriDisable     SysCtlPeripheralDisable
#define GPIOPinTypeOut        GPIOPinTypeGPIOOutput
#define GPIOPinTypeIn         GPIOPinTypeGPIOInput
/*******************************************************************************
* LCD12864�ܽŶ��� 
* GPIOD(0-3)Ϊ���ƹܽ�,����ΪSID, CLK
*******************************************************************************/
#define LCD                   GPIO_PORTD_BASE
//#define LCD_PORT
#define LCD_PERIPH            SYSCTL_PERIPH_GPIOD  
#define LCD_SID               GPIO_PIN_0
#define LCD_CLK               GPIO_PIN_1
#define SID_0()               GPIOPinWrite(LCD, LCD_SID,  0x00)
#define SID_1()               GPIOPinWrite(LCD, LCD_SID,  0xff)
#define CLK_0()               GPIOPinWrite(LCD, LCD_CLK,  0x00)
#define CLK_1()               GPIOPinWrite(LCD, LCD_CLK,  0xff)
#define Delay()               SysCtlDelay(10)
#define LCD_Interval_Delay 75
#define LCD_CS_PERIPH		SYSCTL_PERIPH_GPIOC
#define LCD_SID_CLK_PERIPH	SYSCTL_PERIPH_GPIOH
#define LCD_CS_PORT_BASE	GPIO_PORTC_BASE
#define LCD_CLK_PORT_BASE	GPIO_PORTH_BASE
#define LCD_SID_PORT_BASE	GPIO_PORTH_BASE
#define LCD_CS_Pin			GPIO_PIN_6			// RS	CS
#define LCD_CLK_Pin			GPIO_PIN_0			// E	CLK
#define LCD_SID_Pin			GPIO_PIN_3			// R/W	SID
#define LCD_CS1		GPIOPinWrite(LCD_CS_PORT_BASE, LCD_CS_Pin,0xff)
#define LCD_CS0		GPIOPinWrite(LCD_CS_PORT_BASE, LCD_CS_Pin,0x00)
#define LCD_CLK1	GPIOPinWrite(LCD_CLK_PORT_BASE, LCD_CLK_Pin,0xff)
#define LCD_CLK0	GPIOPinWrite(LCD_CLK_PORT_BASE, LCD_CLK_Pin,0x00)
#define LCD_DAT1	GPIOPinWrite(LCD_SID_PORT_BASE, LCD_SID_Pin,0xff)
#define LCD_DAT0	GPIOPinWrite(LCD_SID_PORT_BASE, LCD_SID_Pin, 0x00)
#define LCD_DAT_OUT	GPIOPinTypeGPIOOutput(LCD_SID_PORT_BASE, LCD_SID_Pin);
#define LCD_DAT_IN	GPIOPinTypeGPIOInput(LCD_SID_PORT_BASE, LCD_SID_Pin);

static void LCD_SendByte(uint8_t Data);
static void Lcd_Write_Data(uint8_t Data);
static void Lcd_Write_Cmd(uint8_t Cmdcode);



/*******************************************************************************
* ������ : WriteData_LCD12864s
* ����   : LCD12864����д���ݲ��� 
* ����   : value - char - ���� 
* ����ֵ : void
*******************************************************************************/
void WriteData_LCD12864s(char value)
{
     unsigned char i;
     //д���ڿ���11111ABC
     //д11111 
     SID_1();Delay();
     CLK_1();Delay();
     for (i=0;i<5;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }
     //дA = 0����MCU��LCD
     SID_0();Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     //дB = 1����ʾ���� 
     SID_1();Delay();
     CLK_0();Delay();
     CLK_1();Delay();  
     //дC = 0
     SID_0();Delay();
     CLK_0();Delay();
     CLK_1();Delay(); 
     //дָ���4λ
     if (value&0x80) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x40) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x20) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x10) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     //д0000 
     SID_0();Delay();
     for (i=0;i<4;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }
     //дָ���4λ
     if (value&0x08) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x04) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x02) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x01) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     //д0000 
     SID_0();Delay();
     for (i=0;i<4;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }     
}
/*******************************************************************************
* ������ : WriteCmd_LCD12864s 
* ����   : LCD12864����дָ����� 
* ����   : value - char - ָ�� 
* ����ֵ : void
*******************************************************************************/
void WriteCmd_LCD12864s(char value)
{
     unsigned char i;
     //д���ڿ���11111ABC
     //д11111 
     SID_1();Delay();
     CLK_1();Delay();
     for (i=0;i<5;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }
     //дA = 0����MCU��LCD
     SID_0();Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     //дB = 0������ָ��
     SID_0();Delay();
     CLK_0();Delay();
     CLK_1();Delay();  
     //дC = 0
     SID_0();Delay();
     CLK_0();Delay();
     CLK_1();Delay(); 
     //дָ���4λ
     if (value&0x80) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x40) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x20) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x10) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     //д0000 
     SID_0();Delay();
     for (i=0;i<4;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }
     //дָ���4λ
     if (value&0x08) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x04) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x02) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     if (value&0x01) SID_1();
     else            SID_0();
     Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     //д0000 
     SID_0();Delay();
     for (i=0;i<4;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }   
}
/*******************************************************************************
* ������ : Init_LCD12864s
* ����   : LCD12864���г�ʼ�� 
* ����   : void 
* ����ֵ : void
*******************************************************************************/           
void Init_LCD12864s(void)
{
     //ʹ�ܹܽ� 
  	 SysCtlPeriEnable(LCD_PERIPH);        																			
     //���ùܽ�Ϊ��� 
  	 GPIOPinTypeOut(LCD, LCD_SID|LCD_CLK); 
     //�����ȴ� 
     Delay();
     //дָ��,����ָ� 
	 Delay();
     WriteCmd_LCD12864s(0x30);
	 //дָ��,��ַ��λ 
	 Delay();
  	 WriteCmd_LCD12864s(0x02);
     //������ʾ��,�α�ر� 
	 Delay();
  	 WriteCmd_LCD12864s(0x0c);
     //�����ʾ 
	 Delay();
  	 WriteCmd_LCD12864s(0x01);
     //�α����� 
	 Delay();
     WriteCmd_LCD12864s(0x06);
     //�趨��ʾ����ʼλ�� 
	 Delay();
	 WriteCmd_LCD12864s(0x80);
}
/*******************************************************************************
* ������ : Show_LCD12864s
* ����   : LCD12864�ַ���ʾ 
* ����   : address - char - �ַ�λ��
*          length  - char - �ַ����
*          str[]   - char - �ַ����� 
* ����ֵ : void
*******************************************************************************/
void Show_LCD12864s(char address,char length,char str[])
{
     char i;	  
     WriteCmd_LCD12864s(address);
     for (i=0; i<length; i++) WriteData_LCD12864s(str[i]);
}
/*******************************************************************************
* ������ : Test_LCD12864s
* ����   : LCD12864���в��� 
* ����   : void 
* ����ֵ : void
*******************************************************************************/
void Test_LCD12864s(void)
{	
	
	Show_LCD12864s(0x80,16,"welcome to 12864");
}





/***************************************************************************************************
 * ����   : LCD_12864��ʼ��
 * ����   : ��
 * ����   : ��
 * ע��   :
 *************************************************************************************************/
void LCD12864_Init(void) {
	SysCtlPeripheralEnable(LCD_CS_PERIPH);
	SysCtlPeripheralEnable(LCD_SID_CLK_PERIPH);
	GPIOPinTypeGPIOOutput(LCD_CS_PORT_BASE, LCD_CS_Pin);
	GPIOPinTypeGPIOOutput(LCD_CLK_PORT_BASE, LCD_CLK_Pin);
	GPIOPinTypeGPIOOutput(LCD_SID_PORT_BASE, LCD_SID_Pin);
	delay_us(500);
	Lcd_Write_Cmd(0x30);        //����Ϊ����ָ��ģʽ
	Lcd_Write_Cmd(0x02);        // ��ַ��λ
	Lcd_Write_Cmd(0x0c);        //���ÿ���ʾ������ʾ���
	Lcd_Write_Cmd(0x06);         //�α�����
	Lcd_Write_Cmd(0x01);        //��������ʾ��0������ָ����0
	Lcd_Write_Cmd(0x80);        //�趨��ʾ����ʼ��ַ
	delay_ms(10);
}

/***************************************************************************************************
 * ����   : LCD_12864����
 * ����   : ��
 * ����   : ��
 * ע��   :
 *************************************************************************************************/
void LCD_Clear(void) {
	Lcd_Write_Cmd(0x02);        // ��ַ��λ
	Lcd_Write_Cmd(0x0c);        //���ÿ���ʾ������ʾ���
	Lcd_Write_Cmd(0x06);         //�α�����
	Lcd_Write_Cmd(0x01);        //��������ʾ��0������ָ����0
	Lcd_Write_Cmd(0x80);        //�趨��ʾ����ʼ��ַ
	delay_ms(10);
}
/***************************************************************************************************
 * ����   : LCD_12864 ��λ����
 * ����   : Line:�� Column���� Column��Χ 0~7  Line��Χ 0~3
 * ����   : ��
 * ע��   :
 *************************************************************************************************/
void LCD_Pos(uint8_t Line, uint8_t Column) {
	uint8_t adr;
	adr = (0x80 + Column);                //�����x����
	switch (Line)                        //�����y����
	{
	case 0:                     	//��1��
		break;
	case 1:                     	//��2��
		adr = adr + 16;
		break;
	case 2:                      	//��3��
		adr = adr + 8;
		break;
	case 3:                     	//��4��
		adr = adr + 24;
		break;
	default:
		break;
	}
	Lcd_Write_Cmd(adr);  //�趨DDRAMλַ��λַ������
}
/***************************************************************************************************
 * ����   : LCD_12864 �����
 * ����   : Line  0~3
 * ����   : ��
 * ע��   :
 *************************************************************************************************/
void LCD_LineClear(uint8_t Line) {
	uint8_t i;
	LCD_Pos(Line, 0);

	for (i = 0; i < 16; i++)
		Lcd_Write_Data(0x20);
}
/***************************************************************************************************
 * ����   : LCD_12864 �����ͼ��ʾ��
 * ����   : ��
 * ����   : ��
 * ע��   :
 *************************************************************************************************/
void LCD_Clear_Gdrom(void) {
	uint8_t i, j;
	Lcd_Write_Cmd(0x36);          //��ͼ��ʾ�� 0x36
	for (j = 0; j < 32; j++)			 //�ϰ�������
			{
		for (i = 0; i < 8; i++) {
			Lcd_Write_Cmd(0x80 + j);	 //д�е�ַ
			Lcd_Write_Cmd(0x80 + i);	 //д�е�ַ
			Lcd_Write_Data(0x00);	 //����д���������ֽ�
			Lcd_Write_Data(0x00);
		}
	}
	for (j = 0; j < 32; j++)			 //�°�������
			{
		for (i = 8; i < 16; i++) {
			Lcd_Write_Cmd(0x80 + j);	 //д�е�ַ
			Lcd_Write_Cmd(0x80 + i);	 //д�е�ַ
			Lcd_Write_Data(0x00);	 //����д���������ֽ�
			Lcd_Write_Data(0x00);
		}

	}
	Lcd_Write_Cmd(0x30);	//��ͼ��ʾ�أ�����ָ�����
}
/***************************************************************************************************
 * ����   : LCD_12864 �����ͼ��ʾ��
 * ����   : ��
 * ����   : ��
 * ע��   :
 *************************************************************************************************/
void LCD_Display_line(uint8_t Column) {
	uint8_t i, j, line;
	Lcd_Write_Cmd(0x36);          // ��ͼ��ʾ�� 0x36
	line = 63 - Column;
	if (line / 32 == 0)
		j = 0;
	else
		j = 8;
	line %= 32;
	for (i = j + 4; i < j + 8; i++) {
		Lcd_Write_Cmd(0x80 + line);	 // д�е�ַ
		Lcd_Write_Cmd(0x80 + i);	     // д�е�ַ
		Lcd_Write_Data(0xff);	     // ����д���������ֽ�
		Lcd_Write_Data(0xff);
	}
	Lcd_Write_Cmd(0x30);	         // ��ͼ��ʾ�أ�����ָ�����
}
/***************************************************************************************************
 * ����   : LCD_12864 X����
 * ����   : ��
 * ����   : ��
 * ע��   : λ���Ұ�ƽ��
 *************************************************************************************************/
void LCD_Display_X(void) {
	uint8_t i, j, line;
	Lcd_Write_Cmd(0x36);          // ��ͼ��ʾ�� 0x36
	line = 31;
	if (line / 32 == 0)
		j = 0;
	else
		j = 8;
	line %= 32;
	for (i = j + 4; i < j + 8; i++) {
		Lcd_Write_Cmd(0x80 + line);	 // д�е�ַ
		Lcd_Write_Cmd(0x80 + i);	     // д�е�ַ
		Lcd_Write_Data(0xff);	     // ����д���������ֽ�
		Lcd_Write_Data(0xff);
	}
	line = 30;
	if (line / 32 == 0)
		j = 0;
	else
		j = 8;
	line %= 32;
	for (i = j + 4; i < j + 8; i++) {
		Lcd_Write_Cmd(0x80 + line);	 // д�е�ַ
		Lcd_Write_Cmd(0x80 + i);	     // д�е�ַ
		Lcd_Write_Data(0x11);	     // ����д���������ֽ�
		Lcd_Write_Data(0x11);
	}
	line = 32;
	if (line / 32 == 0)
		j = 0;
	else
		j = 8;
	line %= 32;
	for (i = j + 4; i < j + 8; i++) {
		Lcd_Write_Cmd(0x80 + line);	 // д�е�ַ
		Lcd_Write_Cmd(0x80 + i);	     // д�е�ַ
		Lcd_Write_Data(0x11);	     // ����д���������ֽ�
		Lcd_Write_Data(0x11);
	}
	Lcd_Write_Cmd(0x30);	         // ��ͼ��ʾ�أ�����ָ�����
}
/***************************************************************************************************
 * ����   : LCD_12864 Y����
 * ����   : ��
 * ����   : ��
 * ע��   : λ���Ұ�ƽ��
 *************************************************************************************************/
void LCD_Display_Y(void) {
	uint8_t n, show1, a = 64;
	uint8_t y_byte, y_bit;
	//Lcd_Write_Cmd(0x36);
	Lcd_Write_Cmd(0x34);          //��չָ� ��ͼ�ر�
	for (n = 0; n < 64; n++) {
		y_byte = (63 - n) / 32;    //�ж����°���
		y_bit = (63 - n) % 32;    //��һ��
		Lcd_Write_Cmd(0x80 + y_bit); //��д��ֱ��ַ
		Lcd_Write_Cmd(0x83 + 8 * y_byte);   //ˮƽ����
		show1 = 0;
		if (a > 0)
			show1 |= 0x01;
		if (a % 4 == 0)
			show1 |= 0x06;
		Lcd_Write_Data(0x00); //1111
		Lcd_Write_Data(show1);
		if (a > 0) {
			a--;
		}
	}
	Lcd_Write_Cmd(0x36);
	Lcd_Write_Cmd(0x30);
}
/***************************************************************************************************
 * ����   : LCD_12864 ������
 * ����   : Column:0~15�У�a,b,c,d:һ������4�������ĸ߶ȣ����Ϊ64
 * ����   : ��
 * ע��   :
 *************************************************************************************************/
void LCD_Display_vertical4(uint8_t Column, uint8_t a, uint8_t b, uint8_t c,
		uint8_t d) {
	uint8_t n, show1, show2;
	uint8_t y_byte, y_bit;
	//Lcd_Write_Cmd(0x36);
	Lcd_Write_Cmd(0x34);          //��չָ� ��ͼ�ر�
	for (n = 0; n < 64; n++) {
		y_byte = (63 - n) / 32;    //�ж����°���
		y_bit = (63 - n) % 32;    //��һ��
		Lcd_Write_Cmd(0x80 + y_bit); //��д��ֱ��ַ
		Lcd_Write_Cmd(0x80 + Column + 8 * y_byte);   //ˮƽ����
		show1 = 0;
		show2 = 0;
		if (a > 0)
			show1 |= 0x80;
		if (b > 0)
			show1 |= 0x08;
		if (c > 0)
			show2 |= 0x80;
		if (d > 0)
			show2 |= 0x08;
		Lcd_Write_Data(show1); //1111
		Lcd_Write_Data(show2);
		if (a > 0) {
			a--;
		}
		if (b > 0) {
			b--;
		}
		if (c > 0) {
			c--;
		}
		if (d > 0) {
			d--;
		}
	}
	Lcd_Write_Cmd(0x36);
	Lcd_Write_Cmd(0x30);
}
/***************************************************************************************************
 * ����   : LCD_12864��ʾ�ַ���
 * ����   : Line:�� Column����
 *          ���֣�Column��Χ 0~7   Line��Χ 0~3
 *          Ӣ�ģ�Column��Χ 0~15  Line��Χ 0~3
 *           ptr���ַ���ָ�룺
 * ����   : ��
 * ע��   : ���֣����ܳ���8��
 *          Ӣ�ģ����ܳ���16��
 *************************************************************************************************/
void Display_Str(uint8_t Line, uint8_t Column, uint8_t *ptr) {
	LCD_Pos(Line, Column);
	while ((*ptr) != '\0')     //�ַ���û����
	{
		Lcd_Write_Data(*ptr++);
	}
}
/***************************************************************************************************
 * ����   : LCD_12864��ʾ����
 * ����   : Line:�� Column���� Column��Χ 0~15  Line��Χ 0~3
 *          num :Ҫ��ʾ������ ��Χ��0~65536 Size: ָ��������ֶεĿ��
 *               ������ݵ�λ��С��Size,����˲��Կո�������Size,��ʵ��λ�����
 * ����   : ��
 * ע��   :
 *************************************************************************************************/
void LCD_Display_FloatNum(uint8_t Line, uint8_t Column, float num, uint8_t Size) {
	uint8_t ch[12];
	uint8_t Count = 0;     //����λ��
	uint32_t Temp;
	uint32_t Temp1;
	//�ж��Ƿ��Ǹ���
	if (num < 0.00f) {
		num = -num;
		Count++;
		ch[0] = '-';     //����
	}
	Temp = (uint32_t) (num * 100);     //��Ϊ����,����3λС��
	ch[11] = 2;     //����С��λ��λ��
	//�ж��Ƿ���С��
	if (ch[11] != 0x00)
		Count++;
	Temp1 = Temp;
	do {
		Temp = Temp / 10;
		Count++;
	} while (Temp);
	//λ������
	if (Size > Count) {
		if (ch[0] == '-') {
			ch[Size - Count] = '-';    //�����ƶ�
		}
		do {
			Count++;
			ch[Size - Count] = ' ';    //�ո��
		} while (Count != Size);
	}
	ch[Count--] = '\0';
	//�����С��
	if (ch[11] != 0) {
		Temp = ch[11];
		do {
			Temp--;
			ch[Count--] = Temp1 % 10 + '0';
			Temp1 = Temp1 / 10;
		} while (Temp != 0);
		ch[Count--] = '.';
	}
	do {
		ch[Count--] = Temp1 % 10 + '0';
		Temp1 = Temp1 / 10;
	} while (Temp1);
	Display_Str(Line, Column, ch);

}
/***************************************************************************************************
 * ����   : LCD_12864��ʾ����
 * ����   : Line:�� Column���� Column��Χ 0~15  Line��Χ 0~3
 *          num :Ҫ��ʾ������ ��Χ��0~65536 Size: ָ��������ֶεĿ��
 *               ������ݵ�λ��С��Size,����˲��Կո�������Size,��ʵ��λ�����
 * ����   : ��
 * ע��   :
 *************************************************************************************************/
void LCD_DisplayNum(uint8_t Line, uint8_t Column, uint16_t num, uint8_t Size) {
	uint8_t ch[5];
	uint8_t Count = 0;
	uint16_t temp = num;
	do {
		temp = temp / 10;
		Count++;
	} while (temp);
	//λ������
	if (Size > Count) {
		do {
			Count++;
			ch[Size - Count] = ' ';    //�ո��
		} while (Count != Size);
	}
	ch[Count] = '\0';
	ch[--Count] = ' ';    //��ֹ�޷���ʾ
	do {
		ch[Count--] = num % 10 + '0';
		num = num / 10;
	} while (num);
	Display_Str(Line, Column, ch);
}

/*****************************************************************************
 * д��GDRAM
 * Ver:�У�0-63��		Hor���� ��0-7��
 * Data1:��λ����		Data2��λ����
 *****************************************************************************/
void LCD_WriteGrap(int8_t Ver, int8_t Hor, int8_t Data1, int8_t Data2) {
	if ((Ver) / 32) {
		Hor += 8;
		Ver -= 32;
	}
	Lcd_Write_Cmd(0x36);
	Lcd_Write_Cmd(0x80 + Ver);
	Lcd_Write_Cmd(0x80 + Hor);
	Lcd_Write_Data(Data1);
	Lcd_Write_Data(Data2);
	Lcd_Write_Cmd(0x30);
}

/*-------------------------�ײ㺯��---------------------------------------------------------------*/

/***************************************************************************************************
 * ����   : д������
 * ����   : Cmdcode: ������
 * ����   : ��
 * ע��   : static
 *************************************************************************************************/
static void Lcd_Write_Cmd(uint8_t Cmdcode) {
	LCD_CS1;
	LCD_SendByte(0xf8);
	LCD_SendByte(Cmdcode & 0xf0);
	LCD_SendByte((Cmdcode << 4) & 0xf0);
	delay_us(LCD_Interval_Delay);
	LCD_CS0;
	delay_us(LCD_Interval_Delay);
}
/***************************************************************************************************
 * ����   :  ��12864д����
 * ����   :  Data: ����
 * ����   :  ��
 * ע��   :
 *************************************************************************************************/
static void Lcd_Write_Data(uint8_t Data) {
	LCD_CS1;
	LCD_SendByte(0xfa);
	LCD_SendByte(Data & 0xf0);
	LCD_SendByte((Data << 4) & 0xf0);
	delay_us(LCD_Interval_Delay);
	LCD_CS0;
	delay_us(LCD_Interval_Delay);
}
/***************************************************************************************************
 * ����   :  ����������
 * ����   :  Data: ����
 * ����   :  ��
 * ע��   :
 *************************************************************************************************/
static void LCD_SendByte(uint8_t Data) {
	uint8_t i;
	for (i = 0; i < 8; i++) {
		if ((Data << i) & 0x80) {
			LCD_DAT1;
		} else {
			LCD_DAT0;
		}
		LCD_CLK0;
		LCD_CLK1;
	}
}







