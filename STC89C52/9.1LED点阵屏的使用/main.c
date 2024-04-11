#include <REGX52.H>
#include "Delay.H"

sbit RCLK1=P3^5;
sbit SRCLK=P3^6;
sbit SER=P3^4;

/*	@brief	74HC595写入一个字节
	@param 要写入的字节BYTE
	@retval 无
*/

void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
	SER=Byte&(0x80>>i);
	SRCLK=1;//数据移入寄存器
	SRCLK=0;//移位清零
	}	
	RCLK1=1;
	RCLK1=0;
}

/*	@brief	LED点阵屏幕写入一列数据
	@param Column，要选择的列，和范围：0~7，0在最左边
			 Date	，选择显示的数据，高位在上
	@retval 无
*/
void MatrixLED_ShowCloumn(unsigned char Column,Date)
{
	_74HC595_WriteByte(Date);
	P0=~(0x80>>Column);
	Delay(1);
	P0=0xff;
}

void main()
{
	SRCLK=0;
	RCLK1=0;
	
	while(1)
	{
	MatrixLED_ShowCloumn(0,0xe8);
	MatrixLED_ShowCloumn(1,0xa8);
	MatrixLED_ShowCloumn(2,0xb8);
//	MatrixLED_ShowCloumn(3,0x00);
//	MatrixLED_ShowCloumn(4,0x00);
	MatrixLED_ShowCloumn(5,0xf8);
	MatrixLED_ShowCloumn(6,0x28);	
	MatrixLED_ShowCloumn(7,0x38);
	}
}