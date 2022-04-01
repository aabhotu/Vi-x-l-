#include<p18f4520.h>
#include<stdio.h>
#include <delays.h>
#include <adc.h>

#pragma config OSC=HS // Cau hinh bo dao dong
#pragma config MCLRE=ON // cau hinh chan reset
#pragma config LVP=OFF // Cam che do su dung nguon don
#pragma config WDT=OFF
#define 	LCD_DATA		PORTD
#define 	LCD_RS   		PORTEbits.RE0
#define 	LCD_RW   		PORTEbits.RE1
#define		LCD_EN   	 	PORTEbits.RE2

char message[32]; // mang luu chuoi can hien thi
int adc, ht;
float dienap, nhietdo;

void Lcd_configure(void);//KHOI TAO LCD
void Lcd_Write_Command(char command);//GHI LENH
void Lcd_Write_Data(char data);//GHI DATA
void Lcd_Write_String (char *str);

void Lcd_configure (void){	
Lcd_Write_Command(0x03);	//bat dau
Lcd_Write_Command(0x38);	//0011 1000
Lcd_Write_Command(0x06);
Lcd_Write_Command(0x0c);	
}
void Lcd_Write_Command (char command){ 
	LCD_RS=0;
	LCD_RW=0;
	LCD_EN=1;
	LCD_DATA=command;
	LCD_EN=0;
	Delay1KTCYx(10);										
}
void Lcd_Write_Data (char data){ 
	LCD_RS=1;
	LCD_RW=0;
	LCD_EN=1;
	LCD_DATA=data;
	LCD_EN=0;
	Delay1KTCYx(10);					
}
void Lcd_Write_String (char *str){
	while(*str)
	{
		Lcd_Write_Data(*str);
		str++;
	}
}
int chuyendoi_adc ()
{
	int ad;
	ConvertADC();
	while(BusyADC());
	ad=ReadADC();
	return ad;
}

void main()
{
TRISD=0x00;
TRISE=0x00;
TRISA=0xff;
ADCON1=0x0e;
Lcd_configure();
OpenADC(ADC_FOSC_8 & ADC_RIGHT_JUST &ADC_8_TAD, ADC_CH0 & 
		 ADC_INT_OFF& ADC_VREFPLUS_VDD& ADC_VREFMINUS_VSS, 
		 14);

Lcd_Write_Command(0x80);	//dau dong 1
sprintf(&message[0], "TB do nhiet do");
Lcd_Write_String(&message[0]);
	while(1)
	{
		adc=chuyendoi_adc();
		dienap = ((float)adc*5)/1023;
		nhietdo=dienap*100;
		ht=nhietdo*10;
		Lcd_Write_Command(0xc0);	//dau dong 1
		sprintf(&message[0], "nhiet do:%d.%d  ",ht/10, ht%10);
		Lcd_Write_String(&message[0]);
		Delay10KTCYx(10);
	}	
}

/*
10mV   0.01v  1 do
100mV  0.1v   10 do
1000   1v     100

*/