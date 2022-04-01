#include <p18f4520.h>
#include <delays.h>
#include <adc.h>

#pragma config OSC = HS
#pragma config LVP = OFF
#pragma config MCLRE = ON
#pragma config WDT = OFF

//chuong trinh con

int adc;
float dienap;
void main(void)
{
//B1: khung chuong trinh
TRISB=0b11011111;
TRISC=0x00;
TRISD=0x00;
TRISA=0xff;
ADCON1=0b00001011;
OpenADC(ADC_FOSC_16&ADC_RIGHT_JUST&ADC_8_TAD, 
		ADC_CH3&ADC_INT_OFF&ADC_VREFPLUS_VDD&ADC_VREFMINUS_VSS, 11);
 
	while(1)
	{
		//B3: doc ADC
		ConvertADC();	//bat dau bien doi
		while(BusyADC());	//cho bien doi xong
		adc=ReadADC();
		//hien thi 
		PORTD=adc%256; 
		PORTC=adc/256<<5;	
		dienap=((float)adc*5)/1023;
		if((dienap>=2) && (dienap<=4))
			PORTBbits.RB5=1;
		else 
			PORTBbits.RB5=0;
	}
}