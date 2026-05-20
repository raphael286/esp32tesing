#include "../bluetooth.hpp"

#include "../../general.hpp"
#include "../../storage.hpp"
#include "esp_log.h"

#include "esp_bt.h"
#include "esp_gap_ble_api.h"
#include "esp_gattc_api.h"
#include "esp_gatt_defs.h"
#include "esp_bt_main.h"
#include "esp_bt_defs.h"
#include "esp_system.h"
#include "esp_bt_device.h"

static const char* tag = "am_ble";

bool am_ble_init() {
    if (!am_nvs_init()) return false;

    ESP_ERROR_CHECK(esp_bt_mem_release(ESP_BT_MODE_CLASSIC_BT));

    esp_bt_controller_config_t bt_config = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    if (am_checkret(tag, esp_bt_controller_init(&bt_config), "failed to initialize controller")) return false;
    if (am_checkret(tag, esp_bt_controller_enable(ESP_BT_MODE_BLE), "failed to enable controller")) return false;
    if (am_checkret(tag, esp_bluedroid_init(), "failed to initialize bluedroid")) return false;
    if (am_checkret(tag, esp_bluedroid_enable(), "failed to enable bluedroid")) return false;
    
    return true;
}

