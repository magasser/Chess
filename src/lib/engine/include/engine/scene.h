#ifndef SCENE_H
#define SCENE_H

#include <utils/list.h>

#include <engine/layer.h>

typedef struct {
    List* layers;
} Scene;

#endif