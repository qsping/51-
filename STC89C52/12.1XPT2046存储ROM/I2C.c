#include <REGX52.H>
sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;
/*
@brief  I2C��ʼ
@param  ��
@retva  ��
*/
void I2C_Start()
{
	I2C_SDA=1;
	I2C_SCL=1;
		
	I2C_SDA=0;	
	I2C_SCL=0;
}
/*
@brief           I2C ����
@param         ��
@retva          ��
*/

void I2C_Stop()
{
	I2C_SDA=0;	
	I2C_SCL=1;	
	I2C_SDA=1;		
}
/*
@brief           I2C����һ���ֽ�
@param         �ֽ�
@retva          ��
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
@brief           I2C����һ���ֽ�
@param         ��
@retva          ���յ���һ���ֽ�����
*/
unsigned char I2C_ReceiveByte( )
{
	unsigned char Byte=0x00,i;
	
	I2C_SDA=1;//�ͷ�����
	
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
@brief           I2C����һ��Ӧ��
@param         AckBitӦ��λ  0ΪӦ��
@retva          ��
*/
void I2C_SendAck(unsigned char AckBit)//��������һ��Ӧ��
{
	I2C_SDA=AckBit;	
	I2C_SCL=1;
	I2C_SCL=0;	
}
/*
@brief           I2C����һ��Ӧ��
@param         ��
@retva          ���յ���AckByteӦ��λ
*/
unsigned char I2C_ReceiveAck()//��������Ӧ��
{
	unsigned char AckByte=0;
	I2C_SDA=1;
	I2C_SCL=1;
	
	AckByte=I2C_SDA;
	I2C_SCL=0;		
	return AckByte;
}