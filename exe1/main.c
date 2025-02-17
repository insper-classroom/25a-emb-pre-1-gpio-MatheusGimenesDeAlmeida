#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN_RED = 5;
const int LED_PIN_YELLOW = 28;


int main() {
    stdio_init_all();

    gpio_init(LED_PIN_RED);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);

    
    while (true) {
        gpio_put(LED_PIN_RED, 1);
        gpio_put(LED_PIN_YELLOW, 1);
        sleep_ms(400);
        gpio_put(LED_PIN_RED, 0);
        gpio_put(LED_PIN_YELLOW, 0);
        sleep_ms(400);
    }
}

