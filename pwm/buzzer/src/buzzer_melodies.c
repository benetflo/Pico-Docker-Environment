#include "buzzer_melodies.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

uint slice_num;

void gpio_pwm_setup(uint gpio_pin){

	gpio_set_function(gpio_pin, GPIO_FUNC_PWM);
        slice_num = pwm_gpio_to_slice_num(gpio_pin);

        pwm_set_enabled(slice_num, true);
}

void play_tone(uint gpio_pin, uint freq, uint duration){

	uint32_t pico_clock = 125000000;
        float div = 125.0f;
        uint32_t pwm_freq = (pico_clock / div);
        uint32_t wrap = (pwm_freq / freq);

        pwm_set_clkdiv(slice_num, div);
        pwm_set_wrap(slice_num, wrap);
        pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio_pin), wrap / 2);

        sleep_ms(duration);

        pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio_pin), 0);
        sleep_ms(50);

}

void melody_starwars(uint gpio_pin){

	int g_minor[] = {311, 392, 440, 466, 523, 587, 622, 698, 739, 783};

	play_tone(gpio_pin, g_minor[1] * 2, 400);
        play_tone(gpio_pin, g_minor[1] * 2, 400);
        play_tone(gpio_pin, g_minor[1] * 2, 400);
        play_tone(gpio_pin, g_minor[0] * 2, 300);
        play_tone(gpio_pin, g_minor[3] * 2, 80);
        play_tone(gpio_pin, g_minor[1] * 2, 400);
        play_tone(gpio_pin, g_minor[0] * 2, 300);
        play_tone(gpio_pin, g_minor[3] * 2, 80);
        play_tone(gpio_pin, g_minor[1] * 2, 400);
        sleep_ms(1000);
}

void melody_stormwind(uint gpio_pin){

	int e_minor[] = {329, 369, 392, 440, 493, 523, 587, 659};

        play_tone(gpio_pin, e_minor[7] * 2, 800);
        play_tone(gpio_pin, e_minor[6] * 2, 1300);
        play_tone(gpio_pin, e_minor[5] * 2, 470);
        play_tone(gpio_pin, e_minor[4] * 2, 2500);
        sleep_ms(10);
        play_tone(gpio_pin, e_minor[4] * 2, 750);
        play_tone(gpio_pin, e_minor[5] * 2, 2400);
        play_tone(gpio_pin, e_minor[4] * 2, 400);
        play_tone(gpio_pin, e_minor[3] * 2, 400);
        play_tone(gpio_pin, e_minor[4] * 2, 800);
        play_tone(gpio_pin, e_minor[7] * 2, 800);
        play_tone(gpio_pin, e_minor[0] * 2, 800);
        play_tone(gpio_pin, e_minor[1] * 2, 800);
        play_tone(gpio_pin, e_minor[2] * 2, 800);
        sleep_ms(1000);
}
