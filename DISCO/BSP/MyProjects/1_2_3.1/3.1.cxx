#include <stm32f4xx_hal.h>
#include <stm32f429i_discovery_lcd.h>
#include <stm32f429i_discovery_ts.h>


int main(void)
{
	BSP_LCD_Init();
	BSP_TS_Init(240, 320);
	BSP_LCD_SetBackColor(LCD_COLOR_RED);
	BSP_LCD_DisplayOn();

	TS_StateTypeDef TsState;

	while (true) {

		BSP_TS_GetState(&TsState);

		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
		BSP_LCD_FillRect(0, 0, 80, 320);

		if ((TsState.TouchDetected > 0) && ((0<=TsState.X) && (TsState.X<=80)))
		{
			BSP_LCD_SetTextColor(LCD_COLOR_GREEN);

			if((0<=TsState.Y) && (TsState.Y<80))
			{
				BSP_LCD_FillRect(0, 0, 80, 80);
			}
			else if((80<=TsState.Y) && (TsState.Y<160))
			{
				BSP_LCD_FillRect(0, 80, 80, 80);
			}
			else if((160<=TsState.Y) && (TsState.Y<240))
			{
				BSP_LCD_FillRect(0, 160, 80, 80);
			}
			else if((240<=TsState.Y) && (TsState.Y<320))
			{
				BSP_LCD_FillRect(0, 240, 80, 80);
			}
		}
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_DrawRect(0, 0, 80, 80);
		BSP_LCD_DrawRect(0, 80, 80, 80);
		BSP_LCD_DrawRect(0, 160, 80, 80);
		BSP_LCD_DrawRect(0, 240, 80, 80);
		BSP_LCD_DisplayChar(0, 0, 0x31);
		BSP_LCD_DisplayChar(0, 80, 0x32);
		BSP_LCD_DisplayChar(0, 160, 0x33);
		BSP_LCD_DisplayChar(0, 240, 0x34);

		HAL_Delay(100);
	}
}
