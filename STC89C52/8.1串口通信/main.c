#include <REGX52.H>
#include "DELAY.H"
#include "UART.H"
unsigned char NUM;


void main()
{
	UartInit();
	
	while (1)
	{
//		UART_SendByte(NUM);	
//		NUM++;
		
		UART_SendByte('F');Delay1000ms();	
		UART_SendByte(0X55);Delay1000ms();	
		UART_SendByte(0X43);Delay1000ms();
		UART_SendByte(0X4B);Delay1000ms();	
		UART_SendByte(0X13);Delay1000ms();	
	}
}
void UART_Rountine() interrupt 4
{
	if(RI==1)
	{
		P2=SBUF;			
		RI=0;
	}
}