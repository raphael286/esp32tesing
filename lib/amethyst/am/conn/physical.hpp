#ifndef AMETHYST_PHYSICAL_H
#define AMETHYST_PHYSICAL_H

#include "../general.hpp"

void am_gpio_high(gpio_num_t pin);
void am_gpio_low(gpio_num_t pin);
void am_gpio_bidirectional(gpio_num_t pin);
void am_gpio_input(gpio_num_t pin);
bool am_gpio_check(gpio_num_t pin);

void am_i2c_init(int sda_pin, int scl_pin);

#endif