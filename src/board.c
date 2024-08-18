#include "board.h"

#include "core.h"

void init_piece(PieceState *piece, PieceKind kind, PieceColor color, uint8_t rank, uint8_t file);

Board *create_board() {
    Board *board = (Board *)malloc(sizeof(Board));

    board->pieces = (PieceState *)malloc(sizeof(PieceState) * BOARD_PIECE_COUNT);

    // Black pieces
    init_piece(&board->pieces[0], ROOK, BLACK, 1, 1);
    init_piece(&board->pieces[1], KNIGHT, BLACK, 2, 1);
    init_piece(&board->pieces[2], BISHOP, BLACK, 3, 1);
    init_piece(&board->pieces[3], QUEEN, BLACK, 4, 1);
    init_piece(&board->pieces[4], KING, BLACK, 5, 1);
    init_piece(&board->pieces[5], BISHOP, BLACK, 6, 1);
    init_piece(&board->pieces[6], KNIGHT, BLACK, 7, 1);
    init_piece(&board->pieces[7], ROOK, BLACK, 8, 1);
    init_piece(&board->pieces[8], PAWN, BLACK, 1, 2);
    init_piece(&board->pieces[9], PAWN, BLACK, 2, 2);
    init_piece(&board->pieces[10], PAWN, BLACK, 3, 2);
    init_piece(&board->pieces[11], PAWN, BLACK, 4, 2);
    init_piece(&board->pieces[12], PAWN, BLACK, 5, 2);
    init_piece(&board->pieces[13], PAWN, BLACK, 6, 2);
    init_piece(&board->pieces[14], PAWN, BLACK, 7, 2);
    init_piece(&board->pieces[15], PAWN, BLACK, 8, 2);

    // White pieces
    init_piece(&board->pieces[16], ROOK, WHITE, 1, 8);
    init_piece(&board->pieces[17], KNIGHT, WHITE, 2, 8);
    init_piece(&board->pieces[18], BISHOP, WHITE, 3, 8);
    init_piece(&board->pieces[19], QUEEN, WHITE, 4, 8);
    init_piece(&board->pieces[20], KING, WHITE, 5, 8);
    init_piece(&board->pieces[21], BISHOP, WHITE, 6, 8);
    init_piece(&board->pieces[22], KNIGHT, WHITE, 7, 8);
    init_piece(&board->pieces[23], ROOK, WHITE, 8, 8);
    init_piece(&board->pieces[24], PAWN, WHITE, 1, 7);
    init_piece(&board->pieces[25], PAWN, WHITE, 2, 7);
    init_piece(&board->pieces[26], PAWN, WHITE, 3, 7);
    init_piece(&board->pieces[27], PAWN, WHITE, 4, 7);
    init_piece(&board->pieces[28], PAWN, WHITE, 5, 7);
    init_piece(&board->pieces[29], PAWN, WHITE, 6, 7);
    init_piece(&board->pieces[30], PAWN, WHITE, 7, 7);
    init_piece(&board->pieces[31], PAWN, WHITE, 8, 7);

    return board;
}

void init_piece(PieceState *piece, PieceKind kind, PieceColor color, uint8_t rank, uint8_t file) {
    piece->piece.kind = kind;
    piece->piece.color = color;
    piece->rank = rank;
    piece->file = file;
    piece->isAlive = 1;
}

void free_board(Board *board) {
    free(board->pieces);
    free(board);
}