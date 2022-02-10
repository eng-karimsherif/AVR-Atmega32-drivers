/*
 * timer.h
 *
 * Created: 26/07/2020 09:26:08
 *  Author: karim sherif
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "std_macros.h"

void timer1_normal_init();
void timer1_normal_prescaler_init(uint16_t);

void timer1_moduleA_comp_init();
void timer1_comp_moduleA_prescaler_init(uint16_t);

void timer1_freq_init();
void set_freq (uint16_t);

void timer1_moduleA_fastpwm_noninverting_init();
void timer1_moduleA_fastpwm_noninverting_duty(uint8_t);

void timer1_moduleA_fastpwm_inverting_init();
void timer1_moduleA_fastpwm_inverting_duty(uint8_t);

void timer1_moduleA_phase_correct_pwm_noninverting_init();
void timer1_moduleA_Phase_correct_pwm_noninverting_duty(uint8_t);

void timer1_moduleA_phase_correct_pwm_inverting_init();
void timer1_moduleA_phase_correct_pwm_inverting_duty(uint8_t);

uint16_t timer1_input_capture_mode_rising_edge();
uint16_t timer1_input_capture_mode_falling_edge();

#endif /* TIMER_H_ */