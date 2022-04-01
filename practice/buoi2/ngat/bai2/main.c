#include <p18f4520.h>
#include <delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF
#pragma config LVP=OFF

#define KEY PORTBbits.RB0

int dem=0;
void ngat_ngoai(void); 
 
#pragma code uu_tien_cao = 0x08 
 
void ngat_cao(void) 
{ 
 ngat_ngoai(); 
} 
//Ði?m vi?t CTCPVN 
#pragma code 
#pragma interrupt ngat_ngoai 
void ngat_ngoai(void) 
//Noi dung cua CTCPVN 
{

	dem++;
	PORTC=dem<<4;
	INTCONbits.INT0IF=0;
}
void main(void)
{
	ADCON1=0x0f;
	TRISC=0b00000000;
	TRISB=0b11111111;
	
	RCONbits.IPEN=0;
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;
	
	INTCONbits.INT0IE=1;
	INTCONbits.INT0IF=0;
	INTCON2bits.INTEDG0=0;	//ngat suon am

	while(1)
	{
		PORTCbits.RC7=~PORTCbits.RC7;
		Delay10KTCYx(50);
	}
}