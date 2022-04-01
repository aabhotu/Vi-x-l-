#include <p18f4520.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config MCLRE = ON

#define xung PORTBbits.RB5
//buoc2: khung ngat
void ngat_ngoai(void); 

#pragma code uu_tien_cao = 0x08 

void ngat_cao(void) 
{ 
 ngat_ngoai(); //g?i d?n CTCPVN 
} 

#pragma code 
#pragma interrupt ngat_ngoai 
void ngat_ngoai(void) 
//Noi dung cua CTCPVN 
{
	TMR1H=(65536-5000)/256;
	TMR1L=(65536-5000)%256;
	PIR1bits.TMR1IF=0;
	xung=~xung;
}
void main()
{
	TRISB=0x00;
	ADCON1=0x0f;
	//buoc4: khoi tao ngat, khoi tao timer
	//IPEN, GIE, PEIE, IE, IF, IP
	RCONbits.IPEN=0;
	INTCONbits.GIE=1;	// cho phep ngat
	INTCONbits.PEIE=1;
	PIE1bits.TMR1IE=1;
	PIR1bits.TMR1IF=0;	//xoa co ngat
	IPR1bits.TMR1IP=1;
	//T1CON
	T1CON=0b10100001;

	while(1)
	{
		
	}
}