#include <REGX52.H>
#include "delay.h"
#include "number.h"
void main()
{
	
	while(1)
		{
		Nixie(1,7);
		delay(1000);
			if(P2_0==0x3f)
				{
				
				 	while(1)
						{
						  Nixie(1,7);
				delay(2);
						}
				 		
				}
			Nixie(2,3);
			delay(1000);

		Nixie(3,5);
		delay(1000);
			Nixie(4,5);
			delay(1000);
		Nixie(5,6);
		delay(1000);
			Nixie(6,0);
			delay(1000);
		Nixie(7,8);
		delay(1000);	  	
		
		}
}
