#include "UI/scenes/scene.h"
#include "UI/components/button.h"

void render_scene(Scene* scene, Renderer* renderer) {
    for (uint32_t i = 0; i < scene->buttons->length; i++) {
        Button* button = (Button*)(&scene->buttons->items[i]);
    }
}