/*
 * seven_segment.h
 *
 * Created: 21/07/2020 00:53:44
 *  Author: karim sherif
 */ 

#include "std_macros.h"

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#define INIT_7SEG DDRA=0x11; DDRC |=0b11000000; DDRB |=0b00000001;

#define EN1(x) if (x==0) CLRBIT(PORTC,6); else SETBIT(PORTC,6);
#define EN2(x) if (x==0) CLRBIT(PORTC,7); else SETBIT(PORTC,7);
#define A(x) if (x==0) CLRBIT(PORTA,1); else SETBIT(PORTA,1);
#define B(x) if (x==0) CLRBIT(PORTA,2); else SETBIT(PORTA,2);
#define C(x) if (x==0) CLRBIT(PORTA,3); else SETBIT(PORTA,3);
#define D(x) if (x==0) CLRBIT(PORTA,4); else SETBIT(PORTA,4);
#define E(x) if (x==0) CLRBIT(PORTA,5); else SETBIT(PORTA,5);
#define F(x) if (x==0) CLRBIT(PORTA,6); else SETBIT(PORTA,6);
#define G(x) if (x==0) CLRBIT(PORTA,7); else SETBIT(PORTA,7);
#define DOT(x) if (x==0) CLRBIT(PORTB,0); else SETBIT(PORTB,0);



void init_7_seg (void);
void write_7_seg (uint8_t);
void write_digit (uint8_t);






#endif /* SEVEN_SEGMENT_H_ */