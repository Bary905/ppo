#include <stm32f4xx_hal.h>
#include <stm32f429i_discovery.h>
#include <stm32f429i_discovery_lcd.h>


int main(void)
{
	BSP_LCD_Init();
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_DrawRect(10, 20, 40, 30);
	BSP_LCD_DisplayOn();
	BSP_LED_Init(LED4);
	while (true) {
		BSP_LED_Toggle(LED4);
		HAL_Delay(100);
	}
}
