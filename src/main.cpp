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

extern "C" void app_main(void) {
    TFT_eSPI tft = TFT_eSPI();
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK); 

    tft.setTextSize(3);
    tft.setTextDatum(TC_DATUM);
    tft.drawString("AMETHYSTv0.0", 240, 0);

    tft.setTextDatum(TL_DATUM);
    tft.setTextSize(2);
    tft.setCursor(0, 0);
    tft.println("\n\nTFT_eSPI initialized.");
    tft.println("Setting up touch control now...");

    nvs_handle_t handle = am_nvs_handle("amsys", NVS_READWRITE, true);
    uint16_t calibrationData[5];
    /*try
    {
        am_nvs_read("touchcal0", handle);
        calibrationData[0] = (uint16_t)am_nvs_read("touchcal0", handle);
        calibrationData[1] = (uint16_t)am_nvs_read("touchcal1", handle);
        calibrationData[2] = (uint16_t)am_nvs_read("touchcal2", handle);
        calibrationData[3] = (uint16_t)am_nvs_read("touchcal3", handle);
        calibrationData[4] = (uint16_t)am_nvs_read("touchcal4", handle);
    }
    catch(const std::exception& e)
    {*/
        tft.printf("Please be ready to calibrate your screen in 5 seconds.");
        am_long_wait(5000);

        tft.calibrateTouch(calibrationData, TFT_WHITE, TFT_RED, 15);
        am_nvs_write("touchcal0", (uint64_t)calibrationData[0], handle);
        am_nvs_write("touchcal1", (uint64_t)calibrationData[1], handle);
        am_nvs_write("touchcal2", (uint64_t)calibrationData[2], handle);
        am_nvs_write("touchcal3", (uint64_t)calibrationData[3], handle);
        am_nvs_write("touchcal4", (uint64_t)calibrationData[4], handle);
    //}
    tft.setTouch(calibrationData);
    tft.fillScreen(TFT_BLUE);
    
    /*while (1) {
        uint16_t x, y;
        static uint16_t color;

        if (tft.getTouch(&x, &y)) {

            tft.setCursor(5, 5, 2);
            tft.printf("x: %i     ", x);
            tft.setCursor(5, 20, 2);
            tft.printf("y: %i    ", y);

            tft.drawPixel(x, y, color);
            color += 155;
        }
    }*/
}