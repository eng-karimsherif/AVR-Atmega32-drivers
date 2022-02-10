/*
 * adc.c
 *
 * Created: 23/07/2020 17:42:29
 *  Author: karim sherif
 */ 

#include "adc.h"
uint16_t adc_data;

void ADC_init(){
	SETBIT(ADCSRA,ADEN); // to enable the ADC
	// internal vcc
	SETBIT(ADMUX,REFS0); 
	CLRBIT(ADMUX,REFS1);
	ADCSRA |=0b00001111;
	SETBIT(SREG,7);
}

void ADC_read(uint8_t ch){
	ADMUX = ADMUX & 0b11100000;
	ADMUX |=ch; // update channel
	SETBIT(ADCSRA,ADSC); // start conversion
	CLRBIT(ADCSRA,ADATE); // enable one shot mode
	//while (READBIT(ADCSRA,ADSC)==1){}
		//return ADC;
	
}

ISR(ADC_vect){
	adc_data=ADC;
}