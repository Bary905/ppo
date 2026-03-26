#ifndef STEPPER_H
#define STEPPER_H

#include "ledinv.h"

class Stepper
{
	public:
			void StepRight(void);
			void StepLeft(void);
	
	private:
			unsigned char ucLedCtr;
      void Step(enum Step);
			Led MyLed;
			LedInv MyLedInv;
};

#endif