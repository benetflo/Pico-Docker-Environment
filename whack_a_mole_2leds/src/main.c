#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/rand.h"
#include <stdbool.h>
#include "pico/multicore.h"

const uint LED1 = 15;
const uint LED2 = 16;
const uint BTN = 14;
const uint BTN2 = 17;
const uint BUZZ = 13;

static bool led1_is_on = false;
static bool led2_is_on = false;

void init_gpio(){
	gpio_init(LED1);
	gpio_init(LED2);
	gpio_init(BTN);
	gpio_init(BTN2);
	gpio_init(BUZZ);

	gpio_set_dir(LED1, GPIO_OUT);
	gpio_set_dir(LED2, GPIO_OUT);
	gpio_set_dir(BTN, GPIO_IN);
	gpio_set_dir(BTN2, GPIO_IN);
	gpio_set_dir(BUZZ, GPIO_OUT);

	gpio_pull_up(BTN);
	gpio_pull_up(BTN2);
}

void core1_main(){
	uint32_t num = 0;

	while(1){
                num = get_rand_32();
                if(num < 2147483648){
                        gpio_put(LED1, 1);
                        led1_is_on = true;
                }else{
                        gpio_put(LED2, 1);
                        led2_is_on = true;
                }
                sleep_ms(200);
                led1_is_on = false;
                led2_is_on = false;
                gpio_put(LED1, 0);
                gpio_put(LED2, 0);
        }
}

int main(){
	stdio_init_all();
	init_gpio();

	multicore_launch_core1(core1_main);

	while(1){
		bool buzz_on = false;
		if(gpio_get(BTN) == 0 && led1_is_on){
			buzz_on = true;
		}

		if(gpio_get(BTN2) == 0 && led2_is_on){
			buzz_on = true;
		}
		gpio_put(BUZZ, buzz_on);
		sleep_ms(20);
	}
	return 0;
}
