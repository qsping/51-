#include <REGX52.H>
#include "time.h"
#include "LCD1602.h"
#include "mkey.h"
int  Result=25 ;
int a;
unsigned char keynum1;
unsigned char keynum2;
unsigned char keynum3;
unsigned char keynum4;
void main()
{	
		LCD_Init();
		LCD_ShowString(1,1,"C4boom:");
//	
		LCD_ShowString(2,1,"PassWord:");
		while(1)
		{	
 
			//keynum1=mkey();
			 
			    Result--;
			    delay(5);
			    LCD_ShowNum(1,15,Result,2);
				if (Result==0)
				{
				  Result=25;
				}
			   	if(Result<=15)
				{
						 P2=0XAA; //1010 1010
						 delay(200);
						 P2=0x55; //0101 0101
						 delay(200);
				}
				keynum1=73;	keynum2=55;keynum3=60;keynum4=8;
				if(keynum1)
				{
					LCD_ShowNum(2 ,10,keynum1,2);
					
					delay(500);LCD_ShowNum(2 ,12,keynum2,2);
					
					delay(500);LCD_ShowNum(2 ,14,keynum3,2); 
					
					delay(500);LCD_ShowNum(2 ,15,keynum4,2);
				}
		}		 
}
		
		

		
	
