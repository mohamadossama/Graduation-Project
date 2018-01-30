
/*
 * stepper.h
 *
 * Created: 15-Nov-17 8:17:01 PM
 *  Author: mossa
 */ 
#ifndef STEEPER_H
#define STEEPER_H

/*
Configuration area
*/

/*
Port where stepper is connected
*/
#define STEPPER_PORT 	C



/*
Position where 1st coil is connected.
All other coils like 2nd,3rd and 4th
must be connected in sequence after the 1st.

For this configuration the connection is
like:-

PC0 -> Coil 1
PC1 -> Coil 2
PC2 -> Coil 3
PC3 -> Coil 4

Don't connect port pins directly to coil,
use a driver like ULN2003A etc.

*/
/*
#define STEPPER_POS		0
#define _CONCAT(a,b) a##b
#define PORT(x) _CONCAT(PORT,x)
#define PIN(x) _CONCAT(PIN,x)
#define DDR(x) _CONCAT(DDR,x)

#define __STEPPER_PORT 	PORT(STEPPER_PORT)
#define __STEPPER_DDR	DDR(STEPPER_PORT)

void StepperInit();
void StepperStepCW();
void StepperStepCCW();
void myStep();
void stepAngle(uint8_t angle);*/
#define _CONCAT(a,b) a##b
#define PORT(x) _CONCAT(PORT,x)
#define PIN(x) _CONCAT(PIN,x)
#define DDR(x) _CONCAT(DDR,x)
#define true 1
struct motor 
{
	
		
	public:
		const unsigned uint8_t motor_steps[HALF_WAVE_STEPS] = {8,12,4,6,2,3,1,9};
		unsigned char count = 0;
		void setPort(char p,bool first); /* initiates output pins for the motor if first = true then first 4 pins else last 4 pins*/
		void rotateCW(); /*rotates the motor 1 step in clockwise direction*/
		void rotateACW(); /* rotates motor 1 step in anti clockwise direction */
		
};
#endif


