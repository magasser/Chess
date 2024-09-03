#include <engine/renderer.h>
#include <engine/components/button.h>
#include <engine/shapes/rectangle.h>
#include <engine/texture.h>

void render_layer(Renderer* renderer, Layer* layer);
void render_object(Renderer* renderer, RenderObject* object);

void render_component(Renderer* renderer, Component* component);
void render_button(Renderer* renderer, Button* button);

void render_shape(Renderer* renderer, Shape* shape);
void render_triangle(Renderer* renderer, Shape* triangle); // TODO
void render_rectangle(Renderer* renderer, Rectangle* rectangle);

void render_texture(Renderer* renderer, RenderTexture* texture);

void render_scene(Renderer* renderer, Scene* scene) {
    for (int32_t i = 0; i < scene->layers->count; i++) {
        render_layer(renderer, (Layer*)list_get(scene->layers, i));
    }
}

void render_layer(Renderer* renderer, Layer* layer) {
    for (int32_t i = 0; i < layer->objects->count; i++) {
        render_object(renderer, (RenderObject*)list_get(layer->objects, i));
    }
}

void render_object(Renderer* renderer, RenderObject* object) {
    if (object->disabled) {
        return;
    }

    switch (object->type) {
    case RENDER_OBJECT_COMPONENT:
        render_component(renderer, (Component*)object);
        break;
    case RENDER_OBJECT_SHAPE:
        render_shape(renderer, (Shape*)object);
        break;
    case RENDER_OBJECT_TEXTURE:
        render_texture(renderer, (RenderTexture*)object);
        break;
    }
}

void render_component(Renderer* renderer, Component* component) {
    switch (component->type) {
    case COMPONENT_BUTTON:
        render_button(renderer, (Button*)component);
        break;
    }
}

void render_shape(Renderer* renderer, Shape* shape) {
    switch (shape->type)
    {
    case SHAPE_TRIANGLE:
        // TODO
        break;
    case SHAPE_RECTANGLE:
        render_rectangle(renderer, (Rectangle*)shape);
        break;
    case SHAPE_LINE:
        // TODO
        break;
    case SHAPE_CIRCLE:
        // TODO
        break;
    }
}