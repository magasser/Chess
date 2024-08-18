#include <stdint.h>
#include "piece.h"

typedef struct {
    Piece *pieces;
    uint8_t pieceCount;
} Board;

Board *create_board();

void free_board(Board *board);