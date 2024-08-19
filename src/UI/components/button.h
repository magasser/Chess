#ifndef BUTTON_H
#define BUTTON_H

#include "core.h"

typedef struct {
    uint32_t x, y, width, height;
    Action onClick;
} Button;

Button* create_button(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
void destroy_button(Button* button);

void on_click(Button* button, Action onClick);

#endif