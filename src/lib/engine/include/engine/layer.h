#ifndef LAYER_H
#define LAYER_H

#include <utils/list.h>

#include <engine/event.h>
#include <engine/render_object.h>

typedef struct {
    List* objects;
} Layer;

uint8_t layer_handle_event(Layer* layer, Event* event);

#endif