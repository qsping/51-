#include <REGX52.H>
 
/*#include<intrins.h>
void delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while (xms--)
	{
	 i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	}
	
}


int 	Nixietable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

void Nixie(unsigned char Location,Number)
{
	switch(Location)
	{
		 	case 1:P2_4=1;P2_3=1;P2_2=1;break;
			case 2:P2_4=1;P2_3=1;P2_2=0;break;
			case 3:P2_4=1;P2_3=0;P2_2=1;break;
			case 4:P2_4=1;P2_3=0;P2_2=0;break;
			case 5:P2_4=0;P2_3=1;P2_2=1;break;
			case 6:P2_4=0;P2_3=1;P2_2=0;break;
			case 7:P2_4=0;P2_3=0;P2_2=1;break;
			case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}

		 P0=Nixietable[Number];	delay(2); 

 }
	void main()
{
	 
	 	while(1)
		 {
		Nixie(1,1);
		//delay(2);
		Nixie(2,7);
		 //delay(2);
		Nixie(3,3);
		 //delay(2);
		Nixie(4,4);
		 //delay(2);
		Nixie(5,5);
		//delay(2);	 	
		 }
}  */
#include <REGX52.H>
#include "time.h"
#include "number.h"
void main()
{
 	while(1)
		{
		Nixie(1,1);
		delay(2);
		Nixie(2,7);
		 delay(2);
		Nixie(3,3);
		 delay(2);
		Nixie(4,4);
		 delay(2);
		Nixie(5,5);
		delay(2);	  
				}
}