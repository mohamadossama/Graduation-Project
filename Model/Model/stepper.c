
/*
 * stepper.c
 *
 * Created: 15-Nov-17 8:16:47 PM
 *  Author: mossa
 */ 
#include <avr/io.h>

#include "stepper.h"
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
