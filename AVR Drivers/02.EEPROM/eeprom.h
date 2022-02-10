/*
 * IncFile1.h
 *
 * Created: 19/07/2020 09:51:36
 *  Author: karim sherif
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include"std_macros.h"

void eeprom_write (uint16_t , uint8_t);
uint8_t eeprom_read (uint16_t);



#endif /* EEPROM_H_ */