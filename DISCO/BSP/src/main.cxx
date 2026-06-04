#include <stm32f4xx_hal.h>

#include "Keyboard.h"
#include "LedBoard.h"

int main()
{
	LedBoard* KlawiaturaLed = new LedBoard(0);
	LedBoard* WyswietlaczLed = new LedBoard(2);

	Keyboard Keyboard(0);

	KlawiaturaLed->Off();
	WyswietlaczLed->Off();

	KeyboardState last_state = RELASED;

    while(1) {

    	KeyboardState current_state = Keyboard.eRead();
    	if(current_state != last_state)
    	{
			switch (current_state) {
				case BUTTON_1:
					KlawiaturaLed->On(0);
					WyswietlaczLed->On(3);
					break;
				case BUTTON_2:
					KlawiaturaLed->On(1);
					WyswietlaczLed->On(2);
					break;
				case BUTTON_3:
					KlawiaturaLed->On(2);
					WyswietlaczLed->On(1);
					break;
				case BUTTON_4:
					KlawiaturaLed->On(3);
					WyswietlaczLed->On(0);
					break;
				default:
					KlawiaturaLed->Off();
					WyswietlaczLed->Off();
					break;
			}
		last_state = current_state;
    	}
        HAL_Delay(50);
    }
}
