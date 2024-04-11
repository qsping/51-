#include <REGX52.H>
#include <INTRINS.h>
void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	 while(xms)
	 {
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		 xms--;
	  }
}

void main()
{
	while(1)
	{
	if(P3_1==0)
	  	{  
								  Delay(20);
						          while(P3_1==0) ;
						  
								  Delay(20);
								  P2_0=~P2_0 ;				  
		}
		if(P3_0==0)
	  	{  
								  Delay(20);
						          while(P3_0==0) ;
						  
								  Delay(20);
								  P2_1=~P2_1 ;				  
		}if(P3_2==0)
	  	{  
								  Delay(20);
						          while(P3_2==0) ;
						  
								  Delay(20);
								  P2_2=~P2_2 ;				  
		}if(P3_3==0)
	  	{  
								  Delay(20);
						          while(P3_3==0) ;
						  
								  Delay(20);
								  P2_3=~P2_3 ;				  
		}
	}
}