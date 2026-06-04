#include <stm32f4xx_hal.h>
#include <stm32f429i_discovery_lcd.h>
#include <stm32f429i_discovery_ts.h>


int main(void)
{
	BSP_LCD_Init();
	BSP_TS_Init(240, 320);
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_DisplayOn();

	TS_StateTypeDef TsState;

	while (true) {

		BSP_TS_GetState(&TsState);

		if (TsState.TouchDetected > 0)
		{
			BSP_LCD_ClearStringLine(0x3);
			BSP_LCD_DisplayStringAtLine(0x3, (uint8_t *) "Pressed");
		}else{
			BSP_LCD_ClearStringLine(0x3);
			BSP_LCD_DisplayStringAtLine(0x3, (uint8_t *) "******");

		}
		HAL_Delay(50);
	}
}
