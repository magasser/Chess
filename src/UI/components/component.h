#ifndef COMPONENT_H
#define COMPONENT_H

#include "UI/render_object.h"

typedef enum {
    COMPONENT_BUTTON = 1,
    COMPONENT_TEXT_INPUT
} ComponentType;

typedef struct {
    RenderObject object;
    ComponentType type;
} Component;

#endif