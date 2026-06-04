#ifndef LEDBOARD_H
#define LEDBOARD_H

#include <stdint.h>

class LedBoard {

	public:
		LedBoard(uint8_t kol);
		void On(uint8_t index);
	private:
		uint8_t kolumna;
};

#endif /*LEDBOARD_H*/
