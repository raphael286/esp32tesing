#include "physical.hpp"

void am_gpio_high(gpio_num_t pin) {
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    gpio_set_level(pin, 1);
}
void am_gpio_low(gpio_num_t pin) {
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    gpio_set_level(pin, 0);
}
void am_gpio_input(gpio_num_t pin) {
    gpio_config_t conf = {
        .pin_bit_mask = (1ULL << pin),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&conf);
}
void am_gpio_bidirectional(gpio_num_t pin) {
    gpio_set_direction(pin, GPIO_MODE_INPUT_OUTPUT_OD);
}
bool am_gpio_check(gpio_num_t pin) {
    return gpio_get_level(pin) == 1 ? true : false;
}