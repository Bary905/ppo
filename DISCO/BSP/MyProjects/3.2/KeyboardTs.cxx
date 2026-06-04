#include <stm32f429i_discovery_ts.h>
#include "KeyboardTs.h"

KeyboardTs::KeyboardTs()
{
	BSP_TS_Init(240, 320);
}

enum KeyboardState KeyboardTs::eRead(void){

	TS_StateTypeDef TsState;
	BSP_TS_GetState(&TsState);

	if ((TsState.TouchDetected > 0) && ((0<=TsState.X) && (TsState.X<=80)))
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
