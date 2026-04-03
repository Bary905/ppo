#ifndef STEPPER_H
#define STEPPER_H

#include "ledinv.h"

class Stepper {

	public:
		void StepRight(void);
		void StepLeft(void);
	
	private:
		void Step(enum Step);
		unsigned char ucLedCtr;
		Led MyLed;
		LedInv MyLedInv;
};

#endif
