#include <REGX52.H>
#include "Delay.h"
#include <INTRINS.h>

unsigned int i,j;
void main ()
{
	P2=0x01;	
	if(P3_1==0)
	{		
		Delay(20);
		while(P3_1==0);	
		
		j++;
	}
		if(j==2)
		{
			j=0;
		}	

	if(j==1)
		{
			while(1)				
			{
				Delay(50);
				while(P3_1==0);
				P2=_cror_(P2,1);
				Delay(50);
			}				
		}
		
	if(j==0)
		{
			while(1)				
			{
				Delay(50);
				while(P3_1==0);
				P2=_crol_(P2,1);
				Delay(50);
			}				
		}
		


}