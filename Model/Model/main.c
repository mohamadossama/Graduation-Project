/*
 * Model.c
 *
 * Created: 15-Nov-17 8:07:51 PM
 * Author : Mohamad Ossama
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define  F_CPU 1000000UL
#include "stepper.h"
int main(void)
{
    /* Replace with your application code */
	 //Initialize the stepper library
	struct motor m1;
	 
	 m1.setPort('C',true);
	 
    while (1) 
    {
		m1.rotateCW();
		_delay_ms(500);
		m1.rotateCW();
		_delay_ms(500);
		m1.rotateACW();
		_delay_ms(500);
		m1.rotateACW();
		_delay_ms(500);
	}
}

