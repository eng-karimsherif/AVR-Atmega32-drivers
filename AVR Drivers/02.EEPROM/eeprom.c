/*
 * eeprom.c
 *
 * Created: 19/07/2020 09:52:05
 *  Author: karim sherif
 */ 

#include "std_macros.h"
#include "eeprom.h"

void eeprom_write (uint16_t adress , uint8_t data){
	while (READBIT(EECR,EEWE)==1){}
		EEAR=adress;
		EEDR=data;
		SETBIT(EECR,EEMWE);
		SETBIT(EECR,EEWE);
	}
	
uint8_t eeprom_read (uint16_t adress){
    while (READBIT(EECR,EEWE)==1){}
        EEAR=adress;
        SETBIT(EECR,EERE);
		
		return EEDR;
}	
