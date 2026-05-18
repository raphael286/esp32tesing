#ifndef AMETHYST_GENERAL_H
#define AMETHYST_GENERAL_H

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "string.h"
#include "stdexcept"

void am_log(const char* tag, const char* content);
bool am_checkret(const char* tag, esp_err_t err, const char* msg);

void am_quick_wait(int us);
void am_long_wait(int ms);

#define am_println(text) { printf(text); printf("\n"); }

#endif