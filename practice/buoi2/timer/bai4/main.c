/*
	Fosc=12M
	F=1400Hz, Timer0
	timercount= (delay*Fosc/4)/PV	delay=T/2=1/(2F)
			  = 1072/PV
	chon PV = 1 timercount =1072
*/

#include <p18f4520.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config LVP = OFF
#pragma config WDT = OFF

#define xung PORTBbits.RB2
void main (void)
{
TRISB = 0b11111011;  
ADCON1 = 0x0F;
// khoi tao timer
T1CON = 0b11001101;			//timer1,Fosc, che do ghi/doc 16 bit chia 1
	while(1)
	{
		//tao tre tao xung

		TMR1H = (65536-1065)/256;
		TMR1L = (65536-1065)%256;
		while(PIR1bits.TMR1IF==0);	//cho co tra
		xung=~xung;
		PIR1bits.TMR1IF=0;
	}
}