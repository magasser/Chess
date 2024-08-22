#include <stdio.h>

#include "core.h"
#include "game.h"
#include <engine/engine.h>


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

    GameContext* game = create_game();

    Event event;
    // Test Scene
    Scene scene = { list_create(1) };
    Layer test = { list_create(2) };

    list_add(scene.layers, &test);

    Rectangle rect1 = { RENDER_OBJECT_SHAPE, 500, 500, SHAPE_RECTANGLE, {0, 255, 0, 255}, 50, 50 };
    Rectangle rect2 = { RENDER_OBJECT_SHAPE, 550, 500, SHAPE_RECTANGLE, {0, 0, 255, 255}, 50, 50 };

    list_add(test.objects, &rect1);
    list_add(test.objects, &rect2);

    while (wait_event(&event)) {

        // TODO: Check if the loop needs to be reversed
        for (int32_t i = 0; i < scene.layers->count; i++) {
            /*if (layer_handle_event((Layer*)scene.layers->items[i], &event)) {
                break;
            }*/
        }

        Color clear_color = { 50, 0, 0, 255 };
        render_begin(renderer, clear_color);
        render_scene(renderer, &scene);
        render_end(renderer);
    }

    destroy_game(game);
    destroy_renderer(renderer);
    destory_window(window);
    ui_quit();

    return 0;
}
