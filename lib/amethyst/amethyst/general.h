#ifndef AMETHYST_GENERAL_H
#define AMETHYST_GENERAL_H

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void gpio_high(gpio_num_t pin);
void gpio_low(gpio_num_t pin);
void gpio_bidirectional(gpio_num_t pin);

#endif