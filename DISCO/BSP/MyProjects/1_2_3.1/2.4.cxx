#include <stm32f4xx_hal.h>
#include <stm32f429i_discovery_lcd.h>


int main(void)
{
	BSP_LCD_Init();
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_DisplayOn();

	unsigned char ucStr1[] = "ALPHA";
	unsigned char ucStr2[] = "CENTAURI";

	while (true) {
		HAL_Delay(1000);
		BSP_LCD_ClearStringLine(0x3);
		BSP_LCD_DisplayStringAtLine(0x3, (uint8_t *)ucStr1);
		HAL_Delay(1000);
		BSP_LCD_ClearStringLine(0x3);
		BSP_LCD_DisplayStringAtLine(0x3, (uint8_t *)ucStr2);
	}
}
