#include <stdio.h>
#include <SDL2/SDL.h>

#include "piece.h"
#include "player.h"
#include "renderer.h"

#define SDL_ERROR(template) \
printf(template, SDL_GetError())

static Piece *heldPiece = NULL;

void on_window_event(SDL_WindowEvent *event);
void on_mouse_move(SDL_MouseMotionEvent *event);
void on_mouse_down(SDL_MouseButtonEvent *event);
void on_mouse_up(SDL_MouseButtonEvent *event);

void run() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_ERROR("Failed to initialize SDL Video with error: %s\n");
        exit(EXIT_FAILURE);
    }

    SDL_Window *window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_ERROR("Failed to create SDL Window with error: %s\n");
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        SDL_ERROR("Failed to create SDL Renderer with error: %s\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    uint32_t width, height;
    SDL_GetWindowSize(window, &width, &height);

    Board *board = create_board();

    SDL_Event event;
    while (SDL_WaitEvent(&event)) {

        switch (event.type) {
        case SDL_WINDOWEVENT:
            on_window_event(&event.window);
            break;

        case SDL_MOUSEMOTION:
            on_mouse_move(&event.motion);
            break;

        case SDL_MOUSEBUTTONDOWN:
            on_mouse_down(&event.button);
            break;

        case SDL_MOUSEBUTTONUP:
            on_mouse_up(&event.button);
            break;

        case SDL_QUIT:
            exit(EXIT_SUCCESS);
            break;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_board(window, board);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void on_window_event(SDL_WindowEvent *event) {
    switch (event->type) {
    case SDL_WINDOWEVENT_CLOSE:
        exit(EXIT_SUCCESS);
        break;
    }
}

void on_mouse_move(SDL_MouseMotionEvent *event) {
    if (heldPiece == NULL) {
        return;
    }

}

void on_mouse_down(SDL_MouseButtonEvent *event) {
    if (event->button == SDL_BUTTON_LEFT) {

    }
}

void on_mouse_up(SDL_MouseButtonEvent *event) {

}