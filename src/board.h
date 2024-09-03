#ifndef BOARD_H
#define BOARD_H

#include "core.h"
#include "piece.h"

#define BOARD_SIZE 8
#define BOARD_PIECE_COUNT 32

typedef struct {
    uint8_t file;
    uint8_t rank;
} Square;

// TODO: Rework to use square
typedef struct {
    Piece piece;
    uint8_t file;
    uint8_t rank;
    uint8_t is_alive;
} PieceState;

typedef struct {
    List* piece_states;
    uint32_t rank_count;
    uint32_t file_count;
} Board;

void init_board(Board* board);

PieceState* get_piece_on_square(const Board* board, uint8_t rank, uint8_t file);
uint8_t has_piece_on_square(const Board* board, uint8_t rank, uint8_t file);
uint8_t has_piece_color_on_square(const Board* board, uint8_t rank, uint8_t file, PieceColor color);

#endif