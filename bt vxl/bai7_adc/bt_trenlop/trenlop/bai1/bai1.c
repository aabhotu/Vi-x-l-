#include <p18f4520.h>
#include <delays.h>
#include <adc.h>

#pragma config OSC = HS
#pragma config LVP = OFF
#pragma config MCLRE = ON
#pragma config WDT = OFF

//chuong trinh con

int adc;
void main(void)
{
//B1: khung chuong trinh
TRISC=0x00;
TRISD=0x00;
TRISA=0xff;
ADCON1=0b00001101;
OpenADC(ADC_FOSC_16&ADC_RIGHT_JUST&ADC_8_TAD, 
		ADC_CH1&ADC_INT_OFF&ADC_VREFPLUS_VDD&ADC_VREFMINUS_VSS, 13);
 
	while(1)
	{
		//B3: doc ADC
		ConvertADC();	//bat dau bien doi
		while(BusyADC());	//cho bien doi xong
		adc=ReadADC();
		//hien thi 
		PORTC=adc%256; //bit cao
		PORTD=adc/256;	//bit thap
	}
}