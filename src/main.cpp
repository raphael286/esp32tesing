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
#include "amethyst/general.h"

static lv_color_t buf[320 * 480 / 10];

extern "C" void app_main(void) {
    lv_init();

  /* Initialize TFT_eSPI display using LVGL's driver */
  lv_display_t * disp = lv_tft_espi_create(
    320, 
    480, 
    buf, 
    sizeof(buf)
  );

  /* Set rotation if needed */
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);

  /* Create a simple label */
  lv_obj_t * label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, "Hello LVGL V9!");
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

  while (true) { vTaskDelay(5 / portTICK_PERIOD_MS); lv_timer_handler(); }
}