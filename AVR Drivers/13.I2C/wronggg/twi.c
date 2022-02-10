/*
 * twi.c
 *
 * Created: 11/08/2020 10:17:17
 *  Author: karim
 */ 

#include "twi.h"

// scl freq = 400 Khz where F_CPU=16Mhz -- TWPS=0 -- TWBR=12

void twi_master_init(){
	TWBR=12;
	CLRBIT(TWCR,TWPS0); CLRBIT(TWCR,TWPS1);
}

void twi_start_master(){
	//TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	
	SETBIT(TWCR,TWINT); // clear TWINT bit  by write logic 1 on it
	SETBIT(TWCR,TWSTA); // send start condition
	SETBIT(TWCR,TWEN);  // enable TWI comm protocol
	
	while (READBIT(TWCR,TWINT)==0){} // polling on bit TWINT to asure if it finish current job
}


void twi_master_address (uint8_t adress){
	/*TWDR = adress<<1; // write operation
	CLRBIT(TWDR,0); // clear LSB to enable write
	TWCR = (1<<TWINT) | (1<<TWEN);*/
	
	TWDR =adress<<1; // setup the adress of slave on last 7 bits on TWDR
	CLRBIT(TWDR,0); // clear LSB to enable writeË
	SETBIT(TWCR,TWINT); // clear TWINT bit  by write logic 1 on it
	SETBIT(TWCR,TWEN);  // enable TWI comm protocol
	
	while (READBIT(TWCR,TWINT)==0){} // polling on bit TWINT to asure if it finish current job
}

void twi_master_data (uint8_t data){
	/*TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);*/
	
	TWDR =data; // setup the data on TWDR
	SETBIT(TWCR,TWINT); // clear TWINT bit  by write logic 1 on it
	SETBIT(TWCR,TWEN);  // enable TWI comm protocol
	
    while (READBIT(TWCR,TWINT)==0){} // polling on bit TWINT to asure if it finish current job
}

void twi_master_stop(){
	/*TWCR = (1<<TWINT) | (1<<TWSTO) | 1<<TWEN;*/
	
	SETBIT(TWCR,TWINT); // clear TWINT bit  by write logic 1 on it
	SETBIT(TWCR,TWEN);  // enable TWI comm protocol
	SETBIT(TWCR,TWSTO);
}

void twi_slave_init(uint8_t address){
	
	TWAR = address<<1;
}

uint8_t twi_Slave_available(){
	/*TWCR  = (1<<TWEN) | (1<<TWINT) |(1<<TWEA);*/
	
	SETBIT(TWCR,TWEA);  // enable ACK
	SETBIT(TWCR,TWINT); // clear TWINT bit  by write logic 1 on it
	SETBIT(TWCR,TWEN);  // enable TWI comm protocol
    while (READBIT(TWCR,TWINT)==0){} // polling on bit TWINT to asure if it finish current job
    if(TWSR == 0x60) {return 1;} // check status register if slave recieve the start bit + own adress + write requesr from slave
    else {return 0;}
}

uint8_t twi_Slave_read(){
	/*TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);*/
	
	SETBIT(TWCR,TWEA);  // enable ACK
	SETBIT(TWCR,TWINT); // clear TWINT bit  by write logic 1 on it
	SETBIT(TWCR,TWEN);  // enable TWI comm protocol
	while (READBIT(TWCR,TWINT)==0){} // polling on bit TWINT to asure if it finish current job
    return TWDR; //return received data from TWDR
}