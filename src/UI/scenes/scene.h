#ifndef SCENE_H
#define SCENE_H

#include "UI/renderer.h"

typedef struct {
    Scene scene;
    Array* buttons;
} Scene;

void destroy_scene(Scene* scene) {
    destory_array(scene->buttons);
    free(scene);
}

void render_scene(Scene* scene, Renderer* renderer);

#endif