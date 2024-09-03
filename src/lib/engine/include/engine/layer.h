#ifndef LAYER_H
#define LAYER_H

#include <utils/list.h>

#include <engine/event.h>
#include <engine/render_object.h>

typedef struct Layer {
    List* objects;
    uint8_t(*handle_event)(struct Layer*, Event*);
    void(*update)(struct Layer*);
} Layer;

static uint8_t layer_handle_event_nop(Layer* layer, Event* event) {
    return 0;
}

static void layer_update_nop(Layer* layer) {
    return;
}

#endif