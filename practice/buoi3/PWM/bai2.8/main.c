#include <p18f4520.h>
#include <delays.h>
#include <pwm.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF
#pragma config CCP2MX=PORTC

#define KEY PORTBbits.RB0

int dem=0;
void main (void)
{
TRISB=0b11111111;
TRISC=0b00000000;
ADCON1=0X0F;

OpenPWM2(99);
T2CONbits.T2CKPS1=0;
T2CONbits.T2CKPS0=0;
SetDCPWM2(360);	//do rong =0

	while (1)
	{
		if(KEY==0)
		{
			while(KEY==0);
			dem++;
		}
		if(dem==1) SetDCPWM2(120);
		else if(dem==2) SetDCPWM2(280);
		else if(dem>2) SetDCPWM2(360);
	}
}