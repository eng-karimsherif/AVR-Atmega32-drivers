/*
 * LCD.c
 *
 * Created: 7/16/2020 7:53:46 PM
 *  Author: karim sherif
 */ 
#include "LCD.h"



void lcd_init(void){
	INIT_LCD_PORT;
	lcd_write_command(0x3);
	lcd_write_command(0x2);
	lcd_write_command(0x28);
	lcd_write_command(0x8);
	lcd_write_command(0x1);
	lcd_write_command(0x6);
	lcd_write_command(0xc);
	_delay_ms(20);	
}


void lcd_write_command(uint8_t cmd){
	
	RS(0);
	D4(   READBIT(cmd,4)     );
	D5(   READBIT(cmd,5)     );
	D6(   READBIT(cmd,6)     );
	D7(   READBIT(cmd,7)    );
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
	D4(   READBIT(cmd,0)     );
	D5(   READBIT(cmd,1)     );
	D6(   READBIT(cmd,2)     );
	D7(   READBIT(cmd,3)    );
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}

void lcd_write_char(uint8_t data){
	RS(1);
	D4(   READBIT(data,4)     );
	D5(   READBIT(data,5)     );
	D6(   READBIT(data,6)     );
	D7(   READBIT(data,7)    );
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
	D4(   READBIT(data,0)     );
	D5(   READBIT(data,1)     );
	D6(   READBIT(data,2)     );
	D7(   READBIT(data,3)    );
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
}

void lcd_write_string(uint8_t txt[]){
	for(uint8_t i = 0; txt[i] != '\0'; i++){
		lcd_write_char(txt[i]);
	}
}


/*
1234 %10 --> 4
1234 / 10 = 123

123%10 --> 3
123/10 = 12

12%10 --> 2
12/10 = 1

1%10 --> 1
1/10 = 0




1 2 3 4
1+48
2+48
3+48
4+48

*/
void lcd_write_num(uint32_t num){
	uint8_t txt[10] = {0};
	int8_t i = 0;
	if(num == 0) {
		lcd_write_char('0');
		return;
	}		
	for (i = 0; num != 0; i++ )
	{
		txt[i] = num%10 + 48;
		num = num  / 10 ;
	}
	i--;
	while(i >= 0){
		lcd_write_char(txt[i]);
		i--;
	}
}