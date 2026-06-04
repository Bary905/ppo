#ifndef KEYBOARDLED_H
#define KEYBOARDLED_H

#include "Keyboard.h"
#include "LedBoard.h"

class KeyboardLed {

	public:
    	KeyboardLed(unsigned char _ucColumn);
    	void eRead(void);

	private:
	    Keyboard *pKeyboard;
	    LedBoard     *pLed;
};

#endif /* KEYBOARDLED_H */
