#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_RED = 28;
const int BTN_PIN_GREEN  = 26;
const int LED_PIN_RED = 4;
const int LED_PIN_GREEN = 6; 


int main() {
    stdio_init_all();

    gpio_init(BTN_PIN_GREEN);
    gpio_init(BTN_PIN_RED);
    gpio_init(LED_PIN_RED);
    gpio_init(LED_PIN_GREEN);

    gpio_set_dir(BTN_PIN_GREEN, GPIO_IN);
    gpio_set_dir(BTN_PIN_RED, GPIO_IN);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    gpio_pull_up(BTN_PIN_GREEN);
    gpio_pull_up(BTN_PIN_RED);

    int apertado_red = 0;
    int apertado_green = 0;

    while (true) {
        if (!gpio_get(BTN_PIN_RED)) {
            if (apertado_red == 1) {
                gpio_put(LED_PIN_RED, 0);
                printf("Desligando LED vermelho\n");
                apertado_red -= 1;
            }
            else {
                printf("Ligando LED vermelho\n");
                gpio_put(LED_PIN_RED, 1);
                apertado_red += 1;
            }
            sleep_ms(250);
        }

        if (!gpio_get(BTN_PIN_GREEN)) {
            if (apertado_green == 1) {
                gpio_put(LED_PIN_GREEN, 0);
                printf("Desligando LED verde\n");
                apertado_green -=1;
            }
            else {
                printf("Ligando LED verde\n");
                gpio_put(LED_PIN_GREEN, 1);
                apertado_green += 1;
            }
            sleep_ms(250);
        }
    }
    return 0; 
}