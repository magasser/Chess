#include "board.h"

#include "core.h"

void init_piece(PieceState* piece, PieceKind kind, PieceColor color, uint8_t rank, uint8_t file);

Board* create_board() {
    Board* board = (Board*)malloc(sizeof(Board));

    board->pieces = (PieceState*)malloc(sizeof(PieceState) * BOARD_PIECE_COUNT);

    // Black pieces
    init_piece(&board->pieces[0], PIECE_KIND_ROOK, PIECE_COLOR_BLACK, 1, 1);
    init_piece(&board->pieces[1], PIECE_KIND_KNIGHT, PIECE_COLOR_BLACK, 2, 1);
    init_piece(&board->pieces[2], PIECE_KIND_BISHOP, PIECE_COLOR_BLACK, 3, 1);
    init_piece(&board->pieces[3], PIECE_KIND_QUEEN, PIECE_COLOR_BLACK, 4, 1);
    init_piece(&board->pieces[4], PIECE_KIND_KING, PIECE_COLOR_BLACK, 5, 1);
    init_piece(&board->pieces[5], PIECE_KIND_BISHOP, PIECE_COLOR_BLACK, 6, 1);
    init_piece(&board->pieces[6], PIECE_KIND_KNIGHT, PIECE_COLOR_BLACK, 7, 1);
    init_piece(&board->pieces[7], PIECE_KIND_ROOK, PIECE_COLOR_BLACK, 8, 1);
    init_piece(&board->pieces[8], PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 1, 2);
    init_piece(&board->pieces[9], PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 2, 2);
    init_piece(&board->pieces[10], PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 3, 2);
    init_piece(&board->pieces[11], PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 4, 2);
    init_piece(&board->pieces[12], PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 5, 2);
    init_piece(&board->pieces[13], PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 6, 2);
    init_piece(&board->pieces[14], PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 7, 2);
    init_piece(&board->pieces[15], PIECE_KIND_PAWN, PIECE_COLOR_BLACK, 8, 2);

    // White pieces
    init_piece(&board->pieces[16], PIECE_KIND_ROOK, PIECE_COLOR_WHITE, 1, 8);
    init_piece(&board->pieces[17], PIECE_KIND_KNIGHT, PIECE_COLOR_WHITE, 2, 8);
    init_piece(&board->pieces[18], PIECE_KIND_BISHOP, PIECE_COLOR_WHITE, 3, 8);
    init_piece(&board->pieces[19], PIECE_KIND_QUEEN, PIECE_COLOR_WHITE, 4, 8);
    init_piece(&board->pieces[20], PIECE_KIND_KING, PIECE_COLOR_WHITE, 5, 8);
    init_piece(&board->pieces[21], PIECE_KIND_BISHOP, PIECE_COLOR_WHITE, 6, 8);
    init_piece(&board->pieces[22], PIECE_KIND_KNIGHT, PIECE_COLOR_WHITE, 7, 8);
    init_piece(&board->pieces[23], PIECE_KIND_ROOK, PIECE_COLOR_WHITE, 8, 8);
    init_piece(&board->pieces[24], PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 1, 7);
    init_piece(&board->pieces[25], PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 2, 7);
    init_piece(&board->pieces[26], PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 3, 7);
    init_piece(&board->pieces[27], PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 4, 7);
    init_piece(&board->pieces[28], PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 5, 7);
    init_piece(&board->pieces[29], PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 6, 7);
    init_piece(&board->pieces[30], PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 7, 7);
    init_piece(&board->pieces[31], PIECE_KIND_PAWN, PIECE_COLOR_WHITE, 8, 7);

    return board;
}

void init_piece(PieceState* piece, PieceKind kind, PieceColor color, uint8_t rank, uint8_t file) {
    piece->piece.kind = kind;
    piece->piece.color = color;
    piece->rank = rank;
    piece->file = file;
    piece->isAlive = 1;
}

void free_board(Board* board) {
    free(board->pieces);
    free(board);
}