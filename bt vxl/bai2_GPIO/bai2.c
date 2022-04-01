#include <p18f4520.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT=OFF
#pragma config LVP = OFF

#define PB1 PORTBbits.RB4
#define LED1 PORTBbits.RB0
#define LED2 PORTBbits.RB1
#define LED3 PORTBbits.RB2
#define LED4 PORTBbits.RB3

int dem=0;
void main() 
{ 
	TRISB=0b01100000;
	ADCON1=0x0f;
	while(1)
	{
		if(PB1 == 0)
		{
			while (PB1 ==0);
			dem++;
		}
		if(dem==12) dem =0;
		if(dem == 0) 
		{
			LED1 = 0;
			LED2 = 0;
			LED3 = 0;
			LED4 = 0;
		}
		if (dem ==1 )
		{
			LED1 = 0;
			LED2 = 0;
			LED3 = 0;
			LED4 = 1;
		}
		if (dem ==2 )
		{
			LED1 = 0;
			LED2 = 0;
			LED3 = 1;
			LED4 = 0;
		}
		if (dem ==3 )
		{
			LED1 = 0;
			LED2 = 0;
			LED3 = 1;
			LED4 = 1;
		}
		if (dem ==4 )
		{
			LED1 = 0;
			LED2 = 1;
			LED3 = 0;
			LED4 = 0;
		}
		if (dem ==5 )
		{
			LED1 = 0;
			LED2 = 1;
			LED3 = 0;
			LED4 = 1;
		}
		if (dem ==6 )
		{
			LED1 = 0;
			LED2 = 1;
			LED3 = 1;
			LED4 = 0;
		}
		if (dem ==7 )
		{
			LED1 = 0;
			LED2 = 1;
			LED3 = 1;
			LED4 = 1;
		}
		if (dem ==8 )
		{
			LED1 = 1;
			LED2 = 0;
			LED3 = 0;
			LED4 = 0;
		}
		if (dem ==9 )
		{
			LED1 = 1;
			LED2 = 0;
			LED3 = 0;
			LED4 = 1;
		}
		if (dem ==10 )
		{
			LED1 = 1;
			LED2 = 0;
			LED3 = 1;
			LED4 = 0;
		}
		if (dem ==11 )
		{
			LED1 = 1;
			LED2 = 0;
			LED3 = 1;
			LED4 = 1;
		}
	}
}