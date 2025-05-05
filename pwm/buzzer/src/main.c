#include "buzzer_melodies.h"
#include "pico/stdlib.h"


const uint BUZZER = 16;



int main(){

	gpio_pwm_setup(BUZZER);
	while(1){
		melody_careless_whisper(BUZZER);
	}
	return 0;
}
