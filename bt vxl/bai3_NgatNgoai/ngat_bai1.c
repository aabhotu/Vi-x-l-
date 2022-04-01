#include <p18f4520.h>
#include <stdio.h>
#include <delays.h>

#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON
#pragma config PBADEN=OFF


void ngat_ngoai(void); 
int sp=0;

#pragma code uu_tien_cao = 0x08 

void ngat_cao(void) 
{ 
 ngat_ngoai(); 
} 

#pragma code 
#pragma interrupt ngat_ngoai 
void ngat_ngoai(void) 
//Noi dung cua CTCPVN 
{
	sp++;
	PORTC=sp%16;
	INTCON3bits.INT2IF=0;
}

void main (void)
{
	ADCON1=0x0F;
	TRISC=0b00000000;
	TRISB=0b11111111;

	RCONbits.IPEN=0;
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;

	INTCON3bits.INT2IE=1;
	INTCON3bits.INT2IP=1;
	INTCON2bits.INTEDG2=0;
	PORTC=0;
	while (1)
	{
		
	}
}