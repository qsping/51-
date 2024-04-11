#include <REGX52.H>

void Timer0_Init(void)		//�秒@11.0592MHz
{
	TMOD &= 0xF0;		
	TMOD |= 0x01;	
	TL0 = 0xCD;		
	TH0 = 0xD4;		
	TF0 = 0;		
	TR0 = 1;		
	ET0=1;
	EA=1;
	PT0=0;
}



/*void Timer0_Routine() interrupt	 1	 定时器中断模�?
{

	static unsigned  int count;
	TL0 = 0x9c;		//设置定时初�??
	TH0 = 0xff;		//设置定时初�??
	count++;

	
	if(count>=1000)
	{
	}

} */
