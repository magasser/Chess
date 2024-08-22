#include <engine/components/button.h>

#include <stdlib.h>

Button* create_button(uint32_t x, uint32_t y, uint32_t width, uint32_t height, Color color) {
    Button* button = (Button*)malloc(sizeof(Button));

    button->component.object.type = RENDER_OBJECT_COMPONENT;
    button->component.type = COMPONENT_BUTTON;
    button->component.object.x = x;
    button->component.object.y = y;
    button->width = width;
    button->height = height;
    button->color = color;
    button->onClick = NULL;

    return button;
}
void destroy_button(Button* button) {
    free(button);
}

void on_click(Button* button, Action onClick);