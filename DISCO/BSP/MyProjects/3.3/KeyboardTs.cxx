#include <stm32f429i_discovery_ts.h>
#include "KeyboardTs.h"

KeyboardTs::KeyboardTs(uint8_t kol)
{
	kolumna = kol;
	BSP_TS_Init(240, 320);
}

enum KeyboardState KeyboardTs::eRead(void){

	TS_StateTypeDef TsState;
	BSP_TS_GetState(&TsState);

	uint16_t x_start = kolumna * 80;
	uint16_t x_end = x_start + 80;

	if ((TsState.TouchDetected > 0) && ((TsState.X >= x_start) && (TsState.X <= x_end)))
	{
		if((0<=TsState.Y) && (TsState.Y<80))
		{
			return BUTTON_1;
		}
		else if((80<=TsState.Y) && (TsState.Y<160))
		{
			return BUTTON_2;
		}
		else if((160<=TsState.Y) && (TsState.Y<240))
		{
			return BUTTON_3;
		}
		else if((240<=TsState.Y) && (TsState.Y<320))
		{
			return BUTTON_4;
		}

	}
	else
	{
		return RELASED;
	}
}
