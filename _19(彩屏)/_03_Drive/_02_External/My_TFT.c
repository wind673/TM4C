/*******************************(C) COPYRIGHT 2016 WindRises��л���죩*********************************/
/**============================================================================
* @FileName    : My_TFT.c
* @Description : TFT2.8��(ILI9341 IC����)
* @Date        : 2016/4/2
* @By          : WindRises��л���죩
* @Email       : 1659567673@ qq.com
* @Platform    : Keil uVision5(TM4C123GH6PZ)
* @Explain     : None
*=============================================================================*/
/* ͷ�ļ����� -----------------------------------------------------------------*/
#include "My_Labrary.h" 
#include "My_TFT.h" 
#include "My_Delay.h" 
#include "Font.h" 
#include <string.h>

/* ˽�к궨�� -----------------------------------------------------------------*/
#if USE_HORIZONTAL==1	//ʹ�ú���
#define TFT_W 320
#define TFT_H 240
#else
#define TFT_W 240	
#define TFT_H 320	
#endif 
  										 

/* ˽�б������� ---------------------------------------------------------------*/

/* ˽�У���̬���������� --------------------------------------------------------*/
static void TFT_Param_Set(void);
static void TFT_Windows_Set(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd);
/* ȫ�ֱ������� ---------------------------------------------------------------*/ 
Type_LCD LCD_Param;//����LCD��Ҫ���� 
u16 TextColor = 0x0000;	//������ɫ
u16 BackColor = 0xFFFF;  //����ɫ  

/* ˽�У���̬��������д --------------------------------------------------------*/

/* ȫ�ֺ�����д ---------------------------------------------------------------*/
 
/**----------------------------------------------------------------------------   
* @FunctionName  : TFT_REG_Write()     
* @Description   : д��Ĵ���
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
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
	TFT_WR_H();//�����Ӷ�ȡ����
	
	TFT_CS_H();  
} 


/**----------------------------------------------------------------------------
* @FunctionName  : TFT_DATA_Write()     
* @Description   : д������
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
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
	TFT_WR_H();//�����Ӷ�ȡ����
	
	TFT_CS_H();
}

 
/**----------------------------------------------------------------------------
* @FunctionName  : TFT_RegData_Write()     
* @Description   : д��Ĵ���������
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
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
* @Description   : ׼��д��
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/ 
void TFT_WR_Prepare(void)
{
 	TFT_REG_Write(LCD_Param.wramcmd);	  
}


/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Clear()     
* @Description   : ����
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
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
* @Description   : ����
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/
void TFT_Point_Draw(u16 x,u16 y,u16 color)
{
	TFT_Windows_Set(x,y,x,y);//���ù��λ�� 
	TFT_DATA_Write(TextColor); 	    
} 	 


/**----------------------------------------------------------------------------
* @FunctionName  : TFT_GPIOInit()     
* @Description   : IO�ڳ�ʼ��
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
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
	
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);  //��8λ
	 GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,0xff); 
	 GPIOPinWrite(GPIO_PORTA_BASE,0xff,0);
	
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);  //��8λ 
	 GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,0xff); 
	 GPIOPinWrite(GPIO_PORTD_BASE,0xff,0);
	 
	 
} 

/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Init()     
* @Description   : TFT��ʼ��
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/ 
void TFT_Init(void)
{ 
	TFT_GPIOInit();
	TFT_RD_H();	 //RD����û���õ������ߴ���
	
	//=========================Һ������ʼ��=============================//
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
	
	//����LCD���Բ���
	TFT_Param_Set();//����LCD����	 
	TFT_LED_ON();//��������	 
}
/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Windows_Set()     
* @Description   : ������ʾ���ڣ������ڿ��Զ�����
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
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

	TFT_WR_Prepare();	//��ʼд��GRAM				
}   


/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Cursor_Set()     
* @Description   : ���ù��λ��
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
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

	TFT_WR_Prepare();	//��ʼд��GRAM	
} 


 
/**----------------------------------------------------------------------------
* @FunctionName  : TFT_Param_Set()     
* @Description   : ����LCD����
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
* @Data          : 2016/4/2
* @Explain       : None
------------------------------------------------------------------------------*/ 
static void TFT_Param_Set(void)
{ 	
	LCD_Param.wramcmd=0x2C;
#if USE_HORIZONTAL==1	//ʹ�ú���	  
	LCD_Param.dir=1;//����
	LCD_Param.width=320;
	LCD_Param.height=240;
	LCD_Param.setxcmd=0x2A;
	LCD_Param.setycmd=0x2B;			
	TFT_RegData_Write(0x36,0x6C);

#else//����
	LCD_Param.dir=0;//����				 	 		
	LCD_Param.width=240;
	LCD_Param.height=320;
	LCD_Param.setxcmd=0x2A;
	LCD_Param.setycmd=0x2B;	
	TFT_RegData_Write(0x36,0x0A);
#endif
}


 
/**----------------------------------------------------------------------------
* @FunctionName  : LCD_ShowChar()     
* @Description   : ��ʾһ���ַ�
* @Parameter     : None
* @Return        : void
* @Programer     : WindRises��л���죩
* @Data          : 2016/4/2
* @Explain       : size:�����С 12/16/24
------------------------------------------------------------------------------*/ 
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size)
{  							  
    u8 temp,t1,t;
	u16 y0=y; 
	u8 csize=(size/8+((size%8)?1:0))*(size/2);		//�õ�����һ���ַ���Ӧ������ռ���ֽ���	
	//���ô���		   
	num=num-' ';//�õ�ƫ�ƺ��ֵ
	for(t=0;t<csize;t++)
	{   
		if(size == 12)temp = asc2_1206[num][t]; 	 	//����1206����
		else if(size == 16)temp = asc2_1608[num][t];	//����1608����
		else if(size == 24)temp = asc2_2412[num][t];	//����2412����
		else return;								//û�е��ֿ�
		for(t1=0;t1<8;t1++) 
		{			    
			if(temp&0x80)TFT_Point_Draw(x,y,TextColor);
			 
			temp<<=1;
			y++;
			if(y>=LCD_Param.height)return;		//��������
			if((y-y0)==size)
			{
				y=y0;
				x++;
				if(x>=LCD_Param.width)return;	//��������
				break;
			}
		}  	 
	}  	    	   	 	  
}  


