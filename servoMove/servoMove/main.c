/*
 * servoMove.c
 *
 * Created: 29-Nov-17 5:52:00 PM
 * Author : mossa
 */ 
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL
void Timer1_Fast_PWM_Init(unsigned short duty_cycle)
{
	TCNT1 = 0;		/* Set timer1 initial count to zero */
	ICR1 = 2499;	/* Set TOP count for timer1 in ICR1 register */

	OCR1A = duty_cycle; /* Set the compare value */
	OCR1B = duty_cycle; /* Set the compare value */
	
	
	TCCR1A = (1<<WGM11) | (1<<COM1A1) ; /*PRESCALER=64 MODE 14(FAST PWM)*/

	/* Configure timer control register TCCR1A
	 * 1. Fast Pwm Mode with the TOP in ICR1 WGM12=01 WGM13=1
	 * 2. Prescaler = F_CPU/64
     */
	//TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS10) | (1<<CS11);
}
	


int main(void)
{
	DDRD |= (1<<PD5);	
	
    while (1) 
    {
		Timer1_Fast_PWM_Init(97);	/* Set Servo shaft at 0° position by 0.388 ms pulse */
		_delay_ms(10000);
		Timer1_Fast_PWM_Init(316);	/* Set Servo shaft at 90° position by 1.264 ms pulse */
		_delay_ms(10000);
		Timer1_Fast_PWM_Init(535);	/* Set Servo shaft at 180° position by 2.14 ms pulse */
		_delay_ms(10000);
				
    }
}