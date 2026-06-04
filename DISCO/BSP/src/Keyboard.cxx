#include <stm32f429i_discovery_ts.h>

#include "Keyboard.h"

Keyboard::Keyboard(uint8_t kol)
{
	kolumna = kol;
	BSP_TS_Init(240, 320);
}

enum KeyboardState Keyboard::eRead(void){

	TS_StateTypeDef TsState;
	BSP_TS_GetState(&TsState);

	uint16_t x_start = kolumna * 80;
	uint16_t x_end = x_start + 80;

	uint8_t x_pos = TsState.X;
	uint8_t led_index = (TsState.Y/80);

	static const KeyboardState lut[] =
	{
		BUTTON_1,
	    BUTTON_2,
	    BUTTON_3,
	    BUTTON_4
	};

	if (TsState.TouchDetected == 0)
	{
		return RELASED;
	}
	if ((x_pos >= x_start) && (x_pos <= x_end))
	{
		return lut[led_index];
	}
	else
	{
		return RELASED;
	}
}