//m^n����
//����ֵ:m^n�η�.
u32 LCD_Pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}			 
//��ʾ����,��λΪ0,����ʾ
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С 12/16/24
//color:��ɫ 
//num:��ֵ(0~4294967295);	 
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


//��ʾ����,��λΪ0,������ʾ
//x,y:�������
//num:��ֵ(0~999999999);	 
//len:����(��Ҫ��ʾ��λ��)
//size:�����С12/16/24
//mode:
//[7]:0,�����;1,���0.
//[6:1]:����
//[0]:0,�ǵ�����ʾ;1,������ʾ.
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


//��ʾ����,��λΪ0
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С 12/16/24
//color:��ɫ 
//num:��ֵ(0~4294967295);	 
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




//��ʾ�ַ���
//x,y:�������
//width,height:�����С  
//size:�����С12/16/24
//*p:�ַ�����ʼ��ַ		
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p)
{         
	u8 x0=x;
	width+=x;
	height+=y;
    while((*p<='~')&&(*p>=' '))//�ж��ǲ��ǷǷ��ַ�!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//�˳�
        LCD_ShowChar(x,y,*p,size);
        x+=size/2;
        p++;
    }  
}


//��ʾС��
//x,y:�������
//digit:����λ��
//size:�����С  12/16/24
void LCD_ShowDecim(u16 x,u16 y,double num,u8 digit,u8 len,u8 size)//���� ����.����
{ 
	
	u32 digitnum=LCD_Pow(10,digit);                              
	u32 numd=(u32)(num*digitnum);     	                   
	u32 temp;                                               
	len=len-digit-1;
	temp=numd/digitnum;
	LCD_ShowxNum(x,y,temp,len,size);//��ʾ��������
	temp=(u32)(numd-((double)(numd/digitnum)*digitnum));
	LCD_ShowString(x+len*(size/2),y,size,size,size,(u8*)".");
	LCD_Show0Num(x+(len+1)*(size/2),y,temp,digit,size);//��ʾС������


} 




void LCD_String_Show(u16 x,u16 y,u8 *p,u8 size)
{ 
	LCD_ShowString(x,y,size *( strlen((char*)p) ),size,size,p); 
	
	
}



