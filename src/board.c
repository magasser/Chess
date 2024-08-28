#include "board.h"

#define INIT_PIECE(l, i, k, c, f, r) \
PieceState* state##i = (PieceState*)list_get(l, i); \
state##i->piece.kind = k; \
state##i->piece.color = c; \
state##i->file = f; \
state##i->rank = r; \
state##i->is_alive = 1

void init_board(Board* board) {
    board->file_count = BOARD_SIZE;
    board->rank_count = BOARD_SIZE;
    board->piece_states = list_create(BOARD_PIECE_COUNT);

    PieceState* states = (PieceState*)calloc(BOARD_PIECE_COUNT, sizeof(PieceState));

    for (int32_t i = 0; i < BOARD_PIECE_COUNT; i++) {
        list_add(board->piece_states, &states[i]);
    }

    INIT_PIECE(board->piece_states, 0, PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 2, 1);
    INIT_PIECE(board->piece_states, 1, PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 2, 2);
    INIT_PIECE(board->piece_states, 2, PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 2, 3);
    INIT_PIECE(board->piece_states, 3, PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 2, 4);
    INIT_PIECE(board->piece_states, 4, PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 2, 5);
    INIT_PIECE(board->piece_states, 5, PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 2, 6);
    INIT_PIECE(board->piece_states, 6, PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 2, 7);
    INIT_PIECE(board->piece_states, 7, PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 2, 8);

    INIT_PIECE(board->piece_states, 8, PIECE_KIND_ROOK, PIECE_COLOR_BLACK, 1, 1);
    INIT_PIECE(board->piece_states, 9, PIECE_KIND_KNIGHT, PIECE_COLOR_BLACK, 1, 2);
    INIT_PIECE(board->piece_states, 10, PIECE_KIND_BISHOP, PIECE_COLOR_BLACK, 1, 3);
    INIT_PIECE(board->piece_states, 11, PIECE_KIND_QUEEN, PIECE_COLOR_BLACK, 1, 4);
    INIT_PIECE(board->piece_states, 12, PIECE_KIND_KING, PIECE_COLOR_BLACK, 1, 5);
    INIT_PIECE(board->piece_states, 13, PIECE_KIND_BISHOP, PIECE_COLOR_BLACK, 1, 6);
    INIT_PIECE(board->piece_states, 14, PIECE_KIND_KNIGHT, PIECE_COLOR_BLACK, 1, 7);

    INIT_PIECE(board->piece_states, 15, PIECE_KIND_ROOK, PIECE_COLOR_BLACK, 1, 8);
    INIT_PIECE(board->piece_states, 16, PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 7, 1);
    INIT_PIECE(board->piece_states, 17, PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 7, 2);
    INIT_PIECE(board->piece_states, 18, PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 7, 3);
    INIT_PIECE(board->piece_states, 19, PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 7, 4);
    INIT_PIECE(board->piece_states, 20, PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 7, 5);
    INIT_PIECE(board->piece_states, 21, PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 7, 6);
    INIT_PIECE(board->piece_states, 22, PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 7, 7);
    INIT_PIECE(board->piece_states, 23, PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 7, 8);

    INIT_PIECE(board->piece_states, 24, PIECE_KIND_ROOK, PIECE_COLOR_WHITE, 8, 1);
    INIT_PIECE(board->piece_states, 25, PIECE_KIND_KNIGHT, PIECE_COLOR_WHITE, 8, 2);
    INIT_PIECE(board->piece_states, 26, PIECE_KIND_BISHOP, PIECE_COLOR_WHITE, 8, 3);
    INIT_PIECE(board->piece_states, 27, PIECE_KIND_QUEEN, PIECE_COLOR_WHITE, 8, 4);
    INIT_PIECE(board->piece_states, 28, PIECE_KIND_KING, PIECE_COLOR_WHITE, 8, 5);
    INIT_PIECE(board->piece_states, 29, PIECE_KIND_BISHOP, PIECE_COLOR_WHITE, 8, 6);
    INIT_PIECE(board->piece_states, 30, PIECE_KIND_KNIGHT, PIECE_COLOR_WHITE, 8, 7);
    INIT_PIECE(board->piece_states, 31, PIECE_KIND_ROOK, PIECE_COLOR_WHITE, 8, 8);
}