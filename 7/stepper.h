#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper
{
	public:
			Stepper (unsigned char = 0);
			void StepRight(void);
			void StepLeft(void);
	
	private:
			unsigned char ucLedCtr;
      void Step(enum Step);
			Led MyLed;
};

#endif