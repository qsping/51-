#include <REGX52.H>
#define uchar unsigned char
#define uint unsigned int
uint i;
uint Num;
uint Disp_Time;
uchar Disp_Tab[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
uchar Disp_Buf[8];
unsigned char count;
void Int_T0();
void main(void)
{
	TMOD=0x51;
	TH0=0;
	TL0=0;
	TH1=0;
	TR0=1;TR1=1;
	ET0=1;EA=1;
	Disp_Time=1;
	Num=0;
	while(1)
	{
		void Int_T0();
		if(count==100)
		{
			count=0;
			P2=0xff;
			P0=Disp_Tab[Disp_Buf[Disp_Time%8]];
			P2=~(0x01<<(Disp_Time%8));
			Disp_Time++;
			if(Disp_Time>3597)
			{
				Disp_Time=0;
				Num=TH0*256+TL0;
				TH0=0;
				TL0=0;
			}			
			Disp_Buf[0]=16;
			Disp_Buf[1]=16;
			Disp_Buf[2]=16;
			Disp_Buf[3]=16;
			Disp_Buf[4]=Num/1000;
			Disp_Buf[5]=(Num%1000)/100;
			Disp_Buf[6]=(Num%100)/10;
			Disp_Buf[7]=Num%10;
		}
	}
}
	void Int_T0() interrupt 1
	{
		TH0=(65536-1000)/256;
		TL0=(65536-1000)%256;
		count++;
	}