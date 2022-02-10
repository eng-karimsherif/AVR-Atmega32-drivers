/*
 * keypad.c
 *
 * Created: 21/07/2020 05:46:57
 *  Author: karim sherif
 */ 

#include "keypad.h"

const uint8_t txt[]={'1','2','3','/',
                     '4','5','6','X',
					 '7','8','9','-',
					 'o','0','=','+'};

void keypad_init(){
	INIT_KEYPAD;
}

uint8_t keypad_read(){
	
	while(1){
	
	PORTB=0b11100000;
	uint8_t flag;
	flag=0;
	while (READBIT(PIND,2)==0) {flag=1;}
	while (READBIT(PIND,3)==0) {flag=2;}
	while (READBIT(PIND,4)==0) {flag=3;}
	while (READBIT(PIND,5)==0) {flag=4;}
	
	if(flag==1) {return txt[0];}
	if(flag==2) {return txt[1];}
	if(flag==3) {return txt[2];}
	if(flag==4) {return txt[3];}
	
	PORTB=0b11010000;
	flag=0;
    while (READBIT(PIND,2)==0) {flag=1;}
	while (READBIT(PIND,3)==0) {flag=2;}
	while (READBIT(PIND,4)==0) {flag=3;}
	while (READBIT(PIND,5)==0) {flag=4;}
	if(flag==1) {return txt[4];}
    if(flag==2) {return txt[5];}
	if(flag==3) {return txt[6];}
	if(flag==4) {return txt[7];}
	
	PORTB=0b10110000;
	flag=0;
    while (READBIT(PIND,2)==0) {flag=1;}
	while (READBIT(PIND,3)==0) {flag=2;}
	while (READBIT(PIND,4)==0) {flag=3;}
	while (READBIT(PIND,5)==0) {flag=4;}
	if(flag==1) {return txt[8];}
    if(flag==2) {return txt[9];}
	if(flag==3) {return txt[10];}
	if(flag==4) {return txt[11];}
	
	PORTB=0b01110000;
	flag=0;
    while (READBIT(PIND,2)==0) {flag=1;}
	while (READBIT(PIND,3)==0) {flag=2;}
	while (READBIT(PIND,4)==0) {flag=3;}
	while (READBIT(PIND,5)==0) {flag=4;}
	if(flag==1) {return txt[12];}
    if(flag==2) {return txt[13];}
	if(flag==3) {return txt[14];}
	if(flag==4) {return txt[15];}
	
	}	
	
}
