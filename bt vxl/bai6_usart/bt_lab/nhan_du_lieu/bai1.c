#include <p18f4520.h>
#include <delays.h>
#include <usart.h>

//cau hinh cho vi dieu khien
#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF

void main()
{
	char x = 0x31;	//ma ASCII cua kis tu nguyen
	TRISC = 0x80;	//thiet lap RC6 la dau ra, RC7 la dau vao
	ADCON1 = 0x0f;
	OpenUSART( USART_TX_INT_OFF & //khong su dung ngat truyen
 			USART_RX_INT_OFF & //khong su dung ngat nhan
			USART_ASYNCH_MODE & //che do khong dong bo
 			USART_EIGHT_BIT & //truyen/nhan 8bit
 			USART_CONT_RX & //cho phep nhan lien tiep
 			USART_BRGH_HIGH, //toc do baud cao
 			51); // 9600=8000000(16*(51+1))
	WriteUSART(x);	//truyen so 0x31
	while(1);
}