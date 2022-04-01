#include <p18f4520.h>
#include <delays.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB0
#define PB2 PORTBbits.RB1

void main (void)
{
	TRISD=0b00000000;
	TRISB=0b11111111;
	ADCON1=0x0f;
	while(1)
	{
		if(PB1==0 && PB2==0) PORTD=0b00000001;
		else if(PB1==0 && PB2==1) PORTD=0b00000010;
		else if(PB1==1 && PB2==0) PORTD=0b00000100;
		else if(PB1==1 && PB2==1) PORTD=0b00001000;
	}
}