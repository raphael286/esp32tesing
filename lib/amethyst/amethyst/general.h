#ifndef AMETHYST_GENERAL_H
#define AMETHYST_GENERAL_H

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void am_gpio_high(gpio_num_t pin);
void am_gpio_low(gpio_num_t pin);
void am_gpio_bidirectional(gpio_num_t pin);

void wait(int ms);

#define USEOR_PTR(ptr, fallback) ((ptr) != NULL ? (ptr) : (fallback))   

#endif