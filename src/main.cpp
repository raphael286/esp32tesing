#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "ft6336.hpp"
#include "driver/i2c.h"

#include "driver/gpio.h"
#include "lvgl.h"
#include "TFT_eSPI.h"
#include "am/conn/physical.hpp"

#define SDA -1
#define SCL -1

#define SCREEN_WIDTH = 320
#define SCREEN_HEIGHT = 480

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
    am_i2c_init(SDA, SCL);
    tft.println("I2C initialized.");

    esp_idf::ft6336<480, 320> ts = esp_idf::ft6336<480, 320>(static_cast<i2c_port_t>(I2C_NUM_0));
    if (!ts.initialize()) am_log("main", "ft6336_htcw failed to initialize");
    tft.println("FT6336 series touch controller intialized.");
}

void tft_init() {
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK); 
}