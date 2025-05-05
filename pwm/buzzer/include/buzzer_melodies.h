#ifndef BUZZER_MELODIES_H
#define BUZZER_MELODIES_H

#include "pico/stdlib.h"

void gpio_pwm_setup(uint gpio_pin);

void play_tone(uint gpio_pin, uint freq, uint duration);

void melody_stop(uint gpio_pin);
void melody_starwars(uint gpio_pin);
void melody_stormwind(uint gpio_pin);
void melody_careless_whisper(uint gpio_pin);

#endif
