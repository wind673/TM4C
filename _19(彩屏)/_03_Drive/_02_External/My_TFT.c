/*******************************(C) COPYRIGHT 2016 WindRises（谢玉伸）*********************************/
/**============================================================================
* @FileName    : My_TFT.c
* @Description : TFT2.8寸(ILI9341 IC驱动)
* @Date        : 2016/4/2
* @By          : WindRises（谢玉伸）
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/
/* 头文件包含 -----------------------------------------------------------------*/
#include "My_Labrary.h" 
#include "My_TFT.h" 
#include "My_Delay.h" 
#include "Font.h" 
#include <string.h>

/* 私有宏定义 -----------------------------------------------------------------*/
#if USE_HORIZONTAL==1	//使用横屏
#define TFT_W 320
#define TFT_H 240
#else
#define TFT_W 240	
#define TFT_H 320	
#endif 
  										 

/* 私有变量定义 ---------------------------------------------------------------*/

/* 私有（静态）函数声明 --------------------------------------------------------*/
static void TFT_Param_Set(void);
static void TFT_Windows_Set(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd);
/* 全局变量定义 ---------------------------------------------------------------*/ 
Type_LCD LCD_Param;//管理LCD重要参数 
u16 TextColor = 0x0000;	//画笔颜色
u16 BackColor = 0xFFFF;  //背景色  

/* 私有（静态）函数编写 --------------------------------------------------------*/

/* 全局函数编写 ---------------------------------------------------------------*/
 
