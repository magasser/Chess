#include "game_scene.h"

#include "ui/layers/background_layer.h"
#include "ui/layers/ui_layer.h"
#include "ui/layers/game/board_layer.h"
#include "ui/layers/game/hint_layer.h"
#include "ui/layers/game/piece_layer.h"

GameScene* create_game_scene(Renderer* renderer, const Game* game) {
    GameScene* game_scene = (GameScene*)malloc(sizeof(GameScene));

    game_scene->game = game;
    game_scene->scene.layers = list_create(4);

    list_add(game_scene->scene.layers, create_board_layer(renderer, &game->game_context.board));
    list_add(game_scene->scene.layers, create_piece_layer(renderer, &game->game_context.board));

    // TODO: Add other layers

    return game_scene;
}

void destroy_layer(void* layer) {
    free(layer);
}

void destroy_game_scene(GameScene* game_scene) {
    list_foreach(game_scene->scene.layers, destroy_layer);
    list_destroy(game_scene->scene.layers);
    free(game_scene);
}