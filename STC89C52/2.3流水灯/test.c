#include <REGX52.H> 
#include <INTRINS.H>
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	int i=0;
	while(1)
	{
		for(i=0;i<9;i++)
		{
			P2=~(0x01<<i);
			Delay500ms();
		}
		P2=0xff;
	}
}