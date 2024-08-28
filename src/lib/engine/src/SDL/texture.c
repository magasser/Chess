#include <engine/texture.h>

#include <SDL2/SDL.h>
#include <SDL_image.h>

Texture* load_texture_from_svg(Renderer* renderer, const char* file, uint32_t width, uint32_t height) {

    SDL_RWops* rw = SDL_RWFromFile(file, "r");

    SDL_Surface* surface = IMG_LoadSizedSVG_RW(rw, width, height);
    SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface(renderer->renderer, surface);

    SDL_FreeSurface(surface);
    SDL_FreeRW(rw);

    Texture* texture = (Texture*)malloc(sizeof(Texture));
    texture->texture = sdl_texture;

    return texture;
}