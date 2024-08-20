#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

typedef enum {
    RENDER_OBJECT_COMPONENT = 1,
    RENDER_OBJECT_SHAPE
} RenderObjectType;

typedef struct {
    RenderObjectType type;
    uint32_t x;
    uint32_t y;
} RenderObject;

#endif