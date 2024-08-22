#include <engine/renderer.h>
#include <engine/color.h>
#include <engine/shapes/rectangle.h>
#include <engine/components/button.h>

#include <SDL2/SDL.h>
#include <SDL_image.h>

#define TILE_SIZE 60

Renderer* create_renderer(Window* window) {
    Renderer* renderer = (Renderer*)malloc(sizeof(Renderer));

    renderer->window = window;
    renderer->renderer = SDL_CreateRenderer(renderer->window->window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer->renderer) {
        free(renderer);
        return NULL;
    }

    return renderer;
}

void destroy_renderer(Renderer* renderer) {
    SDL_DestroyRenderer(renderer->renderer);
    free(renderer);
}

void render_begin(Renderer* renderer, Color clear_color) {
    SDL_SetRenderDrawColor(renderer->renderer, clear_color.r, clear_color.g, clear_color.b, clear_color.a);
    SDL_RenderClear(renderer->renderer);
}

void render_end(Renderer* renderer) {
    SDL_RenderPresent(renderer->renderer);
}

void render_button(Renderer* renderer, Button* object) {

}

void render_rectangle(Renderer* renderer, Rectangle* rectangle) {
    SDL_Rect rect = { rectangle->shape.object.x, rectangle->shape.object.y, rectangle->width, rectangle->height };

    SDL_SetRenderDrawColor(renderer->renderer, rectangle->shape.color.r, rectangle->shape.color.g, rectangle->shape.color.b, rectangle->shape.color.a);
    SDL_RenderFillRect(renderer->renderer, &rect);
}