/*
 * wdt.c
 *
 * Created: 04/08/2020 12:16:32
 *  Author: karim sherif
 */ 

#include "wdt.h"

void wdt_on(){
	WDTCR=(1<<WDE) | (1<<WDP2) | (1<<WDP1);
}




void wdt_off(){
	WDTCR = (1<<WDTOE) | (1<<WDE);
	
	WDTCR = 0x00;

}