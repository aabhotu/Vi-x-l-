#include <p18f4520.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config LVP = OFF
#pragma config WDT = OFF

void main (void)
{
	TRISB=0x00;
	TRISD=0x00;
	PORTC=0b11111111;
	ADCON1=0x0f;
	
	T1CON = 0b10000010;	//che do ghi/doc 16 bit, T13CKI, HSC=1
	T1CONbits.TMR1ON=1;
	while (1)
	{
		//B4. doc gia tri bo dem
		PORTB=TMR1L;
		PORTD=TMR1H;
	}
}
