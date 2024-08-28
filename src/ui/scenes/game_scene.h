#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <engine/engine.h>

#include "game.h"

typedef struct {
    Scene scene;
    const Game* game;
} GameScene;

GameScene* create_game_scene(Renderer* renderer, const Game* game);
void destroy_game_scene(GameScene* game_scene);

#endif