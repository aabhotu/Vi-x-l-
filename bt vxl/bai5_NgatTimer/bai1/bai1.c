#include <p18f4520.h>
#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config MCLRE=ON

#define xung PORTDbits.RD0


void ngat_ngoai(void); 

#pragma code uu_tien_cao = 0x08 

void ngat_cao(void) 
{ 
 ngat_ngoai(); 
} 

#pragma code 
#pragma interrupt ngat_ngoai 
void ngat_ngoai(void) 
//Noi dung cua CTCPVN 
{
	T0CONbits.TMR0ON=0;  //dung timer
	TMR0H = (65536-15625)/256;
	TMR0L = (65536-15625)%256;
	T0CONbits.TMR0ON = 1;
	xung = ~xung;
	INTCONbits.TMR0IF = 0;	//xoa co tran

}

void main (void)
{
	ADCON1=0x0F;
	T0CON = 0b00000100;
	TRISD = 0x00;
	//cau hinh dieu khien ngat
	RCONbits.IPEN = 1;	//bit cho phep uu tien ngat
	INTCON2bits.TMR0IP = 1; 	//timer0 uu tien cao
	INTCON = 0b11100000; //GIE/GIEH = 1, PEIE/GIEL = 1, TMR0IE = 1
	//ghi gia tri khoi tao cho thanh ghi chua so dem cua timer0
	TMR0H = (65536-15625)/256;
	TMR0L = (65536-15625)%256;
	T0CONbits.TMR0ON = 1; 	//bat timer0
	while (1)
	{
		
	}
}