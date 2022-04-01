#include<p18f4520.h> 
#include<stdio.h> 
#include<delays.h> 
//c?u hình 
#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF 

#define LED5 PORTEbits.RE0
int dem = 0;

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
	LED5=0;
	dem++;
	PORTD=(dem%10);
	INTCONbits.INT0IF=0;
}
void main ()
{
TRISD=0x00;
TRISE=0x00;
TRISB=0xff;
ADCON1=0x0f;
RCONbits.IPEN=0;
INTCONbits.GIE=1;
INTCONbits.PEIE=1;
INTCONbits.INT0IE=1;
INTCONbits.INT0IF=0;
INTCON2bits.INTEDG0=0;
while(1)
{
	LED5=~LED5;
	Delay10KTCYx(50);

}
}