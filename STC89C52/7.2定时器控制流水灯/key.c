#include <REGX52.H>
#include<intrins.h>
void delay(unsigned int xms )		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} 
	while (--i);
} 
unsigned char key ()
	{
		unsigned char keynumber=0;
			if(P3_1==0)
		{
			delay(20);while(P3_1==0);delay(20);keynumber=1;
		}
			if(P3_0==0)
		{
			delay(20);while(P3_0==0);delay(20);keynumber=2;
		}	if(P3_2==0)
		{
			delay(20);while(P3_2==0);delay(20);keynumber=3;
		}	if(P3_3==0)
		{
			delay(20);while(P3_3==0);delay(20);keynumber=4;
		}
		return keynumber;
	}