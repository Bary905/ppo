#include <stm32f4xx_hal.h>
#include "KeyboardTs.h"
#include "LedLcd.h"


int main()
{
	LedLcd KlawiaturaLed(0);
	LedLcd WyswietlaczLed(2);

	KeyboardTs Keyboard(0);

	KlawiaturaLed.On(4);
	WyswietlaczLed.On(4);

	KeyboardState last_state = RELASED;

    while(1) {

    	KeyboardState current_state = Keyboard.eRead();
    	if(current_state != last_state)
    	{
			switch (current_state) {
				case BUTTON_1:
					KlawiaturaLed.On(0);
					WyswietlaczLed.On(3);
					break;
				case BUTTON_2:
					KlawiaturaLed.On(1);
					WyswietlaczLed.On(2);
					break;
				case BUTTON_3:
					KlawiaturaLed.On(2);
					WyswietlaczLed.On(1);
					break;
				case BUTTON_4:
					KlawiaturaLed.On(3);
					WyswietlaczLed.On(0);
					break;
				default:
					KlawiaturaLed.On(4);
					WyswietlaczLed.On(4);
					break;
			}
		last_state = current_state;
    	}
        HAL_Delay(50);
    }
}
