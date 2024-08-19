#ifndef RENDERER_H
#define RENDERER_H

#include "window.h"

typedef struct {
    Window* window;
    void* renderer;
} Renderer;

Renderer* create_renderer(Window* window);
void destroy_renderer(Renderer* renderer);

#endif
