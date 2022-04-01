#include <p18f4520.h>
#include <delays.h>
#include <usart.h>

//cau hinh cho vi dieu khien
#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF

char x;
void main()
{
	TRISC = 0b10000000;	//thiet lap RC6 la dau ra, RC7 la dau vao
	TRISB = 0x00;
	ADCON1 = 0x0f;
	OpenUSART( USART_TX_INT_OFF & //khong su dung ngat truyen
 			USART_RX_INT_OFF & //khong su dung ngat nhan
			USART_ASYNCH_MODE & //che do khong dong bo
 			USART_EIGHT_BIT & //truyen/nhan 8bit
 			USART_CONT_RX & //cho phep nhan lien tiep
 			USART_BRGH_HIGH, //toc do baud cao
 			71); 
	while(BusyUSART());
	WriteUSART(0x41);
	while(BusyUSART());
	WriteUSART(0x61);
	while(1)
	{
		x=ReadUSART();
		PORTB=x;
	}
}