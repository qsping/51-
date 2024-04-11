
#include <REGX52.H>
#include "Delay.h"
sbit Buzzer=P1^5;
void Delay500us()		//@11.0592MHz
{
	unsigned char i, j;
	i = 6;
	j = 93;
	do
	{
		while (--j);
	} while (--i);
}
void Buzzer_Time(unsigned int ms)
{
	int i=0;
	for(i=0;i<ms;i++)
	{
		Buzzer=~Buzzer;		
		Delay500us();
	}
}

