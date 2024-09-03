#include <engine/window.h>

#include <stdio.h>
#include <SDL2/SDL.h>

#define GET_SDL_WINDOWPOS(x) (x) == WINDOWPOS_UNDEFINED ? SDL_WINDOWPOS_UNDEFINED : (x) == WINDOWPOS_CENTERED ? SDL_WINDOWPOS_CENTERED : (x)
#define GET_SDL_WINDOW_FLAG(flags, flag, sdl_flag) ((flags) & (flag)) != 0 ? (sdl_flag) : 0

void on_window_create(Window* window);
void on_window_destroy(Window* window);

Window* create_window(const char* title, uint32_t x, uint32_t y, uint32_t width, uint32_t height, WindowFlags flags) {
    Window* window = (Window*)malloc(sizeof(Window));

    x = GET_SDL_WINDOWPOS(x);
    y = GET_SDL_WINDOWPOS(y);

    SDL_WindowFlags window_flags = 0;
    window_flags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_FULLSCREEN, SDL_WINDOW_FULLSCREEN));
    window_flags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_SHOWN, SDL_WINDOW_SHOWN));
    window_flags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_HIDDEN, SDL_WINDOW_HIDDEN));
    window_flags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_RESIZEABLE, SDL_WINDOW_RESIZABLE));
    window_flags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_MINIMIZED, SDL_WINDOW_MINIMIZED));
    window_flags |= (GET_SDL_WINDOW_FLAG(flags, WINDOW_FLAGS_MAXIMIZED, SDL_WINDOW_MAXIMIZED));

    uint32_t t = SDL_WINDOWPOS_CENTERED;

    window->window = SDL_CreateWindow(title, x, y, width, height, window_flags);

    if (!window->window) {
        free(window);
        return NULL;
    }

    window->id = SDL_GetWindowID(window->window);

    on_window_create(window);

    return window;
}

void destory_window(Window* window) {
    on_window_destroy(window);

    SDL_DestroyWindow(window->window);
    free(window);
}

void get_window_size(const Window* window, uint32_t* width, uint32_t* height) {
    SDL_GetWindowSize(window->window, width, height);
}