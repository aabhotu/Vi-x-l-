#include <p18f4520.h>
#include <delays.h>
#include <pwm.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF
#pragma config CCP2MX=PORTC

#define KEY1 PORTBbits.RB0
#define KEY2 PORTBbits.RB3

void main (void)
{
TRISB=0b11111111;
TRISC=0b00000000;
ADCON1=0X0F;

OpenPWM2(149);
T2CONbits.T2CKPS1=0;
T2CONbits.T2CKPS0=1;
SetDCPWM2(120);	//do rong =0

	while (1)
	{
		if(KEY1==0) SetDCPWM2(180);
		else if(KEY2==0) SetDCPWM2(360);
	}
}