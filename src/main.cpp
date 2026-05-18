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
#include "amethyst/bluetooth.hpp"

#define RPIN GPIO_NUM_34
#define UPIN GPIO_NUM_35
#define LPIN GPIO_NUM_16

static char name[] = "am_mc";
static char url[] = "jewels86.me";
TFT_eSPI tft = TFT_eSPI();

void tft_init(void);

extern "C" void app_main(void) {
    tft_init();

    tft.setTextSize(3);
    tft.setTextDatum(TC_DATUM);
    tft.drawString("AMETHYSTv0.0", 240, 0);

    tft.setTextDatum(TL_DATUM);
    tft.setTextSize(2);
    tft.setCursor(0, 0);
    tft.println("\n\nTFT_eSPI initialized.");
    
    if (!am_ble_init()) tft.fillScreen(TFT_RED);
    tft.println("BLE initialized.");
    tft.println("\nAdvertising under BLE name 'am_mc'...");
    if (!am_ble_advertise(name, url, sizeof(name), sizeof(url))) tft.fillScreen(TFT_RED);

    am_long_wait(10000);
}

void tft_init() {
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK); 
}