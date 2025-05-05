#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

//From right to left from 4x4 keypad -> 21 20 19 18 13 12 11 10
uint columns[4] = {18, 19, 20, 21};
uint rows[4] = {10, 11, 12, 13};

char matrix[16] = {
    '1', '2' , '3', 'A',
    '4', '5' , '6', 'B',
    '7', '8' , '9', 'C',
    '*', '0' , '#', 'D'
};

void init_pins(){

        for(int i = 0; i < 4; i++){

                gpio_init(columns[i]);
                gpio_init(rows[i]);

                gpio_set_dir(columns[i], GPIO_IN);
                gpio_set_dir(rows[i], GPIO_OUT);

                gpio_put(rows[i], 1);
        }
}

char get_key_pressed(){
	size_t counter = 0;

	for(int i = 0; i < 4; i++){
                gpio_put(rows[i], 0);
        }

        for(int i = 0; i < 4; i++){
                gpio_put(rows[i], 1);

                sleep_us(10000);
                for(int j = 0; j < 4; j++){
                        if(gpio_get(columns[j])){
                                return matrix[counter];
                        }
                        counter++;
                }
        }

}

int main(){
        stdio_init_all();
        init_pins();

        while(1){
		printf("%c\n", get_key_pressed());
        }

}
