#include <p18f4520.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config LVP=OFF
#pragma config WDT=OFF

#define LED PORTBbits.RB4
#define KEY PORTCbits.RC6

void main (void)
{
TRISB=0b00000000;
TRISC=0b11111111;
ADCON1=0x0f;
LED=0;
	while(1)
	{
		
		if(KEY==0)
		{
			while(KEY==0);
			LED=~LED;
		}
	}
}