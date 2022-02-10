/*
 * spi.c
 *
 * Created: 09/08/2020 14:12:06
 *  Author: karim
 */ 

#include "spi.h"

void master_init_spi(){
	SETBIT(DDRB,MOSI); // setup MOSI pin as output
	SETBIT(DDRB,SCK);  // setup SCK pin as output
	SETBIT(DDRB,SS);   // setup SS pin as output
	CLRBIT(DDRB,MISO); // setup MISO pin as input
	CLRBIT(SPCR,DORD); // MSB of data is transmitted first
	SETBIT(SPCR,MSTR); // master mode
	SETBIT(SPCR,SPE); // enable SPI communication protocol
	CLRBIT(SPCR,SPR1); CLRBIT(SPCR,SPR0); CLRBIT(SPSR,SPI2X); // setup clock as F_CPU/4	
}


void slave_init_spi(){
	CLRBIT(DDRB,MOSI); // setup MOSI pin as input
	CLRBIT(DDRB,SCK);  // setup SCK pin as input
	CLRBIT(DDRB,SS);   // setup SS pin as input
	SETBIT(DDRB,MISO); // setup MISO pin as output
	CLRBIT(SPCR,DORD); // MSB of data is transmitted first
	CLRBIT(SPCR,MSTR); // slave mode
	CLRBIT(SPCR,SPR1); CLRBIT(SPCR,SPR0); CLRBIT(SPSR,SPI2X); // setup clock as F_CPU/4
	SETBIT(SPCR,SPE); // enable SPI communication protocol
}

void spi_send_char(uint8_t data){
	SPDR=data;
	while(READBIT(SPSR,SPIF)==0){}
}

uint8_t spi_recieve_char(){
	while (READBIT(SPSR,SPIF)==0){}
	return SPDR;
}

uint8_t spi_tx_rx(uint8_t data){
	SPDR=data;
	while (READBIT(SPSR,SPIF)==0){}
	return SPDR;
}