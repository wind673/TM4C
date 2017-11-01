#include "My_LCD12864.h"

#define SysCtlPeriEnable      SysCtlPeripheralEnable
#define SysCtlPeriDisable     SysCtlPeripheralDisable
#define GPIOPinTypeOut        GPIOPinTypeGPIOOutput
#define GPIOPinTypeIn         GPIOPinTypeGPIOInput
/*******************************************************************************
* LCD12864管脚定义 
* GPIOD(0-3)为控制管脚,依次为SID, CLK
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
* 函数名 : WriteData_LCD12864s
* 功能   : LCD12864串行写数据操作 
* 参数   : value - char - 数据 
* 返回值 : void
*******************************************************************************/
void WriteData_LCD12864s(char value)
{
     unsigned char i;
     //写串口控制11111ABC
     //写11111 
     SID_1();Delay();
     CLK_1();Delay();
     for (i=0;i<5;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }
     //写A = 0，从MCU到LCD
     SID_0();Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     //写B = 1，显示数据 
     SID_1();Delay();
     CLK_0();Delay();
     CLK_1();Delay();  
     //写C = 0
     SID_0();Delay();
     CLK_0();Delay();
     CLK_1();Delay(); 
     //写指令高4位
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
     //写0000 
     SID_0();Delay();
     for (i=0;i<4;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }
     //写指令低4位
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
     //写0000 
     SID_0();Delay();
     for (i=0;i<4;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }     
}
/*******************************************************************************
* 函数名 : WriteCmd_LCD12864s 
* 功能   : LCD12864串行写指令操作 
* 参数   : value - char - 指令 
* 返回值 : void
*******************************************************************************/
void WriteCmd_LCD12864s(char value)
{
     unsigned char i;
     //写串口控制11111ABC
     //写11111 
     SID_1();Delay();
     CLK_1();Delay();
     for (i=0;i<5;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }
     //写A = 0，从MCU到LCD
     SID_0();Delay();
     CLK_0();Delay();
     CLK_1();Delay();
     //写B = 0，控制指令
     SID_0();Delay();
     CLK_0();Delay();
     CLK_1();Delay();  
     //写C = 0
     SID_0();Delay();
     CLK_0();Delay();
     CLK_1();Delay(); 
     //写指令高4位
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
     //写0000 
     SID_0();Delay();
     for (i=0;i<4;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }
     //写指令低4位
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
     //写0000 
     SID_0();Delay();
     for (i=0;i<4;i++)
     {
         CLK_0();Delay();
         CLK_1();Delay();       
     }   
}
/*******************************************************************************
* 函数名 : Init_LCD12864s
* 功能   : LCD12864串行初始化 
* 参数   : void 
* 返回值 : void
*******************************************************************************/           
void Init_LCD12864s(void)
{
     //使能管脚 
  	 SysCtlPeriEnable(LCD_PERIPH);        																			
     //设置管脚为输出 
  	 GPIOPinTypeOut(LCD, LCD_SID|LCD_CLK); 
     //启动等待 
     Delay();
     //写指令,基本指令集 
	 Delay();
     WriteCmd_LCD12864s(0x30);
	 //写指令,地址归位 
	 Delay();
  	 WriteCmd_LCD12864s(0x02);
     //整体显示打开,游标关闭 
	 Delay();
  	 WriteCmd_LCD12864s(0x0c);
     //清除显示 
	 Delay();
  	 WriteCmd_LCD12864s(0x01);
     //游标右移 
	 Delay();
     WriteCmd_LCD12864s(0x06);
     //设定显示的起始位置 
	 Delay();
	 WriteCmd_LCD12864s(0x80);
}
/*******************************************************************************
* 函数名 : Show_LCD12864s
* 功能   : LCD12864字符显示 
* 参数   : address - char - 字符位置
*          length  - char - 字符宽度
*          str[]   - char - 字符数组 
* 返回值 : void
*******************************************************************************/
void Show_LCD12864s(char address,char length,char str[])
{
     char i;	  
     WriteCmd_LCD12864s(address);
     for (i=0; i<length; i++) WriteData_LCD12864s(str[i]);
}
/*******************************************************************************
* 函数名 : Test_LCD12864s
* 功能   : LCD12864串行测试 
* 参数   : void 
* 返回值 : void
*******************************************************************************/
void Test_LCD12864s(void)
{	
	
	Show_LCD12864s(0x80,16,"welcome to 12864");
}





