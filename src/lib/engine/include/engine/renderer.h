#ifndef RENDERER_H
#define RENDERER_H

#include <engine/window.h>
#include <engine/scene.h>
#include <engine/color.h>

typedef struct {
    Window* window;
    void* renderer;
} Renderer;

typedef struct {
    uint32_t x;
    uint32_t y;
    uint32_t width;
    uint32_t height;
    Color color;
} RenderRect;

Renderer* create_renderer(Window* window);
void destroy_renderer(Renderer* renderer);


void render_begin(Renderer* renderer, Color clear_color);
void render_end(Renderer* renderer);

void render_scene(Renderer* renderer, Scene* scene);

#endif
