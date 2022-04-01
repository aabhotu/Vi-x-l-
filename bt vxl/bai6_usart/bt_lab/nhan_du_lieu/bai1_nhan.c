#include <p18f4520.h>
#include <delays.h>
#include <usart.h>

//cau hinh cho ci dieu khien
#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
void main()
{
	char x;
	TRISC=0x80;
	TRISD=0;
	PORTD=0;
	ADCON1=0x0F;
	OpenUSART(USART_TX_INT_OFF & //khong su dung ngat truyen
 			USART_RX_INT_OFF & //khong su dung ngat nhan
 			USART_ASYNCH_MODE & //che do khong dong bo
 			USART_EIGHT_BIT & //truyen/nhan 8bit
 			USART_CONT_RX & //cho phep nhan lien tiep
 			USART_BRGH_HIGH, //toc do baud:=9600
 			51);
	while(1)
	{
		x=ReadUSART();
		PORTD=x;
	}
}