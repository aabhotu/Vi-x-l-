/*
	Fosc=12M
	F=2500Hz, Timer0
	timercount= (delay*Fosc/4)/HSC	delay=T/2=1/(2F)
			  = 600/HSC
	chon HSC = 1 timercount =600
*/

#include <p18f4520.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config LVP = OFF
#pragma config WDT = OFF

#define xung PORTCbits.RC2
void main (void)
{
TRISC = 0b11111011;  
ADCON1 = 0x0F;
// khoi tao timer
T0CON = 0b10001000;			//timer0, che do ghi/doc 16 bit chia 1
	while(1)
	{
		//tao tre tao xung

		TMR0H = (65536-600)/256;
		TMR0L = (65536-600)%256;
		while(INTCONbits.TMR0IF==0);	//cho co tran
		xung=~xung;
		INTCONbits.TMR0IF=0;
	}
}