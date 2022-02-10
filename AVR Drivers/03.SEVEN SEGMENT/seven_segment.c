/*
 * seven_segment.c
 *
 * Created: 21/07/2020 00:54:04
 *  Author: karim sherif
 */ 

#include "seven_segment.h"

void init_7_seg (void){
	INIT_7SEG;
	_delay_ms(20);
}

void write_7_seg (uint8_t num){
	uint8_t digit_1 = num/10;
	uint8_t digit_2 = num%10;
	
   
	EN2(1);
	EN1(0);
	write_digit (digit_1);                              
	_delay_ms(1);
	

	EN1(1);
	EN2(0);
    write_digit (digit_2);
	_delay_ms(1);
	
	
}


/*      A   B   C   D   E   F   G
------------------------------------------
   0  |1  |1  |1  |1  |1  |1  |0  |
   1  |0  |1  |1  |0  |0  |0  |0  |
   2  |1  |1  |0  |1  |1  |0  |1  |
   3  |1  |1  |1  |1  |0  |0  |1  |
   4  |0  |1  |1  |0  |0  |1  |1  |
   5  |1  |0  |1  |1  |0  |1  |1  |
   6  |1  |0  |1  |1  |1  |1  |1  |
   7  |1  |1  |1  |0  |0  |0  |0  |
   8  |1  |1  |1  |1  |1  |1  |1  |
   9  |1  |1  |1  |1  |0  |1  |1  |
   
   */

void write_digit (uint8_t digit){
	switch(digit){
		
		case 0: A(1); B(1); C(1); D(1); E(1); F(1); G(0); break;
		case 1: A(0); B(1); C(1); D(0); E(0); F(0); G(0); break;
		case 2: A(1); B(1); C(0); D(1); E(1); F(0); G(1); break;
		case 3: A(1); B(1); C(1); D(1); E(0); F(0); G(1); break;
		case 4: A(0); B(1); C(1); D(0); E(0); F(1); G(1); break;
		case 5: A(1); B(0); C(1); D(1); E(0); F(1); G(1); break;
		case 6: A(1); B(0); C(1); D(1); E(1); F(1); G(1); break;
		case 7: A(1); B(1); C(1); D(0); E(0); F(0); G(0); break;
		case 8: A(1); B(1); C(1); D(1); E(1); F(1); G(1); break;
		case 9: A(1); B(1); C(1); D(1); E(0); F(1); G(1); 
	}
	
}