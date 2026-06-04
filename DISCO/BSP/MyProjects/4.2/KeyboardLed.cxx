#include "KeyboardLed.h"

KeyboardLed::KeyboardLed(unsigned char _ucColumn)
{
    pKeyboard = new Keyboard(_ucColumn);
    pLed      = new LedBoard(_ucColumn);
}

void KeyboardLed::eRead(void)
{
    KeyboardState state = pKeyboard->eRead();

    switch(state) {
        case BUTTON_1:
            pLed->On(0);
            break;
        case BUTTON_2:
            pLed->On(1);
            break;
        case BUTTON_3:
            pLed->On(2);
            break;
        case BUTTON_4:
            pLed->On(3);
            break;
        case RELASED:
        default:
            pLed->On(4);
            break;
    }
}
