#ifndef AMETHYST_TOUCH_H
#define AMETHYST_TOUCH_H

#include "stdint.h"
#include "../structs/vec.hpp"

typedef struct {
    void (*read)(int touch_index, uint16_t* out_x, uint16_t* out_y);
    void (*count)();
} am_touch_controller_i;

vec2_u16_t am_touch_read(int touch_index, am_touch_controller_i* controller);

#endif