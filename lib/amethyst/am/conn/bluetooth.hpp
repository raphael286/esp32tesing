#ifndef AMETHYST_BLUETOOTH_H
#define AMETHYST_BLUETOOTH_H

#include "esp_err.h"

bool am_ble_init();
bool am_ble_advertise(const char* name, const char* url, int name_size, int url_size);
bool am_ble_checkret(esp_err_t err, const char* msg);

#endif