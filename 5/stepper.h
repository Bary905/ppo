#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper : private Led
{
	public:
			void StepRight(void);
			void StepLeft(void);
	
	private:
			unsigned char ucLedCtr;
      void Step(enum Step);
};

#endif