/***************************************************************************************************
 * 描述   : LCD_12864初始化
 * 参数   : 无
 * 返回   : 无
 * 注意   :
 *************************************************************************************************/
void LCD12864_Init(void) {
	SysCtlPeripheralEnable(LCD_CS_PERIPH);
	SysCtlPeripheralEnable(LCD_SID_CLK_PERIPH);
	GPIOPinTypeGPIOOutput(LCD_CS_PORT_BASE, LCD_CS_Pin);
	GPIOPinTypeGPIOOutput(LCD_CLK_PORT_BASE, LCD_CLK_Pin);
	GPIOPinTypeGPIOOutput(LCD_SID_PORT_BASE, LCD_SID_Pin);
	delay_us(500);
	Lcd_Write_Cmd(0x30);        //设置为基本指令模式
	Lcd_Write_Cmd(0x02);        // 地址归位
	Lcd_Write_Cmd(0x0c);        //设置开显示，不显示光标
	Lcd_Write_Cmd(0x06);         //游标右移
	Lcd_Write_Cmd(0x01);        //清屏：显示清0，数据指针清0
	Lcd_Write_Cmd(0x80);        //设定显示的起始地址
	delay_ms(10);
}

/***************************************************************************************************
 * 描述   : LCD_12864清屏
 * 参数   : 无
 * 返回   : 无
 * 注意   :
 *************************************************************************************************/
void LCD_Clear(void) {
	Lcd_Write_Cmd(0x02);        // 地址归位
	Lcd_Write_Cmd(0x0c);        //设置开显示，不显示光标
	Lcd_Write_Cmd(0x06);         //游标右移
	Lcd_Write_Cmd(0x01);        //清屏：显示清0，数据指针清0
	Lcd_Write_Cmd(0x80);        //设定显示的起始地址
	delay_ms(10);
}
/***************************************************************************************************
 * 描述   : LCD_12864 定位函数
 * 参数   : Line:行 Column：列 Column范围 0~7  Line范围 0~3
 * 返回   : 无
 * 注意   :
 *************************************************************************************************/
void LCD_Pos(uint8_t Line, uint8_t Column) {
	uint8_t adr;
	adr = (0x80 + Column);                //计算出x坐标
	switch (Line)                        //计算出y坐标
	{
	case 0:                     	//第1行
		break;
	case 1:                     	//第2行
		adr = adr + 16;
		break;
	case 2:                      	//第3行
		adr = adr + 8;
		break;
	case 3:                     	//第4行
		adr = adr + 24;
		break;
	default:
		break;
	}
	Lcd_Write_Cmd(adr);  //设定DDRAM位址到位址计数器
}
/***************************************************************************************************
 * 描述   : LCD_12864 清除行
 * 参数   : Line  0~3
 * 返回   : 无
 * 注意   :
 *************************************************************************************************/
void LCD_LineClear(uint8_t Line) {
	uint8_t i;
	LCD_Pos(Line, 0);

	for (i = 0; i < 16; i++)
		Lcd_Write_Data(0x20);
}
/***************************************************************************************************
 * 描述   : LCD_12864 清除绘图显示区
 * 参数   : 无
 * 返回   : 无
 * 注意   :
 *************************************************************************************************/
void LCD_Clear_Gdrom(void) {
	uint8_t i, j;
	Lcd_Write_Cmd(0x36);          //绘图显示开 0x36
	for (j = 0; j < 32; j++)			 //上半屏操作
			{
		for (i = 0; i < 8; i++) {
			Lcd_Write_Cmd(0x80 + j);	 //写行地址
			Lcd_Write_Cmd(0x80 + i);	 //写列地址
			Lcd_Write_Data(0x00);	 //连续写入两个空字节
			Lcd_Write_Data(0x00);
		}
	}
	for (j = 0; j < 32; j++)			 //下半屏操作
			{
		for (i = 8; i < 16; i++) {
			Lcd_Write_Cmd(0x80 + j);	 //写行地址
			Lcd_Write_Cmd(0x80 + i);	 //写列地址
			Lcd_Write_Data(0x00);	 //连续写入两个空字节
			Lcd_Write_Data(0x00);
		}

	}
	Lcd_Write_Cmd(0x30);	//绘图显示关，基本指令操作
}
/***************************************************************************************************
 * 描述   : LCD_12864 清除绘图显示区
 * 参数   : 无
 * 返回   : 无
 * 注意   :
 *************************************************************************************************/
