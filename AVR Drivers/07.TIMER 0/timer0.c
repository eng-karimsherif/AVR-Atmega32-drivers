/*
 * timer.c
 *
 * Created: 26/07/2020 09:26:21
 *  Author: karim sherif
 */ 

#include "timer0.h"

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
/*
init normal mode
c.c of cpu direct (no prescaler)
enable overflow interrupt
enable global interrupt
*/

void timer0_normal_init(){
       // TCCR0 |= 1<<FOC0 | 1<<CS00;
       SETBIT(TCCR0,FOC0);  //non pwm mode
	   SETBIT(TCCR0,CS00);  // no prescaler mode
	   SETBIT(TIMSK,TOIE0); // TIMSK |= 1<<TOIE0 ; //enable overflow interrupt
	   SETBIT(SREG,7);      //sei(); // enable global interrupt
}
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
init normal mode
c.c of timer =(1024/256/64/8) *c.c of cpu  (prescaler)
enable overflow interrupt
enable global interrupt
*/

void timer0_normal_prescaler_init(uint16_t factor){
		// TCCR0 |= 1<<FOC0  ;
		SETBIT(TCCR0,FOC0);  //non pwm mode
		switch(factor){
		     case 1024: SETBIT(TCCR0,CS00); CLRBIT(TCCR0,CS01); SETBIT(TCCR0,CS02);break; //1024 prescaler mode
		     case 256: CLRBIT(TCCR0,CS00); CLRBIT(TCCR0,CS01); SETBIT(TCCR0,CS02);break; //256 prescaler mode
		     case 64: SETBIT(TCCR0,CS00); SETBIT(TCCR0,CS01); CLRBIT(TCCR0,CS02);break; //64 prescaler mode
		     case 8: CLRBIT(TCCR0,CS00); SETBIT(TCCR0,CS01); CLRBIT(TCCR0,CS02);break; //8 prescaler mode
		     }		
		SETBIT(TIMSK,TOIE0); // TIMSK |= 1<<TOIE0 ; //enable overflow interrupt
		SETBIT(SREG,7);      //sei(); // enable global interrupt
}
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
init clear in compare match (CTC) mode
c.c of cpu direct  (no prescaler)
enable compare match interrupt
enable global interrupt
*/

void timer0_comp_init(){
		// TCCR0 |= 1<<FOC0 | 1<<CS00 | 1<<WGM01;
		SETBIT(TCCR0,FOC0);  //non pwm mode
		CLRBIT(TCCR0,WGM00); SETBIT(TCCR0,WGM01); //enable CTC mode
		SETBIT(TCCR0,CS00);  // no prescaler mode
		OCR0 =200;
		SETBIT(TIMSK,OCIE0); // TIMSK |= 1<<TOIE0 ; //enable CTC interrupt
		SETBIT(SREG,7);      //sei(); // enable global interrupt
}
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
init clear in compare match (CTC) mode
c.c of timer =(1024/256/64/8) *c.c of cpu  (prescaler)
enable compare match interrupt
enable global interrupt
*/

