#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF 
#pragma config LVP=OFF 

char M[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
//cau hinh he thong

int dem=0;
void main (void)
{
	ADCON1=0x0f;
	TRISD=0x00000000;
	TRISC=0x11111111;
	T1CON=0b11000111; //timer1, 16bits,xung T13CKI, HSC=1
	TMR1H=0;
	TMR1L=0;
	while (1)
	{
		dem=TMR1L;
		PORTD=M[dem%10];
	}
}