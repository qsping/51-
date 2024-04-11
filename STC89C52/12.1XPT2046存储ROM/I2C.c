#include <REGX52.H>
sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;
/*
@brief  I2C开始
@param  无
@retva  无
*/
void I2C_Start()
{
	I2C_SDA=1;
	I2C_SCL=1;
		
	I2C_SDA=0;	
	I2C_SCL=0;
}
/*
@brief           I2C 结束
@param         无
@retva          无
*/

void I2C_Stop()
{
	I2C_SDA=0;	
	I2C_SCL=1;	
	I2C_SDA=1;		
}
/*
@brief           I2C发送一个字节
@param         字节
@retva          无
*/
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);
		I2C_SCL=1;
		I2C_SCL=0;
	}
}
/*
@brief           I2C接收一个字节
@param         无
@retva          接收到的一个字节数据
*/
unsigned char I2C_ReceiveByte( )
{
	unsigned char Byte=0x00,i;
	
	I2C_SDA=1;//释放总线
	
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
		if(I2C_SDA)
		{
			Byte|=(0x80>>i);
		}
		I2C_SCL=0;	
	}
	return Byte;
}
/*
@brief           I2C发送一个应答
@param         AckBit应答位  0为应答
@retva          无
*/
void I2C_SendAck(unsigned char AckBit)//主机发送一个应答
{
	I2C_SDA=AckBit;	
	I2C_SCL=1;
	I2C_SCL=0;	
}
/*
@brief           I2C接收一个应答
@param         无
@retva          接收到的AckByte应答位
*/
unsigned char I2C_ReceiveAck()//主机接收应答
{
	unsigned char AckByte=0;
	I2C_SDA=1;
	I2C_SCL=1;
	
	AckByte=I2C_SDA;
	I2C_SCL=0;		
	return AckByte;
}