#include<p18f4520.h> 
#include<stdio.h> 
#include<delays.h> 
//c?u hình 
#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF

#define LED1 PORTCbits.RC0
#define LED2 PORTCbits.RC1
#define LED3 PORTCbits.RC2

int i,j;
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
	LED3=0;
	for(i=0; i<3; i++)
	{
		LED1=~LED1;
		Delay10KTCYx(50);
	}
	INTCON3bits.INT2IF=0;
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
	for(i=0; i<5; i++)
	{
		LED2=~LED2;
		Delay10KTCYx(50);
	}
	INTCON3bits.INT1IF=0;
}
void main ()
{
TRISC=0x00;
ADCON1=0x0f;
RCONbits.IPEN=1;
INTCONbits.GIE=1;
INTCONbits.PEIE=1;

INTCON3bits.INT2IE=1;
INTCON3bits.INT2IF=0;
INTCON3bits.INT2IP=1;
INTCON2bits.INTEDG2=0;

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