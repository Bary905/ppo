#ifndef LEDBOARD_H
#define LEDBOARD_H

#include "Led.h"

class LedBoard
{
	public:
		LedBoard (unsigned char ucColumn);
		void Off();
		void On(unsigned char);
	private:
		Led *Leds[4];
};

#endif /*LEDBOARD_H*/
