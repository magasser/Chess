#ifndef PIECE_LAYER_H
#define PIECE_LAYER_H

#include <engine/engine.h>

#include "core.h"
#include "game.h"

typedef struct {
    Layer layer;
    GameContext* game;
} PieceLayer;

PieceLayer* create_piece_layer(Renderer* renderer, GameContext* board);

#endif