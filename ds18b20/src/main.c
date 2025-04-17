#include "onewire.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const uint TEMP_SENSOR = 15;

void pin_setup(const uint PIN){
	gpio_init(PIN);
	gpio_set_dir(PIN, GPIO_OUT);
}

int main(){
	stdio_init_all();

	float temp = 0.0f;

	pin_setup(TEMP_SENSOR);
	onewire_reset(TEMP_SENSOR);
	if(!ds18b20_start_reading(TEMP_SENSOR)){
		printf("Sensor is not responding!\n");
		return 1;
	}
	sleep_ms(750);
	if(ds18b20_is_reading_done(TEMP_SENSOR)){
		temp = ds18b20_read_temp(TEMP_SENSOR);
		printf("Temperature: %f\n", temp);
	}
	return 0;
}
