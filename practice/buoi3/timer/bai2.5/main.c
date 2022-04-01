#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF 
#pragma config LVP=OFF 

#define KEY PORTAbits.RA4

char M[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
//cau hinh he thong

int dem=0;
void main (void)
{
	ADCON1=0x0f;
	TRISB=0x00000000;
	TRISA=0x11111111;
	T0CON=0b11101000; //timer0, 8bits,xung T0CKI, HSC=1
	TMR0H=0;
	TMR0L=0;
	while (1)
	{
		dem=TMR0L;
		PORTB=M[dem%10];
	}
}