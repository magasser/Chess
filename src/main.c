#include <stdio.h>

#include "game.h"

#include "UI/ui.h"
#include "UI/window.h"
#include "UI/renderer.h"


int main(int argc, char* argv[]) {
    if (ui_init() < 0) {
        char error[200];
        ui_get_error(error, 200);
        printf("Failed to initialize UI with error: %s\n", error);
        exit(EXIT_FAILURE);
    }

    Window* window = create_window("Chess", WINDOWPOS_CENTERED, WINDOWPOS_CENTERED, 1280, 720, WINDOW_FLAGS_SHOWN);

    if (!window) {
        char error[200];
        ui_get_error(error, 200);
        printf("Failed to create Window with error: %s\n", error);
        ui_quit();
        exit(EXIT_FAILURE);
    }

    Renderer* renderer = create_renderer(window);

    if (!renderer) {
        char error[200];
        ui_get_error(error, 200);
        printf("Failed to create Renderer with error: %s\n", error);
        destory_window(window);
        ui_quit();
        exit(EXIT_FAILURE);
    }

    GameContext* game = create_game();

    while (1) {
        printf("do it");
    }

    destroy_game(game);
    destroy_renderer(renderer);
    destory_window(window);
    ui_quit();

    return 0;
}
