#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include <stdbool.h>
#include <stdio.h>

const uint BLINK_LED = 2;
const uint LED = 3;
const uint BTN = 4;

bool blink_led(struct repeating_timer *rt){

	static bool state = false;
	state = !state;
	gpio_put(BLINK_LED, state);
	return true;
}

int main(){

	stdio_init_all();

	const uint LED = 3;
	gpio_init(LED);
	gpio_set_dir(LED, GPIO_OUT);

	gpio_init(BLINK_LED);
	gpio_set_dir(BLINK_LED, GPIO_OUT);

	const uint BTN = 4;
	gpio_init(BTN);
	gpio_set_dir(BTN, GPIO_IN);
	gpio_pull_up(BTN);

	struct repeating_timer timer;

	if(!add_repeating_timer_ms(200, blink_led, NULL, &timer)){
		printf("Blink LED failed!\n");
	}

	while(1){
		if(gpio_get(BTN) == 0){
			gpio_put(LED, 1);
		}else{
			gpio_put(LED, 0);
		}
		sleep_ms(50);
	}
	return 0;
}
