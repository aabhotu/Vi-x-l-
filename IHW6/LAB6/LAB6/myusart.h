#ifndef __MYUSART_H
#include<usart.h>
#include<stdio.h>
void Truyen_so_nguyen(int num);
int num;
char N[100];
void Truyen_so_nguyen(int num)
{
sprintf(&N[100],"%d", num);
putsUSART(&N[100]);
}
#endif