#include <P18f4520.h>
#include <delays.h>
#include <usart.h>
#include "myusart.h"
#include <stdio.h>
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

char M[]= {" DH CN HA NOI\r\n"};
int num=2709;
void main()
{
TRISC=0x80;
ADCON1=0x0f;
OpenUSART(USART_TX_INT_OFF & 
			USART_RX_INT_OFF &
			USART_ASYNCH_MODE &
			USART_EIGHT_BIT &
			USART_CONT_RX &
			USART_BRGH_HIGH, 51); // Nbaud=9600; F=8MHz
putsUSART(M);
Truyen_so_nguyen(num);
while(1);			
}