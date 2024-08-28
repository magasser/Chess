#ifndef TEXTURE_H
#define TEXTURE_H

#include <engine/renderer.h>
#include <engine/geometry/point.h>
#include <engine/render_object.h>

typedef struct {
    void* texture;
} Texture;

typedef struct {
    RenderObject object;
    Texture* texture;
    uint32_t width;
    uint32_t height;
    Point location;
} RenderTexture;

Texture* load_texture_from_svg(Renderer* renderer, const char* file, uint32_t width, uint32_t height);

#endif