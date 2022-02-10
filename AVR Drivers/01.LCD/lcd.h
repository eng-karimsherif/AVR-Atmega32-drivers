/*
 * LCD.h
 *
 * Created: 7/16/2020 7:54:02 PM
 *  Author: karim sherif
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "std_macros.h"
/*
Rs --> PB2
EN --> PB3

D4 --> PB4
D5 --> PB5
D6 --> PB6
D7 --> PB7

*/
#define  INIT_LCD_PORT DDRB |= 0b11111100;

#define  EN(x)    if(x == 0) CLRBIT(PORTB,3); else SETBIT(PORTB,3);
#define  RS(x)    if(x == 0) CLRBIT(PORTB,2); else SETBIT(PORTB,2);
#define  D4(x)    if(x == 0) CLRBIT(PORTB,4); else SETBIT(PORTB,4);
#define  D5(x)    if(x == 0) CLRBIT(PORTB,5); else SETBIT(PORTB,5);
#define  D6(x)    if(x == 0) CLRBIT(PORTB,6); else SETBIT(PORTB,6);
#define  D7(x)    if(x == 0) CLRBIT(PORTB,7); else SETBIT(PORTB,7);


void lcd_init(void);
void lcd_write_command(uint8_t );
void lcd_write_char(uint8_t data);
void lcd_write_string(uint8_t* data);
void lcd_write_num(uint32_t num);

#endif /* LCD_H_ */