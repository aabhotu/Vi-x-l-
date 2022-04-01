#include <P18f4520.h> 
#include <delays.h> 
//C?u hình cho vi di?u khi?n, ví d?: 
#pragma config OSC = HS //ch? d? dao d?ng HS 
#pragma config MCLRE = ON //s? d?ng RE3 làm chân reset (OFF: không s? d?ng) 
#pragma config WDT = OFF //không dùng Watchdog timer 
#pragma config PBADEN = OFF //PORTB<4:0> du?c c?u hình thành các chân vào/ra s? 
 //ON: PORTB<4:0> du?c c?u hình thành các chân AN8-AN12 
#pragma config PWRT=ON // s? d?ng Power-up timer 
#pragma config BOREN=OFF // không s? d?ng ch?c nang Bown-out reset 
//(reset khi Vdd xu?ng th?p du?i 1 ngu?ng) 
#pragma config LVP=OFF //không d?ng ch? d? c?p ngu?n ch? t? m?ch n?p 
//(Single-Supply ICSP Programming) 

#define LED1 PORTAbits.RA0
#define LED2 PORTAbits.RA1

char M[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

int dem=0;
void ngat_ngoai(void);
//Ði?m d?t chuong trình ph?c v? ng?t có m?c uu tiên cao (vector 0008H)
#pragma code uu_tien_cao = 0x08
// N?u là chuong trình ph?c v? ng?t có m?c uu tiên th?p (vector 0018H):
// #pragma code uu_tien_thap = 0x18
//Vi?t 1 chuong trình con (có tên tùy ch?n) d? g?i t?i CTCPVN
void ngat_cao(void)
{
 ngat_ngoai(); //g?i d?n CTCPVN
}
//Ði?m vi?t CTCPVN
#pragma code
#pragma interrupt ngat_ngoai
void ngat_ngoai(void) 
{
	if(INTCONbits.INT0IF==1)
	{dem++;
	if(dem > 99) dem =0;
	}
	INTCONbits.INT0IF=0;

	if(INTCON3bits.INT1IF==1)
	{dem--;
	if(dem < 0) dem =99;
	}
	INTCON3bits.INT1IF=0;
}
void main ()
{
	TRISB=0b00000011;
	TRISA=0;
	TRISC=0;
	ADCON1=0x0F;
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;
	INTCONbits.INT0IE=1;
	INTCON2bits.INTEDG0=1;
	INTCON3bits.INT1IE=1;
	while (1)
	{
		LED1 =  1; LED2 = 0;
		PORTC=M[(dem)/10];
		Delay10KTCYx(2);
		LED1 =  0; LED2 = 1;
		PORTC=M[(dem)%10];
		Delay10KTCYx(2);
	}
}