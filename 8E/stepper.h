#ifndef STEPPER_H
#define STEPPER_H

class Led;

class Stepper
{
	public:
			void StepRight(void);
			void StepLeft(void);
			void SetLed(Led*);
	
	private:
			unsigned char ucLedCtr;
      void Step(enum Step);
			Led* pLed;
};

#endif