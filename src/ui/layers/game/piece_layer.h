#ifndef PIECE_LAYER_H
#define PIECE_LAYER_H

#include <engine/engine.h>

#include "core.h"
#include "board.h"

typedef struct {
    Layer layer;
    const Board* board;
} PieceLayer;

PieceLayer* create_piece_layer(Renderer* renderer, const Board* board);

#endif