void LCD_Display_line(uint8_t Column) {
	uint8_t i, j, line;
	Lcd_Write_Cmd(0x36);          // 绘图显示开 0x36
	line = 63 - Column;
	if (line / 32 == 0)
		j = 0;
	else
		j = 8;
	line %= 32;
	for (i = j + 4; i < j + 8; i++) {
		Lcd_Write_Cmd(0x80 + line);	 // 写行地址
		Lcd_Write_Cmd(0x80 + i);	     // 写列地址
		Lcd_Write_Data(0xff);	     // 连续写入两个空字节
		Lcd_Write_Data(0xff);
	}
	Lcd_Write_Cmd(0x30);	         // 绘图显示关，基本指令操作
}
/***************************************************************************************************
 * 描述   : LCD_12864 X坐标
 * 参数   : 无
 * 返回   : 无
 * 注意   : 位于右半平面
 *************************************************************************************************/
void LCD_Display_X(void) {
	uint8_t i, j, line;
	Lcd_Write_Cmd(0x36);          // 绘图显示开 0x36
	line = 31;
	if (line / 32 == 0)
		j = 0;
	else
		j = 8;
	line %= 32;
	for (i = j + 4; i < j + 8; i++) {
		Lcd_Write_Cmd(0x80 + line);	 // 写行地址
		Lcd_Write_Cmd(0x80 + i);	     // 写列地址
		Lcd_Write_Data(0xff);	     // 连续写入两个空字节
		Lcd_Write_Data(0xff);
	}
	line = 30;
	if (line / 32 == 0)
		j = 0;
	else
		j = 8;
	line %= 32;
	for (i = j + 4; i < j + 8; i++) {
		Lcd_Write_Cmd(0x80 + line);	 // 写行地址
		Lcd_Write_Cmd(0x80 + i);	     // 写列地址
		Lcd_Write_Data(0x11);	     // 连续写入两个空字节
		Lcd_Write_Data(0x11);
	}
	line = 32;
	if (line / 32 == 0)
		j = 0;
	else
		j = 8;
	line %= 32;
	for (i = j + 4; i < j + 8; i++) {
		Lcd_Write_Cmd(0x80 + line);	 // 写行地址
		Lcd_Write_Cmd(0x80 + i);	     // 写列地址
		Lcd_Write_Data(0x11);	     // 连续写入两个空字节
		Lcd_Write_Data(0x11);
	}
	Lcd_Write_Cmd(0x30);	         // 绘图显示关，基本指令操作
}
/***************************************************************************************************
 * 描述   : LCD_12864 Y坐标
 * 参数   : 无
 * 返回   : 无
 * 注意   : 位于右半平面
 *************************************************************************************************/
