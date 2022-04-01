#include <p18f4520.h>
#include <delays.h>

#pragma config OSC=HS
#pragma config MCLRE=ON
#pragma config WDT=OFF
#pragma config LVP=OFF

#define LED1 PORTCbits.RC2
#define LED2 PORTCbits.RC4
#define KEY PORTBbits.RB1

int i=0;
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
	LED1=0;
	for(i=0; i<20; i++)
	{
		LED2=~LED2;
		Delay10KTCYx(50);
	}
	INTCON3bits.INT1IF=0;
}
void main(void)
{
	ADCON1=0x0f;
	TRISC=0b00000000;
	TRISB=0b11111111;
	
	RCONbits.IPEN=0;
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;
	
	INTCON3bits.INT1IE=1;
	INTCON3bits.INT1IF=0;
	INTCON3bits.INT1IP=1;
	INTCON2bits.INTEDG1=0;	//ngat suon am

	while(1)
	{
		LED1=~LED1;
		Delay10KTCYx(50);
	}
}