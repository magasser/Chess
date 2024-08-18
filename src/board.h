#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>
#include "piece.h"

#define BOARD_PIECE_COUNT 32

typedef struct {
    Piece piece;
    uint8_t rank;
    uint8_t file;
    uint8_t isAlive;
} PieceState;

typedef struct {
    PieceState *pieces;
} Board;

Board *create_board();

void free_board(Board *board);

#endif