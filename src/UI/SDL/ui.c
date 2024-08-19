#include "UI/ui.h"

#include <SDL2/SDL.h>

uint32_t ui_init() {
    return SDL_Init(SDL_INIT_VIDEO);
}

void ui_quit() {
    SDL_Quit();
}

void ui_get_error(char* buffer, uint32_t max_length) {
    SDL_GetErrorMsg(buffer, max_length);
}