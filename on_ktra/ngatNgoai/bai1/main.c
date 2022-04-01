#include<p18f4520.h> 
#include<stdio.h> 
#include<delays.h> 
//c?u hình 
#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF 

#define LED1 PORTDbits.RD2
#define LED2 PORTDbits.RD4

int i=0;
void ngat_ngoai(void); 

#pragma code uu_tien_cao = 0x08 
void ngat_cao(void) 
{ 
 ngat_ngoai(); //g?i d?n CTCPVN 
} 
//Ði?m vi?t CTCPVN 
#pragma code 
#pragma interrupt ngat_ngoai 
void ngat_ngoai(void) 
//Noi dung cua CTCPVN 
{
	LED1=0;
	for(i; i<10; i++)
	{
		LED2=~LED2;
		Delay10KTCYx(50);
	}
	INTCON3bits.INT1IF=0;	
}
void main () 
{
TRISD=0x00;
TRISB=0xff;
ADCON1=0x0f;
RCONbits.IPEN=0;
INTCONbits.GIE=1;
INTCONbits.PEIE=1;
INTCON3bits.INT1IE=1;
INTCON3bits.INT1IF=0;
INTCON2bits.INTEDG1=0;
while(1)
{
	LED1=~LED1;
	Delay10KTCYx(50);
}
}