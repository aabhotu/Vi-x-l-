#include <p18f4520.h>
#include <delays.h>
#include <adc.h>

#pragma config OSC = HS
#pragma config LVP = OFF
#pragma config MCLRE = ON
#pragma config WDT = OFF

//chuong trinh con
int adc;
void main()
{
TRISA=0xff;
TRISC=0x00;
TRISD=0x00;
ADCON1=0x0e;
OpenADC( ADC_FOSC_8&ADC_RIGHT_JUST&ADC_0_TAD, 
		ADC_CH0&ADC_INT_OFF&ADC_VREFPLUS_VDD&ADC_VREFMINUS_VSS, 14); 
while(1)
{
	ConvertADC();
	while(ReadADC());
	adc = ReadADC();
	PORTC=adc;
	PORTD=adc>>8;
}
}