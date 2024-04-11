#include <REGX52.H>
#include  "Delay.h"
#include "XPT2046.h"
#include "LCD1602.h"

unsigned int ADValue;
	
 void main ()
 {
	LCD_Init();
	LCD_ShowString(1,1,"ADJ  NTC  RG");
	 while(1)
	 {
		ADValue=XPT2046_ReadAD(XPT2046_XP);
		LCD_ShowNum(2,1,ADValue,3);
		 
		ADValue=XPT2046_ReadAD(XPT2046_YP);
		LCD_ShowNum(2,5,XPT2046_YP,3);
		
		 ADValue=XPT2046_ReadAD(XPT2046_VBAT);		
		 LCD_ShowNum(2,9,ADValue,3);
		Delay1ms();
	 }
 }
	 