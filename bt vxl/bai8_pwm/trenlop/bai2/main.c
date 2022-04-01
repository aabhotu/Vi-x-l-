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
	TRISC=0b11111011;
	ADCON1=0X0F;
	OpenPWM1(124);
	OpenPWM2(124);
	T2CONbits.T2CKPS1=1;
	T2CONbits.T2CKPS0=1;

	SetDCPWM1(0);	//do rong =0
	SetDCPWM2(0);
	Delay10KTCYx(200);
	Delay10KTCYx(200);
	SetDCPWM1(375);	//do rong = 3 Toff
	SetDCPWM2(167);	//do rong = 1/2 Toff
	while (1)
	{
	}
}