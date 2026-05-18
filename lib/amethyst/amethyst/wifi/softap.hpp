#ifndef AMETHYST_WIFI_SOFTAP_H
#define AMETHYST_WIFI_SOFTAP_H

#include "../wifi.hpp"

#define am_softap_init(ssid, pass, channel, max_connection, evt_handler) do { \
    const char* tag = "am_softap"\
    if (am_checkret(tag, esp_netif_init(), "failed to initialize the TCP/IP stack")) return false\
    if (am_checkret(tag, esp_event_loop_create_default(), "failed to create event loop")) return false\
    esp_netif_create_default_wifi_ap()\
    wifi_init_config_t init_config = WIFI_INIT_CONFIG_DEFAULT()\
    if (am_checkret(tag, esp_wifi_init(&init_config), "failed to initialize wifi")) return false\
    if (am_checkret(tag, esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &evt_handler, NULL, NULL), "failed to register handler")) return false\
    wifi_config_t config = {\
        .ap = {\
            .ssid = ssid, \
            .ssid_len = strlen(ssid),\
            .channel = channel,\
            .password = pass,\
            .max_connection = max_connection\
        }\
    }\
    if (am_checkret(tag, esp_wifi_set_mode(WIFI_MODE_AP), "failed to set mode")) return false\
    if (am_checkret(tag, esp_wifi_set_config(WIFI_IF_AP, &config), "failed to set config")) return false\
    if (am_checkret(tag, esp_wifi_start(), "failed to start wifi")) return false\
    am_log(tag, "am_soft_ap exited successfully!")\
    return true\
} while (0)

#endif