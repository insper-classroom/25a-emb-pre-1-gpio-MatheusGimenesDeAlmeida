#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;


bool debounce_button(int pin) {
    if (!gpio_get(pin)) {  
        sleep_ms(50);  
        if (!gpio_get(pin)) {  
            while (!gpio_get(pin)) {  
                sleep_ms(10);
            }
            return true;  
        }
    }
    return false;  
}

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);

    int cnt_1 = 0;
    int cnt_2 = 0;

    while (true) {
        if (debounce_button(BTN_PIN)) {
            printf("Botao 1: %d\n", cnt_1++);
        }
        if (debounce_button(BTN_PIN_2)) {
            printf("Botao 2: %d\n", cnt_2++);
        }
    }

    return 0;
}
