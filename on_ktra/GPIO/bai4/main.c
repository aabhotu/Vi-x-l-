#include <p18f4520.h>
#include <delays.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTEbits.RE0
#define LED1 PORTDbits.RD4
#define LED2 PORTDbits.RD5
#define LED3 PORTDbits.RD6
#define LED4 PORTDbits.RD7

int dem=0;
void main (void)
{
	TRISD=0b00000000;
	TRISE=0b00000001;
	ADCON1=0x0f;
	while(1)
	{
		if(PB1==0)
		{
			while(PB1==0);
			dem++;
		}
	PORTD=(dem%16)<<4;
	}
}