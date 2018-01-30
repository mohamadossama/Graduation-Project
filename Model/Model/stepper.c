
/*
 * stepper.c
 *
 * Created: 15-Nov-17 8:16:47 PM
 *  Author: mossa
 */ 
#include <avr/io.h>

#include "stepper.h"

uint8_t fPort; /* boolean to indicate weather in first four pins or last*/
motor:: setPort(char p, uint8_t first)
{
	fPort = first;
	if (first==1)
	{
		DDR(p)|=0x0F; /* set first 4 pins of port p as output*/
		PORT(p) &= 0xF0; /* clear first four bits in port p*/
	}
	else
	{
		DDR(p)|=0xF0; /* set last 4 pins of port p as output*/
		PORT(p) &= 0x0F; /* clear last four bits in port p*/
	}
	
}
motor:: rotateCW()
{
	// move the motor to the next step
	if (fPort==1)
	{
		PORT(p) = (motor_steps[count] & 0x0F) | (PORT(p) & 0xF0);
		count++;
		if(count == 8)
		{
			//start from the beginning after finish the full motor rotation.
			count = 0;
		}
	}
	else
	{
		PORT(p) = (motor_steps[count] & 0xF0) | (PORT(p) & 0x0F);
		count++;
		if(count == 8)
		{
			//start from the beginning after finish the full motor rotation.
			count = 0;
		}
	}
}
motor:: rotateACW()
{
	// move the motor to the next step
	if (fPort)
	{
		PORT(p) = (motor_steps[count] & 0x0F) | (PORT(p) & 0xF0);
		count--;
		if(count == -1)
		{
			//start from the beginning after finish the full motor rotation.
			count = 7;
		}
	}
	else
	{
		PORT(p) = (motor_steps[count] & 0xF0) | (PORT(p) & 0x0F);
		count--;
		if(count == -1)
		{
			//start from the beginning after finish the full motor rotation.
			count = 7;
		}
	}
}




/*
 uint8_t steps[4]={12,6,3,9};
	 uint8_t i = 0;
	void myStep(){
		__STEPPER_PORT=steps[i];
		i++;
		if(i==4){i=0;}
		
	}
	void stepAngle(uint8_t angle){
		for (uint8_t c=0;c<angle;c++){
			myStep();
		}
	}
void StepperInit()
{
	__STEPPER_DDR|=(0X0F<<STEPPER_POS);
	__STEPPER_PORT|=(1<<STEPPER_POS);
}
void StepperStepCCW()
{
	uint8_t temp=(__STEPPER_PORT & (0x0F<<STEPPER_POS));
	temp=temp>>(STEPPER_POS);
	temp=temp<<1;

	if(temp>(8))
	temp=1;
	
	__STEPPER_PORT=(__STEPPER_PORT & ~(0x0F<<STEPPER_POS))|(temp<<STEPPER_POS);
}

void StepperStepCW()
{
	uint8_t temp=(__STEPPER_PORT & (0x0F<<STEPPER_POS));
	temp=temp>>(STEPPER_POS);
	temp=temp>>1;

	if(temp==0)
	temp=8;
	
	__STEPPER_PORT=(__STEPPER_PORT & ~(0x0F<<STEPPER_POS))|(temp<<STEPPER_POS);
}
*/