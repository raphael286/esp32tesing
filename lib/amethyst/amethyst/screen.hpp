#ifndef AMETHYST_SCREEN_H
#define AMETHYST_SCREEN_H

#include "lvgl.h"
#include "TFT_eSPI.h"

lv_display_t* am_create_display(int width, int height, lv_color_t bg = lv_color_hex(0xFFFFFF));
void am_display_handler();

lv_obj_t* am_create_label(lv_obj_t* parent, char* text, 
    lv_align_t align = LV_ALIGN_CENTER, int x_offset = 0, int y_offset = 0);

#endif