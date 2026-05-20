#include "storage.hpp"

bool am_nvs_init() {
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
        return false;
    }
    ESP_ERROR_CHECK(err);
    return true;
}

bool am_nvs_handle(const char* _namespace, nvs_handle_t* handle, nvs_open_mode_t mode, bool init) {
    if (init) am_nvs_init();
    esp_err_t err = nvs_open(_namespace, mode, handle);
    if (err != ESP_OK) {
        ESP_LOGE("am_nvs", "error while opening NVS handle: %s", esp_err_to_name(err));
        return false;
    }
    return true;
} 

bool am_nvs_write_checkret(esp_err_t err, const char* key) {
    if (err != ESP_OK) {
        ESP_LOGE("am_nvs", "error while writing to %s: %s", key, esp_err_to_name(err));
        return false;
    }
    return true;
}
bool am_nvs_write8(const char* key, uint8_t value, nvs_handle_t handle) {
    esp_err_t err = nvs_set_u8(handle, key, value);
    return am_nvs_write_checkret(err, key);
}
bool am_nvs_write16(const char* key, uint16_t value, nvs_handle_t handle) {
    esp_err_t err = nvs_set_u16(handle, key, value);
    return am_nvs_write_checkret(err, key);
}
bool am_nvs_write32(const char* key, uint32_t value, nvs_handle_t handle) {
    esp_err_t err = nvs_set_u32(handle, key, value);
    return am_nvs_write_checkret(err, key);
}
bool am_nvs_write64(const char* key, uint64_t value, nvs_handle_t handle) {
    esp_err_t err = nvs_set_u64(handle, key, value);
    return am_nvs_write_checkret(err, key);
}

bool am_nvs_read_checkret(esp_err_t err, const char* key) {
    if (err != ESP_OK) {
        ESP_LOGE("am_nvs", "error while reading from %s: %s", key, esp_err_to_name(err));
        return false;
    }
    return true;
}

bool am_nvs_read8(const char* key, nvs_handle_t handle, uint8_t* value) {
    esp_err_t err = nvs_get_u8(handle, key, value);
    return am_nvs_read_checkret(err, key);
}
bool am_nvs_read16(const char* key, nvs_handle_t handle, uint16_t* value) {
    esp_err_t err = nvs_get_u16(handle, key, value);
    return am_nvs_read_checkret(err, key);
}
bool am_nvs_read32(const char* key, nvs_handle_t handle, uint32_t* value) {
    esp_err_t err = nvs_get_u32(handle, key, value);
    return am_nvs_read_checkret(err, key);
}
bool am_nvs_read64(const char* key, nvs_handle_t handle, uint64_t* value) {
    esp_err_t err = nvs_get_u64(handle, key, value);
    return am_nvs_read_checkret(err, key);
}

bool am_nvs_erase(const char* key, nvs_handle_t handle) {
    esp_err_t err = nvs_erase_key(handle, key);
    if (err != ESP_OK) {
        ESP_LOGE("am_nvs", "error while erasing key %s: %s", key, esp_err_to_name(err));
        return false;
    }
    return true;
}

bool am_nvs_close(nvs_handle_t handle) {
    esp_err_t err = nvs_commit(handle);
    if (err != ESP_OK) {
        ESP_LOGE("am_nvs", "error while commiting handle: %s", esp_err_to_name(err));
        return false;
    }
    nvs_close(handle);
    return true;
}
