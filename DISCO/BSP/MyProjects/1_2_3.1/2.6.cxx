#include <stm32f4xx_hal.h>
#include <stm32f429i_discovery_lcd.h>
#include <cstdio>


int main(void)
{
	BSP_LCD_Init();
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_DisplayOn();

	unsigned char ucBuffer[12];
	unsigned int uiXSize = BSP_LCD_GetXSize();
	unsigned int uiYSize = BSP_LCD_GetYSize();

	sprintf((char *)ucBuffer,"X=%d; Y=%d", uiXSize, uiYSize);
	BSP_LCD_ClearStringLine(0x3);
	BSP_LCD_DisplayStringAtLine(0x3, (uint8_t *) ucBuffer);

	while (true) {
	}
}
