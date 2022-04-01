#include<p18f4520.h> 
#include<stdio.h> 
#include<delays.h> 
//c?u hình 
#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF 
char M[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int dem =0;
//khai báo tên chuong trình con ph?c v? ng?t (CTCPVN) 
void ngat_ngoai(void); 
//Ði?m d?t chuong trình ph?c v? ng?t có m?c uu tiên cao (vector 0008H) 
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

	if(INTCON3bits.INT1IF==1)
	{
		dem++;
	}
	INTCON3bits.INT1IF=0;
}
void main ()
{
	TRISB=0b00000010;
	TRISD=0;
	ADCON1=0x0F;
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;
	INTCON3bits.INT1IE=1;
	INTCON3bits.INT1IP=0;
	INTCON2bits.INTEDG1=1;
	while (1)
	{
		PORTD=M[dem];
		if(dem>9) dem = 0;
	}
}