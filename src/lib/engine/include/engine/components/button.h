#ifndef BUTTON_H
#define BUTTON_H

#include <utils/action.h>

#include <engine/color.h>
#include <engine/components/component.h>

typedef struct {
    Component component;
    uint32_t width;
    uint32_t height;
    Color color;
    Action onClick;
} Button;

Button* create_button(uint32_t x, uint32_t y, uint32_t width, uint32_t height, Color color);
void destroy_button(Button* button);

void on_click(Button* button, Action onClick);

#endif