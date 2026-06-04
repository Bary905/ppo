#ifndef KEYBOARDTSLCD_H
#define KEYBOARDTSLCD_H

#include "KeyboardTs.h"
#include "LedLcd.h"

class KeyboardTsLcd {

	public:
    	KeyboardTsLcd(unsigned char _ucColumn);
    	void eRead(void);

	private:
	    KeyboardTs *pKeyboard;
	    LedLcd     *pLed;
};

#endif /* KEYBOARDTSLCD_H */
