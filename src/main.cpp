#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "driver/i2c.h"

#include "driver/gpio.h"
#include "lvgl.h"
#include "TFT_eSPI.h"
#include "am/conn/bluetooth.hpp"

void tft_init();

TFT_eSPI tft = TFT_eSPI();
extern "C" void app_main(void) {
    tft_init();

    tft.setTextSize(3);
    tft.setTextDatum(TC_DATUM);
    tft.drawString("AMETHYSTv0.0", 240, 0);

    tft.setTextDatum(TL_DATUM);
    tft.setTextSize(2);
    tft.setCursor(0, 0);
    tft.println("\n\nTFT_eSPI initialized.");
    
    am_ble_init();
    tft.println("BLE initialized.");
    am_ble_advertise("am_device", "", 9, 0);
    tft.println("BLE advertising started.");
}

void tft_init() {
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK); 
}