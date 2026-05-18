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
#include "amethyst/am_tft_espi.hpp"
#include "amethyst/storage.hpp"

#define RPIN GPIO_NUM_34
#define UPIN GPIO_NUM_35
#define LPIN GPIO_NUM_16

void tft_init(TFT_eSPI tft);
void input_init(void);
void touch_init(TFT_eSPI tft);

extern "C" void app_main(void) {
    TFT_eSPI tft = TFT_eSPI();
    tft_init(tft);
    input_init();

    tft.setTextSize(3);
    tft.setTextDatum(TC_DATUM);
    tft.drawString("AMETHYSTv0.0", 240, 0);

    tft.setTextDatum(TL_DATUM);
    tft.setTextSize(2);
    tft.setCursor(0, 0);
    tft.println("\n\nTFT_eSPI initialized.");


}

void tft_init(TFT_eSPI tft) {
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK); 
}

void touch_init(TFT_eSPI tft) {
    tft.println("Setting up touch control now...");

    nvs_handle_t handle; 
    am_nvs_handle("amsys", &handle, NVS_READWRITE, true);

    uint16_t calibrationData[5];
    if (am_nvs_read16("touchcal0", handle, &calibrationData[0])) {
        am_nvs_read16("touchcal1", handle, &calibrationData[1]);
        am_nvs_read16("touchcal2", handle, &calibrationData[2]);
        am_nvs_read16("touchcal3", handle, &calibrationData[3]);
        am_nvs_read16("touchcal4", handle, &calibrationData[4]);
    } else
    {
        tft.printf("Please be ready to calibrate your screen in 5 seconds.");
        am_long_wait(5000);
        tft.printf("Tap the red dots on the corners of the screen.");

        tft.calibrateTouch(calibrationData, TFT_WHITE, TFT_RED, 15);
        am_nvs_write16("touchcal0", calibrationData[0], handle);
        am_nvs_write16("touchcal1", calibrationData[1], handle);
        am_nvs_write16("touchcal2", calibrationData[2], handle);
        am_nvs_write16("touchcal3", calibrationData[3], handle);
        am_nvs_write16("touchcal4", calibrationData[4], handle);
    }
    tft.setTouch(calibrationData);
}