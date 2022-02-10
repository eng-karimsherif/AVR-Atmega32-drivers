/*
 * uart.c
 *
 * Created: 06/08/2020 15:46:26
 *  Author: karim sherif
 */ 

#include "uart.h"

//9600 
//frame: 1 start , 1 stop  , no parity , 8-bit data 

void uart_init(){
	// set the baud rate 9600, F_CPU=16Mhz
	CLRBIT(UBRRH,URSEL); //select the register UBRRH
	UBRRL=103;
	
	CLRBIT(UCSRA,U2X); // operate UART in normal speed
	SETBIT(UCSRB,RXEN); // enable UART receiving
	SETBIT(UCSRB,TXEN); // enable UART transmitting
	SETBIT(UCSRC,URSEL); //select the register UCSRC
	SETBIT(UCSRC,UCSZ0); SETBIT(UCSRC,UCSZ1); CLRBIT(UCSRB,UCSZ0); // set 8-bit data
	CLRBIT(UCSRC,USBS); // set 1-bit stop in frame
	CLRBIT(UCSRC,UMSEL); // asynchronous UART
	CLRBIT(UCSRC,UPM0); CLRBIT(UCSRC,UPM1); // disable parity mode
}

void uart_write(uint8_t data){

    SETBIT(UCSRA,TXC); // manually clearing TXC by put logic 1 in it
    UDR=data;
	while(READBIT(UCSRA,TXC)==0){} // check trans	
	
}

uint8_t uart_read(){
	while(READBIT(UCSRA,RXC)==0){} // check recieving
	return UDR;
}

void uart_write_string(uint8_t *string){
	uint8_t i;
	for (i=0;string[i]!='\0';i++)
	{
		uart_write(string[i]);
	}
}