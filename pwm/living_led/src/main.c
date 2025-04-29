#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

#define MAX_L 1000

const uint LED = 16;


uint slice_num;

void setup_pwm(uint gpio_pin){
	gpio_set_function(gpio_pin, GPIO_FUNC_PWM);
	slice_num = pwm_gpio_to_slice_num(gpio_pin);
	pwm_set_wrap(slice_num, 1000);
	pwm_set_enabled(slice_num, true);
}



int main(){

	stdio_init_all();
	setup_pwm(LED);
	float procent = 0.05f;

	while(1){
		procent = 0.05;
		for(int i = 0; i < 20; i++){
			pwm_set_chan_level(slice_num, pwm_gpio_to_channel(LED), (MAX_L * procent));
			sleep_ms(200);
			procent += 0.05;
		}
	}


	return 0;
}
