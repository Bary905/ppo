#ifndef LEDBOARD_H
#define LEDBOARD_H

#include "Led.h"
#include <vector>

class LedBoard
{
	public:
		LedBoard (unsigned char ucColumn);
		void Off();
		void On(unsigned char);
	private:
		std::vector<Led*> Leds;
};

#endif /*LEDBOARD_H*/
