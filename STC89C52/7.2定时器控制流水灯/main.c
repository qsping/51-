#include <REGX52.H>
#include <INTRINS.H>
#include"timer.h"
#include"key.h"

//void Delay1000ms()		//@11.0592MHz
//{
//	unsigned char i, j, k;
//
//	_nop_();
//	_nop_();
//	i = 8;
//	j = 1;
//	k = 243;
//	do
//	{
//		do
//		{
//			while (--k);
//		} while (--j);
//	} while (--i);
//}

// void Timer0Init(void)		//1毫秒@11.0592MHz
//{
//
//	TMOD &= 0xF0;		//设置定时器模式
//	TL0 = 0x66;		//设置定时初值
//	TH0 = 0xFC;		//设置定时初值
//	TF0 = 0;		//清除TF0标志
//	TR0 = 1;		//定时器0开始计时
//}

unsigned char keynumber,LEDMOD ;
void main()
{	P2=0xfe;
	Timer0Init();
	while(1)
	{
		keynumber=key();
		if(keynumber)
		{
			if(keynumber==1)
			{
				LEDMOD++;
				if(LEDMOD>=2)LEDMOD=0;
				


			}
			
		}					
	}
}

void Timer0_Routine() interrupt	 1	 
{

	static unsigned  int count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	count++;

	if(count>=500)
	{
		count=0;
		if(LEDMOD==0)P2=_crol_(P2,1);
		if(LEDMOD==1)P2=_cror_(P2,1);
	}
	

}