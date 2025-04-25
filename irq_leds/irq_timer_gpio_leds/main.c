#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include <stdbool.h>
#include <stdio.h>

const uint BLINK_LED = 2;
const uint LED = 3;
const uint BTN = 4;
const uint GREEN_LED = 5;
const uint BTN2 = 6;

static bool toggle_state = false;

bool blink_led(struct repeating_timer *rt){

	static bool state = false;
	state = !state;
	gpio_put(BLINK_LED, state);
	return true;
}

void toggle_led(uint gpio, uint32_t events){
	toggle_state = !toggle_state;
	gpio_put(GREEN_LED, toggle_state);
}

int main(){

	stdio_init_all();

	gpio_init(LED);
	gpio_set_dir(LED, GPIO_OUT);

	gpio_init(BLINK_LED);
	gpio_set_dir(BLINK_LED, GPIO_OUT);

	gpio_init(BTN);
	gpio_set_dir(BTN, GPIO_IN);
	gpio_pull_up(BTN);

	gpio_init(BTN2);
	gpio_set_dir(BTN2, GPIO_IN);
	gpio_pull_up(BTN2);

	gpio_init(GREEN_LED);
	gpio_set_dir(GREEN_LED, GPIO_OUT);

	struct repeating_timer timer;

	if(!add_repeating_timer_ms(200, blink_led, NULL, &timer)){
		printf("Blink LED failed!\n");
	}

	gpio_set_irq_enabled_with_callback(BTN2, GPIO_IRQ_EDGE_FALL, true, &toggle_led);

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
