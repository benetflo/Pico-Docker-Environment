#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "onewire.h"
#include <stdbool.h>
#include <math.h>

// function to start communication
bool onewire_reset(const uint PIN){
    gpio_put(PIN, 0);
    sleep_us(480);
    gpio_put(PIN, 1);
    sleep_us(70);

    gpio_set_dir(PIN, GPIO_IN);
    if(gpio_get(PIN) == 0){
        sleep_us(410);
        return true // sensor answered
    }else{
        return false;
    }
}

// function to write bit
void onewire_write_bit(const uint PIN, bool bit){
	gpio_set_dir(PIN, GPIO_OUT);
	gpio_put(PIN, 0);
	if(bit == 1){
		sleep_us(6);
		gpio_put(PIN, 1);
		gpio_set_dir(PIN, GPIO_IN);
		sleep_us(64);
	}else{
		sleep_us(60);
		gpio_put(PIN, 1);
		gpio_set_dir(PIN, GPIO_IN);
		sleep_us(10);
	}
}

// function to send command
void onewire_write_byte(const uint PIN, uint8_t byte){
	for(int i = 0; i < 8; i++){
		uint8_t bit = (byte >> i) & 0x01;
		onewire_write_bit(PIN, bit);
	}
}

uint8_t onewire_read_bit(const uint PIN){
	gpio_set_dir(PIN, GPIO_OUT);
	gpio_put(PIN, 0);
	sleep_us(6);
	gpio_set_dir(PIN, GPIO_IN);
	sleep_us(9);
	uint8_t bit = gpio_get(PIN);
	sleep_us(55);
	return bit;
}

uint8_t onewire_read_byte(const uint PIN){
	uint8_t byte = 0;
	for(int i = 0; i < 8; i++){
		uint8_t bit = onewire_read_bit(PIN);
		byte |= (bit << i);
	}
	return byte;
}

bool ds18b20_start_reading(const uint PIN){
	if(!onewire_reset(PIN)){
		return false;
	}
	onewire_write_byte(PIN, SKIP_ROM);
	onewire_write_byte(PIN, CONVERT_T);
	return true;
}

bool ds18b20_is_reading_done(const uint PIN){
	return gpio_get(PIN);
}

float ds18b20_read_temp(const uint PIN){

	int16_t temperature = 0;
	float celsius = 0.0f;

	if(!onewire_reset(PIN)){
		return NAN;
	}
	onewire_write_byte(PIN, SKIP_ROM);
	onewire_write_byte(PIN, READ_SCRATCHPAD);

	uint8_t temp_lsb = onewire_read_byte(PIN); // least significant byte
	uint8_t temp_msb = onewire_read_byte(PIN); // most significant byte

	temperature = (temp_msb << 8) | temp_lsb;

	celsius = (temperature / 16.0);
	return celsius;
}
