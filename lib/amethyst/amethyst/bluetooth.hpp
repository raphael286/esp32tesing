#ifndef AMETHYST_BLUETOOTH_H
#define AMETHYST_BLUETOOTH_H

#include "general.hpp"
#include "storage.hpp"
#include "esp_log.h"

#include "esp_bt.h"
#include "esp_gap_ble_api.h"
#include "esp_gattc_api.h"
#include "esp_gatt_defs.h"
#include "esp_bt_main.h"
#include "esp_bt_defs.h"
#include "esp_system.h"
#include "esp_bt_device.h"


bool am_ble_init();
bool am_ble_advertise(const char* name, const char* uri);

#endif