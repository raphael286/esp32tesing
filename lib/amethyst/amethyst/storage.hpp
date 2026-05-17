#ifndef AMETHYST_STORAGE_H
#define AMETHYST_STORAGE_H

#include "nvs.h"
#include "nvs_flash.h"
#include "esp_log.h"
#include "general.hpp"

bool am_nvs_init();
bool am_nvs_handle(const char* _namespace, nvs_handle_t* handle, nvs_open_mode_t mode = NVS_READWRITE, bool init = false);
bool am_nvs_write(const char* key, uint64_t value, nvs_handle_t handle);
bool am_nvs_read(const char* key, nvs_handle_t handle, uint64_t* value);
bool am_nvs_erase(const char* key, nvs_handle_t handle);
bool am_nvs_close(nvs_handle_t handle);

#endif