/**----------------------------------------------------------------------------   
* @FunctionName  : TFT_REG_Write()     
* @Description   : 写入寄存器
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/
void TFT_REG_Write(u16 Reg)	   
{	
	TFT_RS_L();
	
	TFT_CS_L();   
	
	GPIOPinWrite(GPIO_PORTD_BASE,0xff,Reg>>8); 
	GPIOPinWrite(GPIO_PORTA_BASE,0xff,Reg);
	
	TFT_WR_L();  
	TFT_WR_H();//上升延读取数据
	
	TFT_CS_H();  
} 


/**----------------------------------------------------------------------------
* @FunctionName  : TFT_DATA_Write()     
* @Description   : 写入数据
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/
 void TFT_DATA_Write(u16 Data)  
{
	TFT_RS_H();
	
	TFT_CS_L();
 
	GPIOPinWrite(GPIO_PORTD_BASE,0xff,Data>>8); 
	GPIOPinWrite(GPIO_PORTA_BASE,0xff,Data);
 
	TFT_WR_L();
	TFT_WR_H();//上升延读取数据
	
	TFT_CS_H();
}

 
/**----------------------------------------------------------------------------
* @FunctionName  : TFT_RegData_Write()     
* @Description   : 写入寄存器和数据
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/ 
void TFT_RegData_Write(u16 TFT_Reg, u16 TFT_RegValue)
{
	TFT_REG_Write(TFT_Reg);
	TFT_DATA_Write(TFT_RegValue);
}


/**----------------------------------------------------------------------------
* @FunctionName  : TFT_WR_Prepare()     
* @Description   : 准备写入
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/ 
void TFT_WR_Prepare(void)
{
 	TFT_REG_Write(LCD_Param.wramcmd);	  
}


/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Clear()     
* @Description   : 清屏
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/
void TFT_Clear(u16 Color)
{
	u16 i,j;
	TFT_Windows_Set(0,0,LCD_Param.width-1,LCD_Param.height-1);	
    for(i=0;i<LCD_Param.width;i++)
	 {
	  for (j=0;j<LCD_Param.height;j++)
	   	{
        	 TFT_DATA_Write(Color);
	    }

	  }
}


/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Point_Draw()     
* @Description   : 画点
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/
void TFT_Point_Draw(u16 x,u16 y,u16 color)
{
	TFT_Windows_Set(x,y,x,y);//设置光标位置 
	TFT_DATA_Write(TextColor); 	    
} 	 


/**----------------------------------------------------------------------------
* @FunctionName  : TFT_GPIOInit()     
* @Description   : IO口初始化
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/
void TFT_GPIOInit(void)
{
	 
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	 GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3); 
	 GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0);
	
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
	 GPIOPinTypeGPIOOutput(GPIO_PORTJ_BASE,GPIO_PIN_2); 
	 GPIOPinWrite(GPIO_PORTJ_BASE,GPIO_PIN_2,0);
	
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);  //低8位
	 GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,0xff); 
	 GPIOPinWrite(GPIO_PORTA_BASE,0xff,0);
	
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);  //高8位 
	 GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,0xff); 
	 GPIOPinWrite(GPIO_PORTD_BASE,0xff,0);
	 
	 
} 

/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Init()     
* @Description   : TFT初始化
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/ 
void TFT_Init(void)
{ 
	TFT_GPIOInit();
	TFT_RD_H();	 //RD引脚没有用到，拉高处理
	
	//=========================液晶屏初始化=============================//
	TFT_REG_Write(0xCF);  
	TFT_DATA_Write(0x00); 
	TFT_DATA_Write(0xC1); 
	TFT_DATA_Write(0X30); 
	TFT_REG_Write(0xED);  
	TFT_DATA_Write(0x64); 
	TFT_DATA_Write(0x03); 
	TFT_DATA_Write(0X12); 
	TFT_DATA_Write(0X81); 
	TFT_REG_Write(0xE8);  
	TFT_DATA_Write(0x85); 
	TFT_DATA_Write(0x10); 
	TFT_DATA_Write(0x7A); 
	TFT_REG_Write(0xCB);  
	TFT_DATA_Write(0x39); 
	TFT_DATA_Write(0x2C); 
	TFT_DATA_Write(0x00); 
	TFT_DATA_Write(0x34); 
	TFT_DATA_Write(0x02); 
	TFT_REG_Write(0xF7);  
	TFT_DATA_Write(0x20); 
	TFT_REG_Write(0xEA);  
	TFT_DATA_Write(0x00); 
	TFT_DATA_Write(0x00); 
	TFT_REG_Write(0xC0);    //Power control 
	TFT_DATA_Write(0x1B);   //VRH[5:0] 
	TFT_REG_Write(0xC1);    //Power control 
	TFT_DATA_Write(0x01);   //SAP[2:0];BT[3:0] 
	TFT_REG_Write(0xC5);    //VCM control 
	TFT_DATA_Write(0x30); 	 //3F
	TFT_DATA_Write(0x30); 	 //3C
	TFT_REG_Write(0xC7);    //VCM control2 
	TFT_DATA_Write(0XB7); 
	TFT_REG_Write(0x36);    // Memory Access Control 
	TFT_DATA_Write(0x48); 
	TFT_REG_Write(0x3A);   
	TFT_DATA_Write(0x55); 
	TFT_REG_Write(0xB1);   
	TFT_DATA_Write(0x00);   
	TFT_DATA_Write(0x1A); 
	TFT_REG_Write(0xB6);    // Display Function Control 
	TFT_DATA_Write(0x0A); 
	TFT_DATA_Write(0xA2); 
	TFT_REG_Write(0xF2);    // 3Gamma Function Disable 
	TFT_DATA_Write(0x00); 
	TFT_REG_Write(0x26);    //Gamma curve selected 
	TFT_DATA_Write(0x01); 
	TFT_REG_Write(0xE0);    //Set Gamma 
	TFT_DATA_Write(0x0F); 
	TFT_DATA_Write(0x2A); 
	TFT_DATA_Write(0x28); 
	TFT_DATA_Write(0x08); 
	TFT_DATA_Write(0x0E); 
	TFT_DATA_Write(0x08); 
	TFT_DATA_Write(0x54); 
	TFT_DATA_Write(0XA9); 
	TFT_DATA_Write(0x43); 
	TFT_DATA_Write(0x0A); 
	TFT_DATA_Write(0x0F); 
	TFT_DATA_Write(0x00); 
	TFT_DATA_Write(0x00); 
	TFT_DATA_Write(0x00); 
	TFT_DATA_Write(0x00); 		 
	TFT_REG_Write(0XE1);    //Set Gamma 
	TFT_DATA_Write(0x00); 
	TFT_DATA_Write(0x15); 
	TFT_DATA_Write(0x17); 
	TFT_DATA_Write(0x07); 
	TFT_DATA_Write(0x11); 
	TFT_DATA_Write(0x06); 
	TFT_DATA_Write(0x2B); 
	TFT_DATA_Write(0x56); 
	TFT_DATA_Write(0x3C); 
	TFT_DATA_Write(0x05); 
	TFT_DATA_Write(0x10); 
	TFT_DATA_Write(0x0F); 
	TFT_DATA_Write(0x3F); 
	TFT_DATA_Write(0x3F); 
	TFT_DATA_Write(0x0F); 
	TFT_REG_Write(0x2B); 
	TFT_DATA_Write(0x00);
	TFT_DATA_Write(0x00);
	TFT_DATA_Write(0x01);
	TFT_DATA_Write(0x3f);
	TFT_REG_Write(0x2A); 
	TFT_DATA_Write(0x00);
	TFT_DATA_Write(0x00);
	TFT_DATA_Write(0x00);
	TFT_DATA_Write(0xef);	 
	TFT_REG_Write(0x11); //Exit Sleep
//	delay_ms(120);
	TFT_REG_Write(0x29); //display on 
	
	//设置LCD属性参数
	TFT_Param_Set();//设置LCD参数	 
	TFT_LED_ON();//点亮背光	 
}
/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Windows_Set()     
* @Description   : 设置显示窗口，窗口内可自动换行
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/ 
static void TFT_Windows_Set(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd)
{	
	TFT_REG_Write(LCD_Param.setxcmd);	
	TFT_DATA_Write(xStar>>8);
	TFT_DATA_Write(0x00FF&xStar);		
	TFT_DATA_Write(xEnd>>8);
	TFT_DATA_Write(0x00FF&xEnd);

	TFT_REG_Write(LCD_Param.setycmd);	
	TFT_DATA_Write(yStar>>8);
	TFT_DATA_Write(0x00FF&yStar);		
	TFT_DATA_Write(yEnd>>8);
	TFT_DATA_Write(0x00FF&yEnd);	

	TFT_WR_Prepare();	//开始写入GRAM				
}   


/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Cursor_Set()     
* @Description   : 设置光标位置
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/ 
void TFT_Cursor_Set(u16 Xpos, u16 Ypos)
{	  	    			
	TFT_REG_Write(LCD_Param.setxcmd);	
	TFT_DATA_Write(Xpos>>8);
	TFT_DATA_Write(0x00FF&Xpos);		

	
	TFT_REG_Write(LCD_Param.setycmd);	
	TFT_DATA_Write(Ypos>>8);
	TFT_DATA_Write(0x00FF&Ypos);		

	TFT_WR_Prepare();	//开始写入GRAM	
} 


 
/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Param_Set()     
* @Description   : 设置LCD参数
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/ 
static void TFT_Param_Set(void)
{ 	
	LCD_Param.wramcmd=0x2C;
#if USE_HORIZONTAL==1	//使用横屏	  
	LCD_Param.dir=1;//横屏
	LCD_Param.width=320;
	LCD_Param.height=240;
	LCD_Param.setxcmd=0x2A;
	LCD_Param.setycmd=0x2B;			
	TFT_RegData_Write(0x36,0x6C);

#else//竖屏
	LCD_Param.dir=0;//竖屏				 	 		
	LCD_Param.width=240;
	LCD_Param.height=320;
	LCD_Param.setxcmd=0x2A;
	LCD_Param.setycmd=0x2B;	
	TFT_RegData_Write(0x36,0x0A);
#endif
}


 
/**----------------------------------------------------------------------------
* @FunctionName  : LCD_ShowChar()     
* @Description   : 显示一个字符
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises（谢玉伸）
* @Data          : 2016/4/2
* @Explain       : size:字体大小 12/16/24
------------------------------------------------------------------------------*/ 
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size)
{  							  
    u8 temp,t1,t;
	u16 y0=y; 
	u8 csize=(size/8+((size%8)?1:0))*(size/2);		//得到字体一个字符对应点阵集所占的字节数	
	//设置窗口		   
	num=num-' ';//得到偏移后的值
	for(t=0;t<csize;t++)
	{   
		if(size == 12)temp = asc2_1206[num][t]; 	 	//调用1206字体
		else if(size == 16)temp = asc2_1608[num][t];	//调用1608字体
		else if(size == 24)temp = asc2_2412[num][t];	//调用2412字体
		else return;								//没有的字库
		for(t1=0;t1<8;t1++) 
		{			    
			if(temp&0x80)TFT_Point_Draw(x,y,TextColor);
			 
			temp<<=1;
			y++;
			if(y>=LCD_Param.height)return;		//超区域了
			if((y-y0)==size)
			{
				y=y0;
				x++;
				if(x>=LCD_Param.width)return;	//超区域了
				break;
			}
		}  	 
	}  	    	   	 	  
}  


