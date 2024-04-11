#include <REGX52.H>
#include <INTRINS.H>
#include "Delay.h"

sbit OneWire_DQ=P3^7;

unsigned char OneWire_Init()
{		
	unsigned char i;								
	unsigned char AckBit;
	OneWire_DQ=1;
	OneWire_DQ=0;
	i = 247;while (--i);            //Delay 500us
	OneWire_DQ=1;		
	i = 32;while (--i);  	//Delay 70us
	AckBit=OneWire_DQ;
	i = 247;while (--i); 
	return AckBit;	
}
	
void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ=0;
	i = 4;while (--i); 	//delay 10us
	OneWire_DQ=Bit;
	i = 24;while (--i);           //delay 50us
	OneWire_DQ=1;
}

unsigned char OneWire_ReceiveBit()
{
	unsigned char i;
	unsigned char Bit;
	OneWire_DQ=0;
	i = 2;while (--i);        //delay 5us
	OneWire_DQ=1;
	i = 2;while (--i);          //delay 5us
	Bit=OneWire_DQ;
	i = 24;while (--i);     //delay 5us
        return Bit;
}

void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		OneWire_SendBit(Byte&(0x01<<i));
	}
}
unsigned char OneWire_ReceiveByte()
{
	unsigned char i;
	unsigned char Byte=0x00;
	for(i=0;i<8;i++)
	{
		if(OneWire_ReceiveBit()){Byte|=(0x01<<i);}//��Byte���OneWire_Receive������
	}
	return Byte;
}