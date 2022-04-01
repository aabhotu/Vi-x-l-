#include <p18f4520.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF

void main (void)
{
TRISB=0b00000000;
ADCON1=0x0f;
	while(1)
	{
		PORTB=0b11111111;
		Delay10KTCYx(100);
		PORTB=0b00000000;
		Delay10KTCYx(100);
	}
}