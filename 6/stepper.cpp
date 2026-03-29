#include "stepper.h"

enum Step{LEFT,RIGHT};


Stepper::Stepper(unsigned char ucLedDef)
{
	ucLedCtr=ucLedDef;
	On(ucLedCtr);
}

void Stepper::Step(enum Step eStep){
	if(eStep == LEFT){
		ucLedCtr--;
	}
	else if(eStep == RIGHT){
		ucLedCtr++;
		
	}else{
	}
		ucLedCtr = ucLedCtr % 4;
		On(ucLedCtr);
}

void Stepper::StepLeft(void){
	Step(LEFT);
}

void Stepper::StepRight(void){
	Step(RIGHT);
}
