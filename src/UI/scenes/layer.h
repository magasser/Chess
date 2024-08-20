#ifndef LAYER_H
#define LAYER_H

#include "core.h"
#include "UI/event.h"
#include "UI/render_object.h"

typedef struct {
    List* objects;
} Layer;

uint8_t layer_handle_event(Layer* layer, Event* event);

#endif