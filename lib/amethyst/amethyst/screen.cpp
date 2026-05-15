#include "screen.hpp"
#include "general.hpp" 

lv_display_t* am_create_display(int width, int height, lv_color_t bg) {
    uint32_t buf[(width * height / 10 * (LV_COLOR_DEPTH / 8)) / 4];
    lv_display_t* display = lv_tft_espi_create(width, height, buf, sizeof(buf));
    
    lv_obj_set_style_bg_color(lv_screen_active(), bg, LV_PART_MAIN);
    return display;
}

void am_display_handler() {
    lv_task_handler();
    lv_tick_inc(5);
    am_quick_wait(5);
}

lv_obj_t* am_create_label(lv_obj_t* parent, char* text, lv_align_t align, int x_offset, int y_offset) {
    lv_obj_t* label = lv_label_create(parent);
    lv_label_set_text(label, text);
    lv_obj_align(label, align, x_offset, y_offset);
    return label;
}