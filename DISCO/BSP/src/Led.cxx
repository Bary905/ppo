#include "Led.h"
#include <stm32f429i_discovery_lcd.h>

Led::Led(unsigned char ucColumn, unsigned char ucRow)
{
    this->ucColumn = ucColumn;
    this->ucRow = ucRow;
}

void Led::Redraw(uint32_t Color)
{
    uint16_t x_start = ucColumn * 80;
    uint16_t y_start = ucRow * 80;

    BSP_LCD_SetTextColor(Color);
    BSP_LCD_FillRect(x_start, y_start, 80, 80);

    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_DrawRect(x_start, y_start, 80, 80);
    BSP_LCD_DisplayChar(x_start, y_start, 0x31 + ucRow);
}

void Led::On()
{
    Redraw(LCD_COLOR_GREEN);
}

void Led::Off()
{
    Redraw(LCD_COLOR_BLUE);
}
