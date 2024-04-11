#include <REGX52.H>
#include <intrins.h>
void Delay20us()		//@11.0592MHz
{
	unsigned char i;
	
	
		_nop_();
		i = 6;
		while (--i);		
	

}

int 	Nixietable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

void main()
{	 
	unsigned int i,j=0;	
	while(1)
	{			
		for(i=0;i<8;i++)
		{					
			P2=~Nixietable[i];
			P3=0x08;
			for(j=0;j<32775;j++)Delay20us();
		}

	}
} 