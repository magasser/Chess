#ifndef PIECE_H
#define PIECE_H

typedef enum {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
} PieceKind;

typedef enum {
    BLACK,
    WHITE
} PieceColor;

typedef struct {
    PieceKind kind;
    PieceColor color;
} Piece;

#endif