#include "screen.h"
#include "general.h"

lv_display_t* am_create_display(int width, int height) {
    lv_init();
    lv_color_t* buf[width * height / 10];
    return lv_tft_espi_create(width, height, buf, sizeof(buf));
}

void am_display_handler() {
    lv_timer_handler();
    am_wait(5);
}

lv_obj_t* am_create_label(am_label_args_t args) {
    lv_obj_t* label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, args.text);
    lv_obj_align(label, USEOR(args.align, LV_ALIGN_CENTER), USEOR(args.x_offset, 00), USEOR(args.y_offset, 0));
    return label;
}