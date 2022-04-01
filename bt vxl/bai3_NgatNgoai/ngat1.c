#include <p18f4520.h>
#include <stdio.h>
#include <delays.h>

#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON
#pragma config PBADEN=OFF

#define LED5 PORTBbits.RB7

void low_isr (void);
void high_isr (void);

#pragma code low_vector=0x18
void interrupt_at_low_vector (void)
{
_asm GOTO low_isr _endasm
}
#pragma code
#pragma interruptlow low_isr
void low_isr (void)
{
}
#pragma code high_vector=0x08
void interupt_at_high_vector (void)
{
_asm GOTO high_isr _endasm
}
#pragma code
#pragma interrupt high_isr
void high_isr (void)
{
	INTCON3bits.INT2IF=0;
	LED5=1;
	Delay10KTCYx(100);
	LED5=0;
}

void main (void)
{
	ADCON1=0x0F;
	TRISB=0b00000100;
	INTCONbits.GIE=1;
	INTCON3bits.INT2IE=1;
	INTCON2bits.INTEDG2=0;

	while (1)
	{
		PORTB=0b00001000;
		Delay10KTCYx(100);
		PORTB=0b00010000;
		Delay10KTCYx(100);
		PORTB=0b00100000;
		Delay10KTCYx(100);
		PORTB=0b01000000;
		Delay10KTCYx(100);

	}
}