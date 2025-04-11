#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "led_programs.h"

int main(){

	const uint32_t LED = 16;
	const uint32_t BUTTON = 17;

	gpio_init(LED);
	gpio_set_dir(LED, GPIO_OUT);

	gpio_init(BUTTON);
	gpio_set_dir(BUTTON, GPIO_IN);
	gpio_pull_up(BUTTON);


	uint32_t delay = 200;

	while(1){
		button_led(LED, BUTTON);
		sleep_ms(50);
	}
	return 0;
}
