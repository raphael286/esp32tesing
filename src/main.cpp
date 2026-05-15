#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

#include "driver/gpio.h"
#include "lvgl.h"
#include "TFT_eSPI.h"
#include "amethyst/general.hpp"
#include "amethyst/screen.hpp"

extern "C" void app_main(void) {
    lv_init();

    am_create_display(480, 320, lv_color_hex(0xff0000));
    am_create_label(lv_screen_active(), "Hello!", LV_ALIGN_CENTER, 0, 0);
    while (true) { am_display_handler(); }
}