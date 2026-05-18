#include "../bluetooth.hpp"

bool am_ble_init() {
    if (!am_nvs_init()) return false;

    ESP_ERROR_CHECK(esp_bt_mem_release(ESP_BT_MODE_CLASSIC_BT));

    esp_bt_controller_config_t bt_config = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    if (am_ble_checkret(esp_bt_controller_init(&bt_config), "failed to initialize controller")) return false;
    if (am_ble_checkret(esp_bt_controller_enable(ESP_BT_MODE_BLE), "failed to enable controller")) return false;
    if (am_ble_checkret(esp_bluedroid_init(), "failed to initialize bluedroid")) return false;
    if (am_ble_checkret(esp_bluedroid_enable(), "failed to enable bluedroid")) return false;
    
    return true;
}

