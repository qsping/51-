#include <REGX52.H>
#include "Delay.H"

sbit RCLK1=P3^5;
sbit SRCLK=P3^6;
sbit SER=P3^4;

/*	@brief	74HC595д��һ���ֽ�
	@param Ҫд����ֽ�BYTE
	@retval ��
*/

void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
	SER=Byte&(0x80>>i);
	SRCLK=1;//��������Ĵ���
	SRCLK=0;//��λ����
	}	
	RCLK1=1;
	RCLK1=0;
}

/*	@brief	LED������Ļд��һ������
	@param Column��Ҫѡ����У��ͷ�Χ��0~7��0�������
			 Date	��ѡ����ʾ�����ݣ���λ����
	@retval ��
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