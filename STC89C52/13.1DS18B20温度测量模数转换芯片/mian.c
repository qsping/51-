#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
#include "DS18B20.h"
#include "Nixie.h"
#include "Timer0.h"

float temp;
void Delay20us()	//@11.0592MHz
{
	unsigned char i;

	i = 6;
	while (--i);
}

void main()
{
	int i=0;
	LCD_WriteCommand(0x0f);
	DS18B20_ConverT();
	for(i=0;i<200;i++)Delay5ms();
	LCD_Init();
	LCD_ShowString(1,1,"Temperature");
	
	while(1)	
	{	
		
		DS18B20_ConverT();  
		temp=DS18B20_ReadT();
		if(temp<0)
		{
			LCD_ShowChar(2,1,'-');
		}
		else
		{
			LCD_ShowChar(2,1,'+');
		}
		LCD_ShowNum(2,2,temp,3);
		LCD_ShowChar(2,5,'.');
		LCD_ShowNum(2,6,(unsigned long)(temp*10000)%10000,4);
//		Nixie(1,temp/100);Delay20us();
//		Nixie(2,(unsigned long)(temp/10)%10);
//		Delay20us();
//		Nixie(3,(unsigned long)(temp*10)%10);
//		Delay20us();
//		Nixie(4,0x6F);
//		Delay20us();
//		Nixie(5,(unsigned long)(temp*100)%100);Delay20us();
//		Nixie(6,(unsigned long)(temp*1000)%1000);Delay20us();
//		Nixie(7,(unsigned long)(temp*10000)%10000);Delay20us();
//				Nixie(1,1);Delay20us();
		Nixie(5,10);Delay20us();		
//		Nixie(3,0x62);Delay20us();
//		Nixie(4,0x77);Delay20us();		
//		Nixie(5,4);Delay20us();
//		Nixie(6,7);Delay20us();
//		Nixie(7,4);Delay20us();
	}
}
//void Timer0_Routine() interrupt 1
//{
//	static unsigned int T0Count2;
//	TL0 = 0x18;		
//	TH0 = 0xFC;		
//	T0Count2++;
//	if(T0Count2>=2)
//	{
//		T0Count2=0;
//		Nixie_Loop();//2ms
//	}
//}
