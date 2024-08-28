#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

#include <stdint.h>

typedef enum {
    RENDER_OBJECT_COMPONENT = 1,
    RENDER_OBJECT_SHAPE,
    RENDER_OBJECT_TEXTURE
} RenderObjectType;

typedef struct {
    RenderObjectType type;
    uint32_t x;
    uint32_t y;
    double angle;
} RenderObject;

#endif