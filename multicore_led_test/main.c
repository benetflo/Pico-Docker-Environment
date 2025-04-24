#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/multicore.h"


void core1_main(){

	const uint LED = 2;
	gpio_init(LED);
	gpio_set_dir(LED, GPIO_OUT);

	while(1){
		gpio_put(LED, 1);
		sleep_ms(200);
		gpio_put(LED, 0);
		sleep_ms(200);
	}
//	return 0;
}

int main(){

	stdio_init_all();

	const uint LED = 3;
	const uint BTN = 4;

	gpio_init(LED);
	gpio_init(BTN);

	gpio_set_dir(LED, GPIO_OUT);
	gpio_set_dir(BTN, GPIO_IN);

	gpio_pull_up(BTN);

	multicore_launch_core1(core1_main);

	//timer interrupt

	//core 0
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