//m^n函数
//返回值:m^n次方.
u32 LCD_Pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}			 
//显示数字,高位为0,则不显示
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小 12/16/24
//color:颜色 
//num:数值(0~4294967295);	 
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+(size/2)*t,y,' ',size);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size); 
	}
} 


//显示数字,高位为0,还是显示
//x,y:起点坐标
//num:数值(0~999999999);	 
//len:长度(即要显示的位数)
//size:字体大小12/16/24
//mode:
//[7]:0,不填充;1,填充0.
//[6:1]:保留
//[0]:0,非叠加显示;1,叠加显示.
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size)
{  
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				
				LCD_ShowChar(x+(size/2)*t,y,' ',size);  
 				
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size); 
	}
} 


//显示数字,高位为0
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小 12/16/24
//color:颜色 
//num:数值(0~4294967295);	 
void LCD_Show0Num(u16 x,u16 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+(size/2)*t,y,'0',size);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size); 
	}
} 




//显示字符串
//x,y:起点坐标
//width,height:区域大小  
//size:字体大小12/16/24
//*p:字符串起始地址		
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p)
{         
	u8 x0=x;
	width+=x;
	height+=y;
    while((*p<='~')&&(*p>=' '))//判断是不是非法字符!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//退出
        LCD_ShowChar(x,y,*p,size);
        x+=size/2;
        p++;
    }  
}


//显示小数
//x,y:起点坐标
//digit:保留位数
//size:字体大小  12/16/24
void LCD_ShowDecim(u16 x,u16 y,double num,u8 digit,u8 len,u8 size)//长度 包括.在内
{ 
	
	u32 digitnum=LCD_Pow(10,digit);                              
	u32 numd=(u32)(num*digitnum);     	                   
	u32 temp;                                               
	len=len-digit-1;
	temp=numd/digitnum;
	LCD_ShowxNum(x,y,temp,len,size);//显示整数部分
	temp=(u32)(numd-((double)(numd/digitnum)*digitnum));
	LCD_ShowString(x+len*(size/2),y,size,size,size,(u8*)".");
	LCD_Show0Num(x+(len+1)*(size/2),y,temp,digit,size);//显示小数部分


} 




void LCD_String_Show(u16 x,u16 y,u8 *p,u8 size)
{ 
	LCD_ShowString(x,y,size *( strlen((char*)p) ),size,size,p); 
	
	
}



