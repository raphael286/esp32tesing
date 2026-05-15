#ifndef AMETHYST_GENERAL_H
#define AMETHYST_GENERAL_H

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"

void am_gpio_high(gpio_num_t pin);
void am_gpio_low(gpio_num_t pin);
void am_gpio_bidirectional(gpio_num_t pin);

void am_quick_wait(int ms);
void am_long_wait(int ms);

#define USEOR(ptr, fallback) ((ptr) != NULL ? (*ptr) : (fallback))   

#endif