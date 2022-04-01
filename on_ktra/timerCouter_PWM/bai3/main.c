#include<p18f4520.h> 
#include<stdio.h> 
#include<delays.h> 
//c?u hình 
#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF

#define xung PORTDbits.RD3
void main ()
{
TRISD=0b11110111;;
ADCON1=0x0f;
T1CON=0b11011101;
while(1)
{
	TMR1H=(65536 - 500)/256;
	TMR1L=(65536 - 500)%256;
	while(PIR1bits.TMR1IF==0);
	xung=~xung;
	PIR1bits.TMR1IF=0;
}
}