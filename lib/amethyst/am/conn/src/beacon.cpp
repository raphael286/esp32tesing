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

static uint8_t adv_start[] = { 0x02, ESP_BLE_AD_TYPE_FLAG, 0x06, 0x11, ESP_BLE_AD_TYPE_NAME_CMPL };
static uint8_t adv_end[] = { 0x02, ESP_BLE_AD_TYPE_TX_PWR, 0x09, 0x03, ESP_BLE_AD_TYPE_APPEARANCE, 0x00,0x02,
    0x02, ESP_BLE_AD_TYPE_LE_ROLE, 0x00 };
static uint8_t scan_rsp_raw_start[] = { 0x08, ESP_BLE_AD_TYPE_LE_DEV_ADDR };
static uint8_t scan_rsp_raw_mid[] = { 0x11, ESP_BLE_AD_TYPE_URI, 0x17, '/', '/' };
static const char* tag = "am_ble";
static bool config_done = false;

void cb(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param);

static esp_ble_adv_params_t adv_params = {
    .adv_int_min = 0x20,
    .adv_int_max = 0x20,
    .adv_type = ADV_TYPE_SCAN_IND,
    .own_addr_type = BLE_ADDR_TYPE_PUBLIC,
    .channel_map = ADV_CHNL_ALL,
    .adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};

bool am_ble_advertise(const char* name, const char* url, int name_size, int url_size) {
    if (am_checkret(tag, esp_ble_gap_register_callback(cb), "failed to register callback")) return false;
    if (am_checkret(tag, esp_ble_gap_set_device_name(name), "failed to set device name")) return false;

    uint8_t adv_raw_data[sizeof(name) + sizeof(adv_start) + sizeof(adv_end)];
    memcpy(adv_raw_data, adv_start, sizeof(adv_start));
    memcpy(adv_raw_data + sizeof(adv_start), (uint8_t*)name, name_size);
    memcpy(adv_raw_data + sizeof(adv_start) + name_size, adv_end, sizeof(adv_end));

    if (am_checkret(tag, esp_ble_gap_config_adv_data_raw(adv_raw_data, sizeof(adv_raw_data)), "failed to configure advertisement data")) return false;
    config_done = true;

    esp_bd_addr_t local_addr;
    uint8_t local_addr_type;
    if (am_checkret(tag, esp_ble_gap_get_local_used_addr(local_addr, &local_addr_type), "failed to get local used address")) return false;

    uint8_t scan_rsp_raw_data[sizeof(scan_rsp_raw_start) + sizeof(local_addr) + sizeof(scan_rsp_raw_mid) + sizeof(url)]; int place = 0;
    memcpy(scan_rsp_raw_data, scan_rsp_raw_start, sizeof(scan_rsp_raw_start)); place += sizeof(scan_rsp_raw_start);
    memcpy(scan_rsp_raw_data + place, local_addr, sizeof(local_addr)); place += sizeof(local_addr);
    memcpy(scan_rsp_raw_data + place, scan_rsp_raw_mid, sizeof(scan_rsp_raw_mid)); place += sizeof(scan_rsp_raw_mid);
    memcpy(scan_rsp_raw_data + place, url, url_size);
    if (am_checkret(tag, esp_ble_gap_config_scan_rsp_data_raw(scan_rsp_raw_data, sizeof(scan_rsp_raw_data)), "failed to configure scan rsp data")) return false;

    am_log("am_ble", "Successfully exited am_ble_advertise!");

    return true;
}

void cb(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param) {
        switch (event) {
        case ESP_GAP_BLE_ADV_DATA_SET_COMPLETE_EVT:
            if (!config_done) break;
            esp_ble_gap_start_advertising(&adv_params);
            break;
        case ESP_GAP_BLE_ADV_DATA_RAW_SET_COMPLETE_EVT:
            if (!config_done) break;
            esp_ble_gap_start_advertising(&adv_params);
            break;
        case ESP_GAP_BLE_SCAN_RSP_DATA_SET_COMPLETE_EVT:
            if (!config_done) break;
            esp_ble_gap_start_advertising(&adv_params);
            break;
        case ESP_GAP_BLE_SCAN_RSP_DATA_RAW_SET_COMPLETE_EVT:
            if (!config_done) break;
            esp_ble_gap_start_advertising(&adv_params);
            break;
        case ESP_GAP_BLE_ADV_START_COMPLETE_EVT:
            if (param->adv_start_cmpl.status != ESP_BT_STATUS_SUCCESS) {
                am_log("am_ble", "failed to start advertising");
            }
            am_log("am_ble", "Started advertising!");
            break;
        default:
            break;
        }
    };