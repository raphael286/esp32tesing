#include "general.hpp"

void am_log(const char* tag, const char* content) {
    char result[sizeof(tag) + sizeof(content) + 3];
    sprintf(result, "%s: %s\n", tag, content);
    printf(result);
}

void am_quick_wait(int us) {
    ets_delay_us(us);
}
void am_long_wait(int ms) {
    vTaskDelay(ms / portTICK_PERIOD_MS);
}