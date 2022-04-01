#include <p18f4520.h>
#include <delays.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB0
int x, i;
void main (void)
{
	TRISD=0b00000000;
	TRISB=0b11111111; 
	ADCON1=0x0f;
	while(1)
	{
		x=0b00000001;
		for(i=0; i<4; i++)
		{
			PORTD=x;
			Delay10KTCYx(50);
			x=x<<1;
			while(PB1==0) PORTD=0;
		}
	}
}