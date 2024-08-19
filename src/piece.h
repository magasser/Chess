#ifndef PIECE_H
#define PIECE_H

typedef enum {
    PIECE_KIND_PAWN,
    PIECE_KIND_KNIGHT,
    PIECE_KIND_BISHOP,
    PIECE_KIND_ROOK,
    PIECE_KIND_QUEEN,
    PIECE_KIND_KING
} PieceKind;

typedef enum {
    PIECE_COLOR_BLACK,
    PIECE_COLOR_WHITE
} PieceColor;

typedef struct {
    PieceKind kind;
    PieceColor color;
} Piece;

#endif