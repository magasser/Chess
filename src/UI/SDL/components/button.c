#include "UI/components/button.h"

Button* create_button(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
    Button* button = (Button*)malloc(sizeof(Button));

    button->x = x;
    button->y = y;
    button->width = width;
    button->height = height;
    button->onClick = NULL;

    return button;
}
void destroy_button(Button* button) {
    free(button);
}

void on_click(Button* button, Action onClick);