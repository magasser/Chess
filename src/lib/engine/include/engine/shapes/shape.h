#ifndef SHAPE_H
#define SHAPE_H

#include <engine/color.h>
#include <engine/render_object.h>

typedef enum {
    SHAPE_TRIANGLE = 1,
    SHAPE_RECTANGLE = 2,
    SHAPE_LINE = 3,
    SHAPE_CIRCLE = 4
} ShapeType;

typedef struct {
    RenderObject object;
    ShapeType type;
    Color color;
} Shape;

#endif