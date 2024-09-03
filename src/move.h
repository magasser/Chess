#ifndef MOVE_H
#define MOVE_H

#include <utils/list.h>

#include "board.h"

typedef struct {
    PieceState* piece;
    List* valid_moves;
    uint8_t new_rank;
    uint8_t new_file;
} Move;

void reset_move(Move* move);

uint8_t is_valid_move(const Board* board, const Move* move);
List* get_valid_moves(const Board* board, PieceState* piece);

uint8_t move_piece(Board* board, const Move* move);

#endif