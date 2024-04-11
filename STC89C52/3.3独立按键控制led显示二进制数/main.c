#include <REGX52.H>
#include <intrins.h>  
  void delay(unsigned int xms )		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
} 

 void main ()
 { unsigned char a=0;
 	while(1)
	{
	if(P3_1==0)
		{
			delay(50);
			while(P3_1==1);
			delay(50);
			a++;
			P2=~a;
		}	
	}
}