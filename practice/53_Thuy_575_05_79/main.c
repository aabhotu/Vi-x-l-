
#include <p18f4520.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config LVP = OFF
#pragma config WDT = OFF

#define xung PORTEbits.RE1
#define KEY PORTEbits.RE0
void main (void)
{
TRISE = 0b00000101;  
ADCON1 = 0x0F;
// khoi tao timer
T3CON = 0b11010101;			//timer3, che do ghi/doc 16 bit chia 1
	while(1)
	{
		//tao tre tao xung
	if(KEY == 0)
	{
		PORTE = 0;
	}
	else
	{
		TMR3H = (65536-2000)/256;
		TMR3L = (65536-2000)%256;
		while(PIR2bits.TMR3IF==0);	//cho co tran
		xung=~xung;
		PIR2bits.TMR3IF=0;
	}
	}
}