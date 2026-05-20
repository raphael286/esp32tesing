#include "../touch.hpp"

#include "../../general.hpp"
#include "../../structs/vec.hpp"

vec2_u16_t am_touch_read(int touch_index, am_touch_controller_i* controller) {
    uint16_t x;
    uint16_t y;
    controller->read(0, &x, &y);
    return vec2_u16_t { x, y };
}

vec2_u16_t am_touch_read_0(am_touch_controller_i* controller) { 
    return am_touch_read(0, controller);
}

bool am_touch_wait_0(am_touch_controller_i* controller, vec2_u16_t* out_vec, bool* cancelation) {
    int count;
    while (cancelation == nullptr || *cancelation == false) {
        controller->count(&count);
        if (count > 0) {
            *out_vec = am_touch_read_0(controller);
            return true;
        }
        continue;
    }
    return false;
}