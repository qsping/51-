#include <REGX52.H>


void Timer0Init(void)		//100??@12.000MHz
{

	TMOD &= 0xF0;		//???????
	TL0 = 0x9C;		//??????
	TH0 = 0xFF;		//??????
	TF0 = 0;		//??TF0??
	TR0 = 1;		//???0????
}



/*void Timer0_Routine() interrupt	 1	 ��ʱ���ж�ģ��
{

	static unsigned  int count;
	TL0 = 0x9c;		//���ö�ʱ��ֵ
	TH0 = 0xff;		//���ö�ʱ��ֵ
	count++;

	
	if(count>=1000)
	{
	}

} */