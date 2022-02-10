/*
 * std_macros.h
 *
 * Created: 19/07/2020 02:52:25
 *  Author: karim sherif
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#include <avr/io.h>
#define F_CPU 16000000ul
#include <util/delay.h>
#include <avr/interrupt.h>

#define SETBIT(REG,BIT) (REG |=1<<BIT)
#define CLRBIT(REG,BIT) (REG &=~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^=1<<BIT)
#define READBIT(REG,BIT) ((REG>>BIT) & 1)

#endif /* STD_MACROS_H_ */