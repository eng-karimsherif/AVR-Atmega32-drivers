/*
 * keypad.h
 *
 * Created: 21/07/2020 05:46:31
 *  Author: karim sherif
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_macros.h"

#define INIT_KEYPAD DDRB|=0b11110000; PORTB|=0b11110000; PORTD=0b00111100;


void keypad_init();

uint8_t keypad_read();


#endif /* KEYPAD_H_ */