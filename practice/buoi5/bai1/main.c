
#include <p18f4520.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config LVP = OFF
#pragma config WDT = OFF

#define xung PORTCbits.RC7
void main (void)
{
TRISC = 0b01111111;  
ADCON1 = 0x0F;
// khoi tao timer
T2CON = 0b00100101;	
PR2 = 249;
	while(1)
	{
		//tao tre tao xung

		while(PIR1bits.TMR2IF==0);	//cho co tran
		xung=~xung;
		PIR1bits.TMR2IF=0;
	}
}