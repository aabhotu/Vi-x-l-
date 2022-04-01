#include <p18f4520.h>

#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF 

#define KEY1 PORTAbits.RA1
#define KEY2 PORTCbits.RC1
#define LED1 PORTDbits.RD2
#define LED2 PORTDbits.RD4

int dem=0;
void main ()
{
	TRISA=0xff;
	TRISD=0x00;
	TRISC=0xff;
	ADCON1=0x0f;
	if(KEY2 == 0)
	{
		while(KEY2==0);
		dem++;
	}
	if(KEY1 == 1)
	{
		LED1=LED2=0;
	}
	else if(KEY1==0)
	{
		if(dem==1) {LED1 =0; LED2=1;}
		if(dem==2) {LED1 =1; LED2=0;}
		if(dem>=3) {LED1=LED2=1;}
	}
}