void timer0_comp_prescaler_init(uint16_t factor){
		// TCCR0 |= 1<<FOC0 | 1<<WGM01;
		SETBIT(TCCR0,FOC0);  //non pwm mode
		CLRBIT(TCCR0,WGM00); SETBIT(TCCR0,WGM01); //enable CTC mode
		switch(factor){
			case 1024: SETBIT(TCCR0,CS00); CLRBIT(TCCR0,CS01); SETBIT(TCCR0,CS02);break; //1024 prescaler mode
			case 256: CLRBIT(TCCR0,CS00); CLRBIT(TCCR0,CS01); SETBIT(TCCR0,CS02);break; //256 prescaler mode
			case 64: SETBIT(TCCR0,CS00); SETBIT(TCCR0,CS01); CLRBIT(TCCR0,CS02);break; //64 prescaler mode
			case 8: CLRBIT(TCCR0,CS00); SETBIT(TCCR0,CS01); CLRBIT(TCCR0,CS02);break; //8 prescaler mode
			}
		OCR0=200;
		SETBIT(TIMSK,OCIE0); // TIMSK |= 1<<TOIE0 ; //enable CTC interrupt
		SETBIT(SREG,7);      //sei(); // enable global interrupt
	
}
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
init  (CTC) mode
enable frequancy generator on OC0 pin on microcontroller
no interrupt request needed
set compare value
*/
void timer0_freq_init(){
		// TCCR0 |= 1<<FOC0 | 1<<CS00 | 1<<WGM01 | 1<<COM00;
		SETBIT(TCCR0,FOC0);  //non pwm mode
		CLRBIT(TCCR0,WGM00); SETBIT(TCCR0,WGM01); //enable CTC mode
		SETBIT(TCCR0,CS00);  // no prescaler mode
		SETBIT(TCCR0,COM00); // enable OC0 toggle
		SETBIT(DDRB,3); // set OC0 pin as output
}

void set_freq (uint8_t x){
	OCR0=x;
}
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
fast freq PWM
non inverting
8 bit counter
no interrupt request needed
must don,t have prescaler
*/

void timer0_fastpwm_noninverting_init(){
	CLRBIT(TCCR0,FOC0);  //pwm mode
	SETBIT(TCCR0,CS00); // no prescaler mode
	SETBIT(TCCR0,WGM00); SETBIT(TCCR0,WGM01); // enable fast PWM mode
	CLRBIT(TCCR0,COM00); SETBIT(TCCR0,COM01); // non inverting mode
	SETBIT(DDRB,3); // set OC0 pin as output
}

void timer0_fastpwm_noninverting_duty(uint8_t duty_cycle){
	OCR0 = duty_cycle*2.55;
}

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
fast freq PWM
inverting
8 bit counter
no interrupt request needed
must don,t have prescaler
*/

void timer0_fastpwm_inverting_init(){
	CLRBIT(TCCR0,FOC0);  //pwm mode
	SETBIT(TCCR0,CS00); // no prescaler mode
	SETBIT(TCCR0,WGM00); SETBIT(TCCR0,WGM01); // enable fast PWM mode
	SETBIT(TCCR0,COM00); SETBIT(TCCR0,COM01); // inverting mode
	SETBIT(DDRB,3); // set OC0 pin as output
}

void timer0_fastpwm_inverting_duty(uint8_t duty_cycle){
	OCR0 = 255-(duty_cycle*2.55);
}

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
phase correct PWM
non inverting
8 bit counter
no interrupt request needed
must don,t have prescaler
*/

void timer0_phase_correct_pwm_noninverting_init(){
	CLRBIT(TCCR0,FOC0);  //pwm mode
	SETBIT(TCCR0,CS00); // no prescaler mode
	SETBIT(TCCR0,WGM00); CLRBIT(TCCR0,WGM01); // enable phase correct PWM mode
	CLRBIT(TCCR0,COM00); SETBIT(TCCR0,COM01); // non inverting mode
	SETBIT(DDRB,3); // set OC0 pin as output
}

void timer0_Phase_correct_pwm_noninverting_duty(uint8_t duty_cycle){
	OCR0 = duty_cycle*2.55;
}

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
phase correct freq PWM
inverting
8 bit counter
no interrupt request needed
must don,t have prescaler
*/

void timer0_phase_correct_pwm_inverting_init(){
	CLRBIT(TCCR0,FOC0);  //pwm mode
	SETBIT(TCCR0,CS00); // no prescaler mode
	SETBIT(TCCR0,WGM00); CLRBIT(TCCR0,WGM01); // enable phase correct PWM mode
	SETBIT(TCCR0,COM00); SETBIT(TCCR0,COM01); // inverting mode
	SETBIT(DDRB,3); // set OC0 pin as output
}

void timer0_phase_correct_pwm_inverting_duty(uint8_t duty_cycle){
	OCR0 = 255-(duty_cycle*2.55);
}

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------