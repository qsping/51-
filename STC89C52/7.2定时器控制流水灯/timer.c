#include <REGX52.H>

void Timer0_Init(void)		//100΢��@11.0592MHz
{
	TMOD &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0xA4;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0=1;
	EA=1;
	PT0=0;
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