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

bool am_nvs_write(const char* key, uint64_t value, nvs_handle_t handle) {
    esp_err_t err = nvs_set_u64(handle, key, value);
    if (err != ESP_OK) {
        ESP_LOGE("am_nvs", "error while writing to %s: %s", key, esp_err_to_name(err));
        return false;
    }
    return true;
}

bool am_nvs_read(const char* key, nvs_handle_t handle, uint64_t* value) {
    esp_err_t err = nvs_get_u64(handle, key, value);
    if (err != ESP_OK) {
        ESP_LOGE("am_nvs", "error while reading key %s: %s", key, esp_err_to_name(err));
        return false;
    }
    return true;
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
