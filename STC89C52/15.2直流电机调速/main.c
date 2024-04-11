#include <REGX52.H>
#include "Delay.h"
#include "key.h"
#include "nixie.h"
#include "Timer0.h"
sbit Motor=P1^0;
unsigned char counter,compare;
unsigned char KeyNumber,Speed;
 void main()
{	
	Timer0_Init ();
	compare=5;
	while(1)
	{
		KeyNumber=key();
		if(KeyNumber==1)
		{
			Speed++;
			Speed%=4;	//清零
			if(Speed==0){compare=0;}
			if(Speed==1){compare=30;}
			if(Speed==2){compare=60;}
			if(Speed==3){compare=90;}
		}
			Nixie(1,Speed);
			
	}
}
void Timer0_Routine() interrupt 1	 //定时器中断模板
{
	TL0 = 0xCD;		//设置定时初值
	TH0 = 0xD4;		//设置定时初值
	counter++;
	if(counter>=100)counter=0;//定时器定时自增
	if(counter<=compare)
	{
		Motor=1;
	}
	else
	{
		Motor=0;
	}
	
}	
