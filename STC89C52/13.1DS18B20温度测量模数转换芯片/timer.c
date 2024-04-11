#include <REGX52.H>


void Timer0Init(void)		//100??@12.000MHz
{

	TMOD &= 0xF0;		//???????
	TL0 = 0x9C;		//??????
	TH0 = 0xFF;		//??????
	TF0 = 0;		//??TF0??
	TR0 = 1;		//???0????
}



/*void Timer0_Routine() interrupt	 1	 定时器中断模板
{

	static unsigned  int count;
	TL0 = 0x9c;		//设置定时初值
	TH0 = 0xff;		//设置定时初值
	count++;

	
	if(count>=1000)
	{
	}

} */