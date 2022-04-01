#include <p18f4520.h>
#include <delays.h>
#include <pwm.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF
#pragma config CCP2MX=PORTBE

void main (void)
{
TRISB=0b11110111;
ADCON1=0X0F;
OpenPWM2(249);
T2CONbits.T2CKPS1=1;
T2CONbits.T2CKPS0=1;
SetDCPWM2(0);	//do rong =0
Delay10KTCYx(200);
Delay10KTCYx(200);
SetDCPWM2(667);	//do rong = 2 Toff
	while (1)
	{
	}
}