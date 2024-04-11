#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
#include "key.h"
#include "Buzzer.h"
sbit Buzzer=P1^5;
int i=0;

void main()
{
	int KeyNum=0;
	Nixie(1,0);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{					
			Buzzer_Time(50);
			Delay(200);		
			Nixie(1,KeyNum);
		}
		if(KeyNum==2)
		{
			Buzzer_Time(50);
			Nixie(1,KeyNum);
		}
		if(KeyNum==3)
		{
			Buzzer_Time(50);
			Nixie(1,KeyNum);
		}
		if(KeyNum==4)
		{
			Buzzer_Time(50);
			Nixie(1,KeyNum);
		}
		
	}
}