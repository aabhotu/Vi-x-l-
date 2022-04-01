#include <P18f4520.h>
#include <delays.h>
#include <usart.h>
#include "my_usart.h"
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

float num1 = 55.75;

void main()
{
TRISC=0x80;
ADCON1=0x0f;

OpenUSART( USART_TX_INT_OFF & //khong su dung ngat truyen
USART_RX_INT_OFF & //khong su dung ngat nhan
USART_ASYNCH_MODE & //che do khong dong bo
USART_EIGHT_BIT & //truyen/nhan 8bit
USART_CONT_RX & //cho phep nhan lien tiep
USART_BRGH_HIGH, //toc do baud cao
51);
truyen_so_thuc(num1);
while(1);
}