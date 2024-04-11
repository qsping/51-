 #include <REGX52.H>
 #include "LCD1602.H"
 #include "KEY.H"
 #include "AT24C02.H"
 #include "delay.h"
unsigned char KeyNum,i=0;
unsigned int Num=0;
void main()
{
     unsigned char KeyNum;
	LCD_Init();
     LCD_ShowNum(1,1,Num,5);	  
     while(1)
	{
		KeyNum=Key();
          if(KeyNum==1)
          {
               Num++;
               LCD_ShowNum(1,1,Num,5);	   
          }
          if(KeyNum==2)
          {
               Num--;
                LCD_ShowNum(1,1,Num,5);	   
          }
           if(KeyNum==3)
          {
			AT24C02_WriteByte(0,Num%256);
			Delay5ms();
			AT24C02_WriteByte(1,Num/256);
			Delay5ms();
			LCD_ShowString(2,1,"Write OK");
			for(i=0;i<100;i++)Delay5ms();             
			LCD_ShowString(2,1,"        ");

          }
          if(KeyNum==4)
          {
			Num=AT24C02_ReadByte(0);
			Num|=AT24C02_ReadByte(1)<<8;
			LCD_ShowNum(1,1,Num,5);
			LCD_ShowString(2,1,"Read OK ");
               for(i=0;i<100;i++)Delay5ms();    
			LCD_ShowString(2,1,"        ");             
          }          
	}
}