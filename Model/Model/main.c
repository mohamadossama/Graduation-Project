/*
 * Model.c
 *
 * Created: 15-Nov-17 8:07:51 PM
 * Author : Mohamad Ossama
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define  F_CPU 1000000UL
int main(void)
{
    /* Replace with your application code */
	 //Initialize the stepper library
	 StepperInit();
		//stepAngle(20);

	 
    while (1) 
    {
		myStep();
		_delay_ms(1000);
	}
}

