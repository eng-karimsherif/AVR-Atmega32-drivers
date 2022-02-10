/*
 * uart.h
 *
 * Created: 06/08/2020 15:46:39
 *  Author: karim sherif
 */ 


#ifndef UART_H_
#define UART_H_
#include "std_macros.h"

void uart_init(); // data 8-bit
void uart_write(uint8_t);
uint8_t uart_read();
void uart_write_string(uint8_t *);


#endif /* UART_H_ */