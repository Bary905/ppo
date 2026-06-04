#include <stm32f429i_discovery_lcd.h>

#include "LedBoard.h"

LedBoard::LedBoard(uint8_t kol)
{
	kolumna = kol;
	BSP_LCD_Init();
	BSP_LCD_DisplayOn();
	BSP_LCD_SetBackColor(LCD_COLOR_RED);
}

void LedBoard::Off()
{
    uint16_t x_start = kolumna * 80;

    BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
    BSP_LCD_FillRect(x_start, 0, 80, 320);

    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    for (uint8_t i = 0; i < 4; i++)
    {
        uint16_t y_pos = i * 80;
        BSP_LCD_DrawRect(x_start, y_pos, 80, 80);
        BSP_LCD_DisplayChar(x_start, y_pos, 0x31 + i);
    }
}

void LedBoard::On(uint8_t index)
{
    Off();
    if (index <= 3)
    {
        uint16_t x_start = kolumna * 80;
        uint16_t y_start = index * 80;

        BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
        BSP_LCD_FillRect(x_start, y_start, 80, 80);

        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
        BSP_LCD_DisplayChar(x_start, y_start, 0x31 + index);
    }
}
