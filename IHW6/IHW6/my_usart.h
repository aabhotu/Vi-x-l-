#ifndef __MYUSART_H
#include<usart.h>
#include<stdio.h>
void truyen_so_thuc(float num1);
char M[5];
int num;
int nghin, tram, chuc, donvi;
void truyen_so_thuc(float num1)
{
num= num1*100;
nghin=num/1000;
tram=(num%1000)/100;
chuc=((num%1000)%100)/10;
donvi=((num%1000)%100)%10;
sprintf(&M[5],"%2d%2d.%2d%2d",nghin,tram,chuc,donvi);
putsUSART(&M[5]);
}
#endif