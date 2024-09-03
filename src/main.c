#include <stdio.h>

#include <engine/engine.h>

#include "core.h"
#include "game.h"
#include "ui/scenes/game_scene.h"


int main(void) {
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

    Game game;
    init_game(&game);

    Scene* scene = (Scene*)create_game_scene(renderer, &game);

    Event event;

    while (wait_event(&event)) {

        if (event.type == QUIT_EVENT) {
            break;
        }
        // TODO: Check if the loop needs to be reversed
        for (int32_t i = 0; i < scene->layers->count; i++) {
            Layer* layer = (Layer*)list_get(scene->layers, i);
            if (layer->handle_event(layer, &event)) {
                break;
            }
        }

        scene->update(scene);

        Color clear_color = { 50, 0, 0, 255 };
        render_begin(renderer, clear_color);
        render_scene(renderer, scene);
        render_end(renderer);
    }

    destroy_renderer(renderer);
    destory_window(window);
    ui_quit();

    return 0;
}
