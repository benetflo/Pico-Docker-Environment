#ifndef LCD_H
#define LCD_H

#define RETURN_HOME 0x02
#define LCD_CLEAR_SCREEN 0x01
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_FUNCTIONSET 0x20
#define LCD_SETDDRAMADDR 0x80
#define LCD_ENTRYLEFT 0x02
#define LCD_DISPLAYON 0x04
#define LCD_2LINE 0x08
#define LCD_BACKLIGHT 0x08
#define LCD_ENABLE_BIT 0x04
#define LCD_CHARACTER 1
#define LCD_COMMAND 0



void i2c_write_byte(uint8_t value);

void lcd_enable_pulse_toggle(uint8_t value);

void lcd_send_byte(uint8_t value, int mode);

void lcd_clear(void);

void lcd_char(char value);

void lcd_set_cursor(uint8_t row, uint8_t col);

void lcd_send_command(uint8_t value);

void lcd_init(void);

#endif
