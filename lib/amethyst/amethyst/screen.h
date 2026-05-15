#ifndef AMETHYST_SCREEN_H
#define AMETHYST_SCREEN_H

#include "lvgl.h"
#include "TFT_eSPI.h"

typedef struct {
    char* text;
    lv_align_t align;
    int x_offset;
    int y_offset;
} am_label_args_t;

lv_display_t* am_create_display(int width, int height);
void am_display_handler();

lv_obj_t* am_create_label(am_label_args_t args);

#endif