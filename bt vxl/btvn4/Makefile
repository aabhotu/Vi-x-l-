# MPLAB IDE generated this makefile for use with GNU make.
# Project: bai1.mcp
# Date: Fri Oct 15 14:34:35 2021

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

bai1.cof : bai1.o
	$(LD) /p18F4520 /l"D:\Mplap\maplap v3.47\lib" "bai1.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"bai1.cof" /M"bai1.map" /W

bai1.o : bai1.c ../../../Mplap/maplap\ v3.47/h/p18f4520.h
	$(CC) -p=18F4520 "bai1.c" -fo="bai1.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "bai1.o" "bai1.cof" "bai1.hex"

