
#include <REGX52.H>

sbit DS1302_SlCK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;
#define DS1302_SECOND		0x80
#define DS1302_MINUTE		0x82
#define DS1302_HOUR			0x84
#define DS1302_DATE			0x86
#define DS1302_MONTH		0x88
#define DS1302_DAY			0x8A
#define DS1302_YEAR			0x8C
#define DS1302_WP			0x8E
unsigned char DS1302_Time[]={24,3,23,15,59,55,6};//通过数组进行时间的交换，芯片进行时间的运算
void DS1302_Init(void)
{
	DS1302_CE=0;
	DS1302_SlCK=0;
}
void DS1302_WriteByte(unsigned char Command,Data)
{
	int i=0;		
	DS1302_CE=1;//CE是时序 
	for(i=0;i<8;i++)//写入控制字
	{
		DS1302_IO=Command&(0x01<<i);//
		DS1302_SlCK=1;//读操作
		DS1302_SlCK=0;
	}
	for(i=0;i<8;i++)//写入数据
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SlCK=1;
		DS1302_SlCK=0;
	}
	 DS1302_CE=0;
}
unsigned char DS1302_ReadByte(unsigned char Command)	//写入控制字返回参数
{
	int i=0;
	unsigned char Data=0x00;
	Command|=0x01;	
	DS1302_CE=1;	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SlCK=0;
		DS1302_SlCK=1;
	}
		for(i=0;i<8;i++)
	{			
		DS1302_SlCK=1;		
		DS1302_SlCK=0;
		if(DS1302_IO){Data|=(0x01<<i);}
	}
	DS1302_CE=0;
	DS1302_IO=0;	
	return Data;
}

void DS1302_SetTime(void)//将时间写入数组
{
	DS1302_WriteByte(DS1302_WP,0x00);//关闭写保护
	DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
	DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_WriteByte(DS1302_WP,0x80);
}


void DS1302_ReadTime(void)//将时间读出入数组
{
	unsigned char Temp;
	Temp=DS1302_ReadByte(DS1302_YEAR);
	DS1302_Time[0]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_DATE);
	DS1302_Time[2]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_MINUTE);
	DS1302_Time[4]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_SECOND);
	DS1302_Time[5]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[6]=Temp/16*10+Temp%16;
}
