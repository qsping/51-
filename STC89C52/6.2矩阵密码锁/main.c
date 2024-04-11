#include <REGX52.H>
#include "time.h"
#include "LCD1602.h"
#include "mkey.h"
unsigned int  password,count,A;
unsigned char keynumber ;

void main()
{	
		LCD_Init();
		LCD_ShowString(1,1,"password:");
		while(1)
		{				 
			keynumber=mkey();
			if(keynumber)
			{
				if(keynumber<=10)
				{
					if(count<=3)//输入次数小于4
					{
						password*=10;			//  密码移位
						password+=keynumber%10;	//　获取一位密码
					 	count++;
					}  
					LCD_ShowNum(2,1,password,4);															
				} 
				
				if (count==4)
				{					
					if (password==1234)
						{
						  	LCD_ShowString(1,13,"NiCE");
							password=0;
							count=0;
							delay(1000);
							LCD_ShowNum(2,1,password,4);
							LCD_ShowString(1,13,"    ");	
						}
					else
						{
						 	LCD_ShowString(1,13,"BAD");
							password=0;
							count=0;
							delay(1000);
							LCD_ShowNum(2,1,password,4);
							LCD_ShowString(1,13,"    ");
						}
			
							
				  }
					
				if (keynumber==12)
					{	
						if(password!=0)
						{
						 	password/=10;
							count--;
							LCD_ShowNum(2,1,password,4);
						}
												
					}			
	
			}
			
		
		}		 
}
		
		

		
	
