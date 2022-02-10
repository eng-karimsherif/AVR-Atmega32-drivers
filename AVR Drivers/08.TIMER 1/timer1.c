/*
 * timer.c
 *
 * Created: 26/07/2020 09:26:21
 *  Author: karim sherif
 */ 

#include "timer1.h"

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
/*
init normal mode
c.c of cpu direct (no prescaler)
enable overflow interrupt
enable global interrupt
*/

void timer1_normal_init(){
       // TCCR1A |= 1<<FOC1A |1<<FOC1B ;
	   // TCCR1B |= 1>>CS10
       SETBIT(TCCR1A,FOC1A);  //non pwm mode for module A
	   SETBIT(TCCR1A,FOC1B);  //non pwm mode for module B
	   SETBIT(TCCR1B,CS10);  // no prescaler mode
	   SETBIT(TIMSK,TOIE1); // TIMSK |= 1<<TOIE0 ; //enable overflow interrupt
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

void timer1_normal_prescaler_init(uint16_t factor){
		// TCCR1A |= 1<<FOC1A |1<<FOC1B ;
	    SETBIT(TCCR1A,FOC1A);  //non pwm mode for module A
	    SETBIT(TCCR1A,FOC1B);  //non pwm mode for module B
		switch(factor){
		     case 1024: SETBIT(TCCR1B,CS10); CLRBIT(TCCR1B,CS11); SETBIT(TCCR1B,CS12);break; //1024 prescaler mode
		     case 256: CLRBIT(TCCR1B,CS10); CLRBIT(TCCR1B,CS11); SETBIT(TCCR1B,CS12);break; //256 prescaler mode
		     case 64: SETBIT(TCCR1B,CS10); SETBIT(TCCR1B,CS11); CLRBIT(TCCR1B,CS12);break; //64 prescaler mode
		     case 8: CLRBIT(TCCR1B,CS10); SETBIT(TCCR1B,CS11); CLRBIT(TCCR1B,CS12);break; //8 prescaler mode
		     }		
		SETBIT(TIMSK,TOIE1); // TIMSK |= 1<<TOIE1 ; //enable overflow interrupt
		SETBIT(SREG,7);      //sei(); // enable global interrupt
}
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
init clear in compare match (CTC) mode in module A
c.c of cpu direct  (no prescaler)
enable compare match interrupt for module A in timer 1
enable global interrupt
*/

void timer1_moduleA_comp_init(){
		// TCCR1A |= 1<<FOC1A | 1<<FOC1B ;
		// TCCR1B |= 1<<WGM12 | 1<<CC10;
		SETBIT(TCCR1A,FOC1A);  //non pwm mode for module A
		SETBIT(TCCR1A,FOC1B);  //non pwm mode for module B
		SETBIT(TCCR1B,WGM12);  //enable CTC mode
		SETBIT(TCCR0,CS10);  // no prescaler mode
		OCR1A =200;
		SETBIT(TIMSK,OCIE1A); // TIMSK |= 1<<OCIE1A ; //enable CTC interrupt for module A
		SETBIT(SREG,7);      //sei(); // enable global interrupt
}
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------


/*
init clear in compare match (CTC) mode in module A
c.c of timer =(1024/256/64/8) *c.c of cpu  (prescaler)
enable compare match interrupt
enable global interrupt
*/

void timer1_comp_moduleA_prescaler_init(uint16_t factor){
		// TCCR1A |= 1<<FOC1A | 1<<FOC1B;
		// TCCR1B |= 1>>WGM12;
		SETBIT(TCCR1A,FOC1A);  //non pwm mode for module A
		SETBIT(TCCR1A,FOC1B);  //non pwm mode for module B
		SETBIT(TCCR1B,WGM12); //enable CTC mode
		switch(factor){
			case 1024: SETBIT(TCCR1B,CS10); CLRBIT(TCCR1B,CS11); SETBIT(TCCR1B,CS12);break; //1024 prescaler mode
			case 256: CLRBIT(TCCR1B,CS10); CLRBIT(TCCR1B,CS11); SETBIT(TCCR1B,CS12);break; //256 prescaler mode
			case 64: SETBIT(TCCR1B,CS10); SETBIT(TCCR1B,CS11); CLRBIT(TCCR1B,CS12);break; //64 prescaler mode
			case 8: CLRBIT(TCCR1B,CS10); SETBIT(TCCR1B,CS11); CLRBIT(TCCR1B,CS12);break; //8 prescaler mode
			}
		OCR1A=200;
		SETBIT(TIMSK,OCIE1A); // TIMSK |= 1<<OCIE1A ; //enable CTC interrupt
		SETBIT(SREG,7);      //sei(); // enable global interrupt
	
}
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
init  (CTC) mode in module A
enable frequancy generator on OC0 pin on microcontroller
no interrupt request needed
set compare value
*/
void timer1_freq_init(){
		// TCCR1A |= 1<<FOC1A | 1<<F0C1B  | 1<<COM1A0;
		// TCCR1B |= 1<<WGM12 | 1<<CS10;
		SETBIT(TCCR1A,FOC1A);  //non pwm mode in module 1
		SETBIT(TCCR1A,FOC1B);  //non pwm mode in module 1
		SETBIT(TCCR1B,WGM12); //enable CTC mode
		SETBIT(TCCR1B,CS10);  // no prescaler mode
		SETBIT(TCCR1A,COM1A0); // enable OC1A toggle
		SETBIT(DDRD,5); // set OC1A pin as output
}

void set_freq (uint16_t x){
	OCR1A=x;
}
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
fast freq PWM for module A
non inverting
10 bit counter
no interrupt request needed
must don,t have prescaler
*/

void timer1_moduleA_fastpwm_noninverting_init(){
	CLRBIT(TCCR1A,FOC1A);  //pwm mode for module A
	SETBIT(TCCR1B,CS10); // no prescaler mode
	SETBIT(TCCR1A,WGM10); SETBIT(TCCR1A,WGM11); SETBIT(TCCR1B,WGM12); CLRBIT(TCCR1B,WGM13); // enable fast PWM mode (10 bit)
	CLRBIT(TCCR1A,COM1A0); SETBIT(TCCR1A,COM1A1); // non inverting mode
	SETBIT(DDRD,5); // set OC1A pin as output
}

void timer1_moduleA_fastpwm_noninverting_duty(uint8_t duty_cycle){
	OCR1A = duty_cycle*10.23;
}

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
fast freq PWM for module A
inverting
10 bit counter
no interrupt request needed
must don,t have prescaler
*/

void timer1_moduleA_fastpwm_inverting_init(){
      CLRBIT(TCCR1A,FOC1A);  //pwm mode for module A
      SETBIT(TCCR1B,CS10); // no prescaler mode
      SETBIT(TCCR1A,WGM10); SETBIT(TCCR1A,WGM11); SETBIT(TCCR1B,WGM12); CLRBIT(TCCR1B,WGM13); // enable fast PWM mode (10 bit)
      SETBIT(TCCR1A,COM1A0); SETBIT(TCCR1A,COM1A1); // inverting mode
      SETBIT(DDRD,5); // set OC1A pin as output
}

void timer1_moduleA_fastpwm_inverting_duty(uint8_t duty_cycle){
	 OCR1A = 1023-(duty_cycle*10.23);
}

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
phase correct PWM for module 1
non inverting
10 bit counter
no interrupt request needed
must don,t have prescaler
*/

void timer1_moduleA_phase_correct_pwm_noninverting_init(){
	CLRBIT(TCCR1A,FOC1A);  //pwm mode for module A
	SETBIT(TCCR1B,CS10); // no prescaler mode
	SETBIT(TCCR1A,WGM10); SETBIT(TCCR1A,WGM11); CLRBIT(TCCR1B,WGM12); CLRBIT(TCCR1B,WGM13); // enable phase correct PWM mode (10 bit)
	CLRBIT(TCCR1A,COM1A0); SETBIT(TCCR1A,COM1A1); // non inverting mode
	SETBIT(DDRD,5); // set OC1A pin as output
}

void timer1_moduleA_Phase_correct_pwm_noninverting_duty(uint8_t duty_cycle){
	OCR1A = duty_cycle*10.23;
}

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/*
phase correct freq PWM for module A
inverting
10 bit counter
no interrupt request needed
must don,t have prescaler
*/

void timer1_moduleA_phase_correct_pwm_inverting_init(){
	CLRBIT(TCCR1A,FOC1A);  //pwm mode for module A
	SETBIT(TCCR1B,CS10); // no prescaler mode
	SETBIT(TCCR1A,WGM10); SETBIT(TCCR1A,WGM11); CLRBIT(TCCR1B,WGM12); CLRBIT(TCCR1B,WGM13); // enable phase correct PWM mode (10 bit)
    SETBIT(TCCR1A,COM1A0); SETBIT(TCCR1A,COM1A1); // inverting mode
	SETBIT(DDRD,5); // set OC1A pin as output
}

void timer1_moduleA_phase_correct_pwm_inverting_duty(uint8_t duty_cycle){
	OCR1A = 1023-(duty_cycle*10.23);
}

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------

/* enable timer 1 input capture mode
   using polling method
   no prscaler 
   trigger at rising edge */

uint16_t timer1_input_capture_mode_rising_edge(){
	TCCR1A=0x00;
	SETBIT(TIFR,ICF1);  // clear input capture by write logic 1 in it
	/*SETBIT(TCCR1B,CS10); // no prescaler mode
	SETBIT(TCCR1B,ICES1); // trigger the capture at rising edge*/
	TCCR1B=0x41;
	while (READBIT(TIFR,ICF1)==0){}
	return ICR1;
	}	
	
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
   
   
/* enable timer 1 input capture mode
   using polling method
   no prscaler 
   trigger at falling edge */

uint16_t timer1_input_capture_mode_falling_edge(){
	TCCR1A=0x00;
	SETBIT(TIFR,ICF1);  // clear input capture by write logic 1 in it
	/*SETBIT(TCCR1B,CS10); // no prescaler mode
	CLRBIT(TCCR1B,ICES1); // trigger the capture at falling edge*/
	TCCR1B=0x01;
	while (READBIT(TIFR,ICF1)==0){}
	return ICR1;
	}	
	
//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
   