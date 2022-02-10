/*
 * timer.h
 *
 * Created: 26/07/2020 09:26:08
 *  Author: karim sherif
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "std_macros.h"

void timer0_normal_init();
void timer0_normal_prescaler_init(uint16_t);

void timer0_comp_init();
void timer0_comp_prescaler_init(uint16_t);

void timer0_freq_init();
void set_freq (uint8_t);

void timer0_fastpwm_noninverting_init();
void timer0_fastpwm_noninverting_duty(uint8_t);

void timer0_fastpwm_inverting_init();
void timer0_fastpwm_inverting_duty(uint8_t);

void timer0_phase_correct_pwm_noninverting_init();
void timer0_Phase_correct_pwm_noninverting_duty(uint8_t);

void timer0_phase_correct_pwm_inverting_init();
void timer0_phase_correct_pwm_inverting_duty(uint8_t);

#endif /* TIMER_H_ */