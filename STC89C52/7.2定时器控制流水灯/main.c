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

// void Timer0Init(void)		//1����@11.0592MHz
//{
//
//	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
//	TL0 = 0x66;		//���ö�ʱ��ֵ
//	TH0 = 0xFC;		//���ö�ʱ��ֵ
//	TF0 = 0;		//���TF0��־
//	TR0 = 1;		//��ʱ��0��ʼ��ʱ
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
	TL0 = 0x66;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	count++;

	if(count>=500)
	{
		count=0;
		if(LEDMOD==0)P2=_crol_(P2,1);
		if(LEDMOD==1)P2=_cror_(P2,1);
	}
	

}