#include <p18f4520.h>
#define XUNG PORTBbits.RB5

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config LVP = OFF
#pragma config WDT = OFF

void main (void)
{
TRISB = 0b11011111;  //RA5 chieu ra
ADCON1 = 0x0F;
// khoi tao timer
T1CON = 0b10100000;			//timer1, che do ghi/doc 16 bit
	while(1)
	{
		//tao tre tao xung
		T1CONbits.TMR1ON = 0;
		TMR1H = (65536-37500)/256;
		TMR1L = (65536-37500)%256;
		T1CONbits.TMR1ON = 1; //cho timer hoat dong
		while(PIR1bits.TMR1IF==0); //cho co tran - 37500 xung, 0,05s tre
		PIR1bits.TMR1IF=0; //xoa
		XUNG=~XUNG;	//xung co chu ki 0,1s
	}
}