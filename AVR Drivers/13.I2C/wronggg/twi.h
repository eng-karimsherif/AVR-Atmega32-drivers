/*
 * twi.h
 *
 * Created: 11/08/2020 10:17:01
 *  Author: karim
 */ 


#ifndef TWI_H_
#define TWI_H_
#include "std_macros.h"

void twi_master_init();
void twi_start_master();
void twi_master_address (uint8_t);
void twi_master_data (uint8_t);
void twi_master_stop();

void twi_slave_init(uint8_t);
uint8_t twi_Slave_available();
uint8_t twi_Slave_read();


#endif /* TWI_H_ */