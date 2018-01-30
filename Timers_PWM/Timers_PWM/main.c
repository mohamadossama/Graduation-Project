/*
 * Timers_PWM.c
 *
 * Created: 26-Nov-17 6:18:33 PM
 * Author : mossa
 */ 

#include <avr/io.h>
#include "common_macros.h"

#define F_CPU 1000000UL
uint8_t g_tick = 0;
ISR(TIMER0_OVF_vect){
	g_tick++;
	if (g_tick==2){
		g_tick = 0;
		TOGGLE_BIT(PORTD,4);
	}		
}
void timer0_init_normal_mode(void)
{
	TCNT0 = 0; //timer initial value
	TIMSK |= (1<<TOIE0); //enable overflow interrupt
	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0 
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
}

int main(void)
{
	/*intialization*/
	
	SET_BIT(PORTD,4); /*set PD4 as output pin*/
	CLEAR_BIT(PORTD,4); /*turn off PD4*/
	timer0_init_normal_mode();
    while (1) 
    {
    }
}

