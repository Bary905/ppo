#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper {

	public:
		Stepper (unsigned char = 0);
		void StepRight(void);
		void StepLeft(void);
	
	private:
		void Step(enum Step);
		unsigned char ucLedCtr;
		Led MyLed;
};

#endif
