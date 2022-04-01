#include<p18f4520.h> 
#include<stdio.h> 
#include<delays.h> 
//c?u hình 
#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF 

#define KEY1 PORTDbits.RD1
#define KEY2 PORTEbits.RE1

char M[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int dem = 0;

void main (void)
{
	TRISC=0x00;
	ADCON1=0x0f;
	TRISD=0b00000010;
	TRISE=0b00000010;
	while (1)
	{
		if(KEY1==0 &&KEY2==1)
		{
			dem++;
		}
		else if(KEY1==1 &&KEY2==0)
		{
			dem--;
		}
		PORTC=M[dem];
	}
}