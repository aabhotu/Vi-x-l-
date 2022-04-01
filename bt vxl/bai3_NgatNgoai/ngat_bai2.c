#include <p18f4520.h>
#include <stdio.h>
#include <delays.h>

#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON
#pragma config PBADEN=OFF
//b2. chuong trinh ngat

int i, j;
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
	for(i=0; i<10; i++)
	{
		PORTCbits.RC0=~PORTCbits.RC0;
		Delay10KTCYx(50);
	}
	INTCONbits.INT0IF=0;}

#pragma code uu_tien_thap = 0x18 
void ngat_thap(void) 
{ 
ngat_uu_tien_thap(); 
} 
#pragma code 
#pragma interrupt ngat_uu_tien_thap 
void ngat_uu_tien_thap(void) 
{ 
	for(j=0; j<20; j++)
	{
		PORTCbits.RC1=~PORTCbits.RC1;
		Delay10KTCYx(50);
	}
	INTCON3bits.INT1IF=0;
}

void main (void)
{
	ADCON1=0x0F;
	TRISC=0b00000000;
	TRISB=0b11111111;

	RCONbits.IPEN=1;
	INTCONbits.GIE=1;	//cho phep ngat uu tien cao
	INTCONbits.PEIE=1;
	
	//INT0
	INTCONbits.INT0IE=1;
	INTCONbits.INT0IF=0;
	INTCON2bits.INTEDG0=0;

	//INT1
	INTCON3bits.INT1IE=1;
	INTCON3bits.INT1IF=0;
	INTCON3bits.INT1IP=0;	// uu tien thap
	INTCON2bits.INTEDG1=0;
	while (1)
	{
		PORTCbits.RC2=~PORTCbits.RC2;
		Delay10KTCYx(50);
	}
}