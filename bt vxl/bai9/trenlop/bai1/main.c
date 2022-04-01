// Timer0
/*
	Fosc=4M Hz
	Delay = 0.01 S
	TimerCount 	= Delay * (Fosc/4PV)
				=    10000/PV
	PV = 2
	TimerCount = 5000 
*/

// B1 . Viet khung CT vi dieu khien PIC
#include<p18f4520.h>
#include<delays.h>
#include<pwm.h>

#pragma config OSC = HS
#pragma config LVP = OFF
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config CCP2MX = PORTBE


unsigned char ma_led[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
char i,tr,ng,ch,dv;
unsigned int sp;


void ngat_uu_tien_cao(void);
void ngat_uu_tien_thap(void);
//Ði?m d?t CTCPVN có m?c uu tiên cao UTC, vector 0008H
#pragma code uu_tien_cao=0x08
void ngat_cao(void)
{
ngat_uu_tien_cao();
}
#pragma code
#pragma interrupt ngat_uu_tien_cao
void ngat_uu_tien_cao(void)
{

	if(INTCONbits.TMR0IF==1)
	{
		TMR0H= (65536-5000)/256;
		TMR0L= (65536-5000)%256;
		PORTDbits.RD7=~PORTDbits.RD7;
		
		i++;
		if(i>4) i=1;
		if(i==1)
		{
			PORTD=0b00000001;
			PORTC=ma_led[ng];
		}
		else if(i==2)
		{
			PORTD=0b00000010;
			PORTC=ma_led[tr];
		}
		else if(i==3)
		{
			PORTD=0b00000100;
			PORTC=ma_led[ch];
		}
		else if(i==4)
		{
			PORTD=0b00001000;
			PORTC=ma_led[dv];
		}
		INTCONbits.TMR0IF=0;	
	}
}

#pragma code uu_tien_thap = 0x18
void ngat_thap(void)
{
ngat_uu_tien_thap();
}
#pragma code
#pragma interrupt ngat_uu_tien_thap
void ngat_uu_tien_thap(void)
{
	if(INTCON3bits.INT1IF==1)
	{
		sp++;
		ng=sp/1000;
		tr=(sp%1000)/100;
		ch=((sp%1000)%100)/10;
		dv=sp%10;
		INTCON3bits.INT1IF=0;
	}
}

void main (void)
{
// Buoc 2. Khoi tao vào /ra; thiet lap chu ky
TRISC=0b00000000;
TRISD=0b00000000;
TRISB=0b11111111;
ADCON1=0x0f;
// Khoi tao Timer
T0CON=0b10000000; // 16 bit, Fosc, chia 2
TMR0H= (65536-5000)/256;
TMR0L= (65536-5000)%256;

// Khoi tao ngat Timer
RCONbits.IPEN=1; // lua chon uu tien ngat
INTCONbits.GIE=1;
INTCONbits.PEIE=1;

INTCONbits.TMR0IE=1;
INTCONbits.TMR0IF=0;
INTCON2bits.TMR0IP=1;
// Khoi tao ngat ngoai INT1

INTCON3bits.INT1IE=1;
INTCON3bits.INT1IF=0;
INTCON3bits.INT1IP=0;
INTCON2bits.INTEDG1=0; // suon am


sp=5678;
ng=sp/1000;
tr=(sp%1000)/100;
ch=((sp%1000)%100)/10;
dv=sp%10;
	while(1)
	{

	}
}