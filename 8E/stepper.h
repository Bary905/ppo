#ifndef STEPPER_H
#define STEPPER_H

class Led;

class Stepper {

	public:
		void StepRight(void);
		void StepLeft(void);
		void SetLed(Led* pLedWrite);
	
	private:
		void Step(enum Step);
		unsigned char ucLedCtr;
		Led* pLed;
};

#endif
