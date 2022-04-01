#include <p18f4520.h>
#include <delays.h>
#include <pwm.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF
#pragma config CCP2MX=PORTBE

#define S1 PORTDbits.RD0
#define S2 PORTDbits.RD1
#define S3 PORTDbits.RD2
#define OFF PORTDbits.RD3

void main (void)
{
	TRISB=0b11110111;
	TRISD=0b11111111;
	ADCON1=0X0F;
	OpenPWM2(124);
	T2CONbits.T2CKPS1=1;
	T2CONbits.T2CKPS0=1;

	SetDCPWM2(0);
	if (S1==0) SetDCPWM2(200);
	else if(S2==0) SetDCPWM2(300);
	else if (S3==0) SetDCPWM2(400);
	else if(OFF==0) SetDCPWM2(0);
	
	while (1)
	{
	}
}