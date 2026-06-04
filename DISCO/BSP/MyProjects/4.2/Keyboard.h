#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

enum KeyboardState{
	BUTTON_1,
	BUTTON_2,
	BUTTON_3,
	BUTTON_4,
	RELASED
};

class Keyboard {

	public:
		Keyboard(uint8_t kol);
		enum KeyboardState eRead(void);
	private:
		uint8_t kolumna;
};

#endif /*KEYBOARD_H*/
