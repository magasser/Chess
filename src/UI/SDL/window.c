#include "UI/window.h"

#include <stdio.h>
#include <SDL2/SDL.h>

#define GET_SDL_WINDOWPOS(x) (x) == WINDOWPOS_UNDEFINED ? SDL_WINDOWPOS_UNDEFINED : (x) == WINDOWPOS_CENTERED ? SDL_WINDOWPOS_CENTERED : (x)
#define GET_SDL_WINDOW_FLAG(flags, flag, sdlFlag) ((flags) & (flag)) != 0 ? (sdlFlag) : 0

Window* create_window(const char* title, uint32_t x, uint32_t y, uint32_t width, uint32_t height, WindowFlags flags) {
    Window* window = (Window*)malloc(sizeof(Window));

    x = GET_SDL_WINDOWPOS(x);
    y = GET_SDL_WINDOWPOS(y);

    SDL_WindowFlags windowFlags = 0;
    windowFlags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_FULLSCREEN, SDL_WINDOW_FULLSCREEN));
    windowFlags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_SHOWN, SDL_WINDOW_SHOWN));
    windowFlags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_HIDDEN, SDL_WINDOW_HIDDEN));
    windowFlags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_RESIZEABLE, SDL_WINDOW_RESIZABLE));
    windowFlags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_MINIMIZED, SDL_WINDOW_MINIMIZED));
    windowFlags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_MAXIMIZED, SDL_WINDOW_MAXIMIZED));

    window->window = SDL_CreateWindow(title, x, y, width, height, windowFlags);

    if (!window->window) {
        free(window);
        return NULL;
    }
}

void destory_window(Window* window) {
    SDL_DestroyWindow(window->window);
    free(window);
}