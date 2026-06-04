#ifndef KEYBOARDTS_H
#define KEYBOARDTS_H

#include <stdint.h>

enum KeyboardState{
	BUTTON_1,
	BUTTON_2,
	BUTTON_3,
	BUTTON_4,
	RELASED
};

class KeyboardTs {

	public:
		KeyboardTs(uint8_t kol);
		enum KeyboardState eRead(void);
	private:
		uint8_t kolumna;
};

#endif /*KEYBOARDTS_H*/
