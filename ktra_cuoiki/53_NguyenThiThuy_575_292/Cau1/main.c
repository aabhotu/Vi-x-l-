#include <p18f4520.h>
#include <delays.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTDbits.RD1
#define PB2 PORTDbits.RD2

void main (void)
{
	TRISD=0b00000110;
	ADCON1=0x0f;
	while(1)
	{
		if(PB1==0 && PB2==0) PORTD=0b000111110;
		else if(PB1==0 && PB2==1) PORTD=0b01100110;
		else if(PB1==1 && PB2==0) PORTD=0b11000110;
		else if(PB1==1 && PB2==1) PORTD=0b10010110;
	}
}