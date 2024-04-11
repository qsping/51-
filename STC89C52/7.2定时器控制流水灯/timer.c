#include <REGX52.H>

void Timer0_Init(void)		//100微秒@11.0592MHz
{
	TMOD &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
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