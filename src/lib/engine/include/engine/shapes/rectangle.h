#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <engine/shapes/shape.h>

typedef struct {
    Shape shape;
    uint32_t width;
    uint32_t height;
} Rectangle;

#endif