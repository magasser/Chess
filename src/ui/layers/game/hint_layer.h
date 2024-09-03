#ifndef HINT_LAYER_H
#define HINT_LAYER_H

#include <engine/engine.h>

#include "game.h"

typedef struct {
    Layer layer;
    const GameContext* game;
    Renderer* renderer;
} HintLayer;

HintLayer* create_hint_layer(Renderer* renderer, const GameContext* game);

#endif