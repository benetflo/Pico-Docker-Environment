#include "led_programs.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdint.h>

void blink(const uint32_t PIN, uint32_t delay){
	gpio_put(PIN, 1);
	sleep_ms(delay);
	gpio_put(PIN, 0);
	sleep_ms(delay);
}

void button_led(const uint32_t PIN, const uint32_t BUTTON){
	if(gpio_get(BUTTON) == 0){
		gpio_put(PIN, 1);
	}else{
		gpio_put(PIN, 0);
	}
}