void LCD_Display_Y(void) {
	uint8_t n, show1, a = 64;
	uint8_t y_byte, y_bit;
	//Lcd_Write_Cmd(0x36);
	Lcd_Write_Cmd(0x34);          //扩展指令集 绘图关闭
	for (n = 0; n < 64; n++) {
		y_byte = (63 - n) / 32;    //判断上下半屏
		y_bit = (63 - n) % 32;    //哪一行
		Lcd_Write_Cmd(0x80 + y_bit); //先写垂直地址
		Lcd_Write_Cmd(0x83 + 8 * y_byte);   //水平坐标
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
 * 描述   : LCD_12864 画竖线
 * 参数   : Column:0~15列，a,b,c,d:一列内有4条线条的高度，最大为64
 * 返回   : 无
 * 注意   :
 *************************************************************************************************/
void LCD_Display_vertical4(uint8_t Column, uint8_t a, uint8_t b, uint8_t c,
		uint8_t d) {
	uint8_t n, show1, show2;
	uint8_t y_byte, y_bit;
	//Lcd_Write_Cmd(0x36);
	Lcd_Write_Cmd(0x34);          //扩展指令集 绘图关闭
	for (n = 0; n < 64; n++) {
		y_byte = (63 - n) / 32;    //判断上下半屏
		y_bit = (63 - n) % 32;    //哪一行
		Lcd_Write_Cmd(0x80 + y_bit); //先写垂直地址
		Lcd_Write_Cmd(0x80 + Column + 8 * y_byte);   //水平坐标
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
 * 描述   : LCD_12864显示字符串
 * 参数   : Line:行 Column：列
 *          汉字：Column范围 0~7   Line范围 0~3
 *          英文：Column范围 0~15  Line范围 0~3
 *           ptr：字符串指针：
 * 返回   : 无
 * 注意   : 汉字：不能超过8个
 *          英文：不能超过16个
 *************************************************************************************************/
void Display_Str(uint8_t Line, uint8_t Column, uint8_t *ptr) {
	LCD_Pos(Line, Column);
	while ((*ptr) != '\0')     //字符串没结束
	{
		Lcd_Write_Data(*ptr++);
	}
}
/***************************************************************************************************
 * 描述   : LCD_12864显示数字
 * 参数   : Line:行 Column：列 Column范围 0~15  Line范围 0~3
 *          num :要显示的数字 范围：0~65536 Size: 指定的输出字段的宽度
 *               如果数据的位数小于Size,则左端补以空格，若大于Size,则按实际位数输出
 * 返回   : 无
 * 注意   :
 *************************************************************************************************/
void LCD_Display_FloatNum(uint8_t Line, uint8_t Column, float num, uint8_t Size) {
	uint8_t ch[12];
	uint8_t Count = 0;     //数据位数
	uint32_t Temp;
	uint32_t Temp1;
	//判断是否是负数
	if (num < 0.00f) {
		num = -num;
		Count++;
		ch[0] = '-';     //负数
	}
	Temp = (uint32_t) (num * 100);     //化为整数,保留3位小数
	ch[11] = 2;     //计数小数位的位数
	//判断是否有小数
	if (ch[11] != 0x00)
		Count++;
	Temp1 = Temp;
	do {
		Temp = Temp / 10;
		Count++;
	} while (Temp);
	//位数控制
	if (Size > Count) {
		if (ch[0] == '-') {
			ch[Size - Count] = '-';    //负号移动
		}
		do {
			Count++;
			ch[Size - Count] = ' ';    //空格填补
		} while (Count != Size);
	}
	ch[Count--] = '\0';
	//如果有小数
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
 * 描述   : LCD_12864显示数字
 * 参数   : Line:行 Column：列 Column范围 0~15  Line范围 0~3
 *          num :要显示的数字 范围：0~65536 Size: 指定的输出字段的宽度
 *               如果数据的位数小于Size,则左端补以空格，若大于Size,则按实际位数输出
 * 返回   : 无
 * 注意   :
 *************************************************************************************************/
void LCD_DisplayNum(uint8_t Line, uint8_t Column, uint16_t num, uint8_t Size) {
	uint8_t ch[5];
	uint8_t Count = 0;
	uint16_t temp = num;
	do {
		temp = temp / 10;
		Count++;
	} while (temp);
	//位数控制
	if (Size > Count) {
		do {
			Count++;
			ch[Size - Count] = ' ';    //空格填补
		} while (Count != Size);
	}
	ch[Count] = '\0';
	ch[--Count] = ' ';    //防止无法显示
	do {
		ch[Count--] = num % 10 + '0';
		num = num / 10;
	} while (num);
	Display_Str(Line, Column, ch);
}

/*****************************************************************************
 * 写入GDRAM
 * Ver:列（0-63）		Hor：行 （0-7）
 * Data1:高位数据		Data2低位数据
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

/*-------------------------底层函数---------------------------------------------------------------*/

/***************************************************************************************************
 * 描述   : 写命令码
 * 参数   : Cmdcode: 命令码
 * 返回   : 无
 * 注意   : static
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
 * 描述   :  向12864写数据
 * 参数   :  Data: 数据
 * 返回   :  无
 * 注意   :
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
 * 描述   :  发送数据流
 * 参数   :  Data: 数据
 * 返回   :  无
 * 注意   :
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







