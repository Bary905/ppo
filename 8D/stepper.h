#ifndef STEPPER_H
#define STEPPER_H

#include "ledinv.h"

class Stepper
{
	public:
			void StepRight(void);
			void StepLeft(void);
			void SetMode(unsigned char);
	
	private:
			unsigned char ucInversion;
			unsigned char ucLedCtr;
      void Step(enum Step);
			Led MyLed;
			LedInv MyLedInv;
};

#endif