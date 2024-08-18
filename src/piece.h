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
    uint8_t rank;
    uint8_t file;
} Piece;

#endif