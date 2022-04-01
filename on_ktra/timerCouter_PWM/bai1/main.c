#include<p18f4520.h> 
#include<stdio.h> 
#include<delays.h> 
//c?u hình 
#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF

#define xung PORTCbits.RC2
void main ()
{
TRISC=0b11111011;;
ADCON1=0x0f;
T0CON=0b10001000;
while(1)
{
	TMR0H=(65536 - 750)/256;
	TMR0L=(65536 - 750)%256;
	while(INTCONbits.TMR0IF==0);
	xung=~xung;
	INTCONbits.TMR0IF=0;
}
}