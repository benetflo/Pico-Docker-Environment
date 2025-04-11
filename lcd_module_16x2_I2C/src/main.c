#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "lcd.h"
#include <stdio.h>


#define SDA_PIN 4
#define SCL_PIN 5

int main(){

	stdio_init_all();

	i2c_init(i2c0, 100 * 1000);
	gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
	gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
	gpio_pull_up(SDA_PIN);
	gpio_pull_up(SCL_PIN);

	lcd_init();

	lcd_send_command(0x80);
	const uint32_t char_delay = 200;

	while(1){
		lcd_send_command(RETURN_HOME);
		for(int i = 0; i < 16; i++){
			lcd_char('.');
			sleep_ms(char_delay);
		}
		lcd_set_cursor(1,0);
		lcd_send_command(RETURN_HOME);
		for(int i = 0; i < 16; i++){
                        lcd_char(' ');
                        sleep_ms(char_delay);
                }
	}
}
