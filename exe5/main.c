#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

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
    int apertado_1 = 0;
    int apertado_2 = 0;

    while (true) {
        if (!gpio_get(BTN_PIN)) {
          if (apertado_1 == 1) {
            cnt_1 ++
            printf("Botao 1: %d\n", cnt_1++);
            apertado_1 -= 1;
            }
          else {
            cnt_1 ++
            printf("Botao 1: %d\n", cnt_1++);
            apertado_1 += 1;
            }
        sleep_ms(250);
        }

        if (!gpio_get(BTN_PIN_2)) {
          if (apertado_2 == 1) {
            cnt_2 ++
            printf("Botao 2: %d\n", cnt_2++);
            apertado_2 -= 1;
            }
          else {
            cnt_2 ++
            printf("Botao 2: %d\n", cnt_2++);
            apertado_2 += 1;
            }
        sleep_ms(250);
        }
    }
}
