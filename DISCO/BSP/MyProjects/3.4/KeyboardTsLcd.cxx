#include "KeyboardTsLcd.h"

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn)
{
    pKeyboard = new KeyboardTs(_ucColumn);
    pLed      = new LedLcd(_ucColumn);
}

void KeyboardTsLcd::eRead(void)
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
