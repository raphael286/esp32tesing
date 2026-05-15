#include "general.h"

void am_gpio_high(gpio_num_t pin) {
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    gpio_set_level(pin, 1);
}
void am_gpio_low(gpio_num_t pin) {
    gpio_set_direction(pin, GPIO_MODE_INPUT);
    gpio_set_level(pin, 0);
}
void am_gpio_bidirectional(gpio_num_t pin) {
    gpio_set_direction(pin, GPIO_MODE_INPUT_OUTPUT_OD);
}

void am_wait(int ms) {
    vTaskDelay(ms / portTICK_PERIOD_MS);
}