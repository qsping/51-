#include <REGX52.H>
/**
  * @brief  ���ڳ�ʼ����化，4800bps@12.000MHz
  * @param  ��
  * @retval ��
  */

void UartInit()		//4800bps@11.0592MHz
{
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//�����ʱ��1ģʽλ
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xF4;		//�趨��ʱ��ֵ
	TH1 = 0xF4;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;
	EA=1;
	ES=1;//������ʱ��1
}
/**
  * @brief  ���ڷ���һ���ֽ�4800bps@12.000MHz
  * @param  ��
  * @retval ��
  */

void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;	
	while(TI==0);//�ж�TI�Ƿ����0
	TI=0;
}
/*�ж�ģ��*/
//void UART_Rountine() interrupt 4
//{
//	if(RI==1)
//	{
//				
//		RI=0;
//	}
//}