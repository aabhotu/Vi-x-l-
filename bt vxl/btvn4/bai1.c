#include <p18f4520.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config LVP = OFF
#pragma config WDT = OFF

#define xung PORTCbits.RC1

void tre1giay()
{

	TMR0H=(65536-62500)/256;
	TMR0L=(65536-62500)%256;
	while(INTCONbits.TMR0IF==0);
	INTCONbits.TMR0IF=0;
	
}

void main (void)
{
	TRISB=0x00;
	TRISC=0xff;
	ADCON1=0x0f;
	
	T1CON = 0b10000011;
	T0CON=0b10000011;
	while (1)
	{
		//B4. doc gia tri bo dem
		TMR1H=0;
		TMR1L=0;
		T1CONbits.TMR1ON=1;
		tre1giay();
		T1CONbits.TMR1ON=0;
		PORTB=TMR1L;	//doc tan so
	}
}
