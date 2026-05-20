#ifndef AMETHYST_STORAGE_H
#define AMETHYST_STORAGE_H

#include "nvs.h"
#include "nvs_flash.h"
#include "esp_log.h"
#include "general.hpp"



bool am_nvs_init();
bool am_nvs_handle(const char* _namespace, nvs_handle_t* handle, nvs_open_mode_t mode = NVS_READWRITE, bool init = false);

bool am_nvs_write8(const char* key, uint8_t value, nvs_handle_t handle);
bool am_nvs_write16(const char* key, uint16_t value, nvs_handle_t handle);
bool am_nvs_write32(const char* key, uint32_t value, nvs_handle_t handle);
bool am_nvs_write64(const char* key, uint64_t value, nvs_handle_t handle);

bool am_nvs_read8(const char* key, nvs_handle_t handle, uint8_t* value);
bool am_nvs_read16(const char* key, nvs_handle_t handle, uint16_t* value);
bool am_nvs_read32(const char* key, nvs_handle_t handle, uint32_t* value);
bool am_nvs_read64(const char* key, nvs_handle_t handle, uint64_t* value);

bool am_nvs_erase(const char* key, nvs_handle_t handle);
bool am_nvs_close(nvs_handle_t handle);

#endif