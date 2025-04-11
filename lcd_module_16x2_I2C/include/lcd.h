#ifndef LCD_H
#define LCD_H

void i2c_write_byte(uint8_t value);

void lcd_enable_pulse_toggle(uint8_t value);

void lcd_send_byte(uint8_t value, int mode);

void lcd_clear(void);

void lcd_init(void);

#endif
