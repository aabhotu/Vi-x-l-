#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config LVP = OFF

#define KEY1 PORTBbits.RB1

char M[]= {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int dem = 0;

void ngat_ngoai(void);
#pragma code uu_tien_cao = 0x08

void ngat_cao(void)
{
	ngat_ngoai();
}

#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai(void)
{
	if (INTCON3bits.INT1IF == 1)
	{
		dem ++;
	}
	INTCON3bits.INT1IF = 0;
}

void main (void)
{
	TRISB=0b00000010;
	TRISD=0;
	ADCON1= 0x0F;
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;
	INTCON3bits.INT1IE=1;
	INTCON2bits.INTEDG1=1;
	while (1)
	{
		PORTD=M[dem];
		if (dem >9) dem =0;
	}
}