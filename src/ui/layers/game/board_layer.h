#ifndef BOARD_LAYER_H
#define BOARD_LAYER_H

#include <engine/engine.h>

#include "core.h"
#include "board.h"

typedef struct {
    Layer layer;
    const Board* board;
} BoardLayer;

BoardLayer* create_board_layer(Renderer* renderer, Board* board);

#endif