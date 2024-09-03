#ifndef SCENE_H
#define SCENE_H

#include <utils/list.h>

#include <engine/layer.h>

typedef struct Scene {
    List* layers;
    void (*update)(struct Scene*);
} Scene;

#endif