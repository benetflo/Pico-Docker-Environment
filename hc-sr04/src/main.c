#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>
#include "pico/time.h"
#include <stdint.h>
#include "hcsr04.h"

const uint TRIG = 13;
const uint ECHO = 12;

void pin_setup(const uint PIN1, const uint PIN2){
	gpio_init(PIN1);
	gpio_init(PIN2);
	gpio_set_dir(PIN1, GPIO_OUT);
	gpio_set_dir(PIN2, GPIO_IN);
}

int main(){

	stdio_init_all();

	double distance = 0.0;

	pin_setup(TRIG, ECHO);

	while(1){

		distance = hcsr04_get_distance(TRIG, ECHO);
		printf("Distance: %lf\n", distance);
		sleep_ms(200);
	}
}
