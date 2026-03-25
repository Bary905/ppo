#ifndef STEPPER_H
#define STEPPER_H

class Stepper
{
	public:
			void StepRight(void);
			void StepLeft(void);
	
	private:
			unsigned char ucLedCtr;
      void Step(enum Step);
};

#endif