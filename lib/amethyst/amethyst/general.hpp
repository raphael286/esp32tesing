#ifndef AMETHYST_GENERAL_H
#define AMETHYST_GENERAL_H

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "string.h"
#include "stdexcept"

void am_gpio_high(gpio_num_t pin);
void am_gpio_low(gpio_num_t pin);
void am_gpio_bidirectional(gpio_num_t pin);
void am_gpio_input(gpio_num_t pin);
bool am_gpio_check(gpio_num_t pin);

void am_quick_wait(int us);
void am_long_wait(int ms);

#define am_println(text) { printf(text); printf("\n"); }

#endif