#include<p18f4520.h> 
#include<stdio.h> 
#include<delays.h> 
//c?u h�nh 
#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF

#define LED1 PORTDbits.RD0
#define LED2 PORTDbits.RD1
#define LED3 PORTDbits.RD2

int i,j;
void ngat_uu_tien_cao(void); 
void ngat_uu_tien_thap(void); 
//�i?m d?t CTCPVN c� m?c uu ti�n cao UTC, vector 0008H 
#pragma code uu_tien_cao=0x08 
void ngat_cao(void) 
{ 
ngat_uu_tien_cao(); 
} 
#pragma code 
#pragma interrupt ngat_uu_tien_cao 
void ngat_uu_tien_cao(void) 
{ 
	LED3=0;
	for(i=0; i<5; i++)
	{
		LED1=~LED1;
		Delay10KTCYx(50);
	}
	INTCONbits.INT0IF=0;
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
	LED3=0;
	for(i=0; i<6; i++)
	{
		LED2=~LED2;
		Delay10KTCYx(50);
	}
	INTCON3bits.INT1IF=0;
}
void main ()
{
TRISD=0x00;
ADCON1=0x0f;
RCONbits.IPEN=1;
INTCONbits.GIE=1;
INTCONbits.PEIE=1;

INTCONbits.INT0IE=1;
INTCONbits.INT0IF=0;
INTCON2bits.INTEDG0=0;

INTCON3bits.INT1IE=1;
INTCON3bits.INT1IF=0;
INTCON3bits.INT1IP=0;
INTCON2bits.INTEDG1=0;
while(1)
{
	LED3=~LED3;
	Delay10KTCYx(50);
}
}