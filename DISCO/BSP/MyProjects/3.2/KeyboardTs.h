#ifndef KEYBOARDTS_H
#define KEYBOARDTS_H

enum KeyboardState{
	BUTTON_1,
	BUTTON_2,
	BUTTON_3,
	BUTTON_4,
	RELASED
};

class KeyboardTs {

	public:
	KeyboardTs();
	enum KeyboardState eRead(void);
};

#endif /*KEYBOARDTS_H*/
