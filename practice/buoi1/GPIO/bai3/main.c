#include <p18f4520.h>
#include <delays.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF

#define PB1 PORTBbits.RB0
#define LED1 PORTDbits.RD0
#define LED2 PORTDbits.RD1
#define LED3 PORTDbits.RD2
#define LED4 PORTDbits.RD3

int dem=0;
void main (void)
{
	TRISD=0b00000000;
	TRISB=0b11111111;
	ADCON1=0x0f;
	while(1)
	{
		if(PB1==0)
		{
			while(PB1==0);
			dem++;
		}
	PORTD=dem%16;
	}
}