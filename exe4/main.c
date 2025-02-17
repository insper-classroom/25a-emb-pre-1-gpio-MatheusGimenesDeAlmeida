#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;
const int LED_PIN_RED = 5;
const int LED_PIN_PP = 8; 
const int LED_PIN_BLU = 11;
const int LED_PIN_YE = 15;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_init(LED_PIN_RED);
    gpio_init(LED_PIN_PP);
    gpio_init(LED_PIN_BLU);
    gpio_init(LED_PIN_YE);

    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_set_dir(LED_PIN_PP, GPIO_OUT);
    gpio_set_dir(LED_PIN_BLU, GPIO_OUT);
    gpio_set_dir(LED_PIN_YE, GPIO_OUT);

    gpio_pull_up(BTN_PIN);

    while (true) {
        if (!gpio_get(BTN_PIN)) {
          gpio_put(LED_PIN_RED, 1);
          sleep_ms(300);
          gpio_put(LED_PIN_RED, 0);
          gpio_put(LED_PIN_PP, 1);
          sleep_ms(300);
          gpio_put(LED_PIN_PP, 0);
          gpio_put(LED_PIN_BLU, 1);
          sleep_ms(300);
          gpio_put(LED_PIN_BLU, 0);
          gpio_put(LED_PIN_YE, 1);
          sleep_ms(300);
          gpio_put(LED_PIN_YE, 0);
        }
        sleep_ms(50);}
    return; 
}