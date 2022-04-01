#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF

char M[]= {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int i = 0;
int j = 0;

void ngat_uu_tien_cao(void); 
void ngat_uu_tien_thap(void); 

#pragma code uu_tien_cao=0x08 
void ngat_cao(void) 
{ 
ngat_uu_tien_cao(); 
} 
#pragma code 
#pragma interrupt ngat_uu_tien_cao 
void ngat_uu_tien_cao(void) 
{ 
	if (INTCONbits.INT0IF == 1)
	{
		i++;
	}
	INTCONbits.INT0IF =0;}

#pragma code uu_tien_thap=0x18 
void ngat_thap(void) 
{ 
ngat_uu_tien_thap(); 
} 
#pragma code 
#pragma interrupt ngat_uu_tien_thap 
void ngat_uu_tien_thap(void) 
{ 
		if (INTCON3bits.INT1IF == 1)
	{
		j++;
	}
	INTCON3bits.INT1IF=0;
}

void main (void)
{
	ADCON1=0x0F;
	TRISB=0b00000111;
	TRISC=0;
	TRISD=0;
	RCONbits.IPEN=1;
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;

	INTCONbits.INT0IE=1;
	INTCONbits.INT0IF =0;
	INTCON2bits.INTEDG0=0;

	INTCON3bits.INT1IP=0;
	INTCON3bits.INT1IE=1;
	INTCON3bits.INT1IF=0;
	INTCON2bits.INTEDG1=0;

	while (1)
	{
		PORTC=M[i];
		if (i>9) i = 0;

		PORTD=M[j];
		if (j>9) j = 0;
	}
}