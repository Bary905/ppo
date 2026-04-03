#ifndef LED_H
#define LED_H

class Led {

	public:
		void StepRight(void);
		void StepLeft(void);
		void Init(void);
	
	private:
		void Step(enum Step);
		void On(unsigned char);
		unsigned char ucLedCtr;
};

#endif
