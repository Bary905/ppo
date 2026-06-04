#include <stm32f429i_discovery_lcd.h>

#include "LedBoard.h"

LedBoard::LedBoard(uint8_t kol)
{
	kolumna = kol;
	BSP_LCD_Init();
	BSP_LCD_DisplayOn();
	BSP_LCD_SetBackColor(LCD_COLOR_RED);
}

void LedBoard::On(uint8_t index)
{
	uint16_t x_start = kolumna * 80;

	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_FillRect(x_start, 0, 80, 320);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DrawRect(x_start, 0, 80, 80);
	BSP_LCD_DrawRect(x_start, 80, 80, 80);
	BSP_LCD_DrawRect(x_start, 160, 80, 80);
	BSP_LCD_DrawRect(x_start, 240, 80, 80);
	BSP_LCD_DisplayChar(x_start, 0, 0x31);
	BSP_LCD_DisplayChar(x_start, 80, 0x32);
	BSP_LCD_DisplayChar(x_start, 160, 0x33);
	BSP_LCD_DisplayChar(x_start, 240, 0x34);
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);

	switch(index){
		case 0:
			BSP_LCD_FillRect(x_start, 0, 80, 80);
			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			BSP_LCD_DisplayChar(x_start, 0, 0x31);
		break;
		case 1:
			BSP_LCD_FillRect(x_start, 80, 80, 80);
			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			BSP_LCD_DisplayChar(x_start, 80, 0x32);
		break;
		case 2:
			BSP_LCD_FillRect(x_start, 160, 80, 80);
			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			BSP_LCD_DisplayChar(x_start, 160, 0x33);
		break;
		case 3:
			BSP_LCD_FillRect(x_start, 240, 80, 80);
			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			BSP_LCD_DisplayChar(x_start, 240, 0x34);
		break;
		case 4:
		break;
		default:
		break;
	}
}
