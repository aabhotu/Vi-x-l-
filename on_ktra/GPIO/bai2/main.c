#include <p18f4520.h>
#include <delays.h>

#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF 

#define KEY PORTEbits.RE2
#define LED1 PORTDbits.RD2
#define LED2 PORTDbits.RD4
#define LED3 PORTCbits.RC6
#define LED4 PORTBbits.RB3

int dem=0;
void main ()
{
	TRISB=0x00;
	TRISD=0x00;
	TRISC=0x00;
	TRISE=0b00000100;
	ADCON1=0x0f;
while(1)
{
	if(KEY==1) 
	{
		LED1=1;
		Delay10KTCYx(50);
		LED1=0;
		Delay10KTCYx(50);

		LED2=1;
		Delay10KTCYx(50);
		LED2=0;
		Delay10KTCYx(50);

		LED3=1;
		Delay10KTCYx(50);
		LED3=0;
		Delay10KTCYx(50);

		LED4=1;
		Delay10KTCYx(50);
		LED4=0;
		Delay10KTCYx(50);
	}
	else LED1=LED2=LED3=LED4=0;
}
	
}