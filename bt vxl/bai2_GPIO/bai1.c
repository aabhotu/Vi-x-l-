#include <p18f4520.h>

#pragma config OSC = HS
#pragma config MCLRE = ON
#pragma config WDT=OFF
#pragma config LVP = OFF

#define PB1 PORTBbits.RB0
#define PB2 PORTBbits.RB1

int dem=0;
void main() 
   { 
     TRISB=0b00111111;
	ADCON1=0x0f;
      while(1)
      {
		if(PB1==1)
		{
			PORTB=0;
		}
		else
		{
			if(PB2==0)
			{
				while(PB2==0);
				dem++;
			}
			if(dem==0)
				PORTB=0b00000000;
			if(dem==1)
				PORTB=0b10000000;
			if(dem==2)
				PORTB=0b01000000;
			if(dem>=3)
				PORTB=0b11000000;
		}
      }
}