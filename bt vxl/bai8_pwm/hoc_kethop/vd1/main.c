#include <p18f4520.h>
#include <delays.h>
#include <pwm.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config MCLRE=ON
#pragma config WDT=OFF

void main(void)
{
TRISC=0x00;
ADCON1=0x0f;
OpenPWM1(124);
T2CONbits.T2CKPS1=1;	//chia 16
T2CONbits.T2CKPS0=1;
SetDCPWM1(350);  //70%
	while (1)
	{
	}
}