#include "hcsr04.h"
#include "pico/time.h"
#include "hardware/gpio.h"

absolute_time_t start_timer;
absolute_time_t end_timer;
double distance = 0;
uint32_t time_passed = 0;

double hcsr04_get_distance(const uint TRIG, const uint ECHO){

        gpio_put(TRIG, 1);
        sleep_us(10);
        gpio_put(TRIG, 0);

        while(gpio_get(ECHO) == 0){
                ;
        }
        start_timer = get_absolute_time();

        while(gpio_get(ECHO) == 1){
                ;
        }
        end_timer = get_absolute_time();
        time_passed = absolute_time_diff_us(start_timer, end_timer);
        distance = (time_passed * 0.0343) / 2;

	return distance;
}
