#include "move.h"

typedef struct {
    int32_t x;
    int32_t y;
} Vector;

static List* get_direction_moves(const Board* board, PieceState* piece, uint8_t dir_x, uint8_t dir_y, uint8_t iterations);

List* get_pawn_moves(const Board* board, PieceState* piece);
List* get_knight_moves(const Board* board, PieceState* piece);
List* get_bishop_moves(const Board* board, PieceState* piece);
List* get_rook_moves(const Board* board, PieceState* piece);
List* get_queen_moves(const Board* board, PieceState* piece);
List* get_king_moves(const Board* board, PieceState* piece);

static Move* create_move(PieceState* piece, uint8_t rank, uint8_t file) {
    Move* move = (Move*)malloc(sizeof(Move));
    move->piece = piece;
    move->new_rank = rank;
    move->new_file = file;
    move->valid_moves = NULL;
}

static void destroy_move(Move* move) {
    free(move);
}

void reset_move(Move* move) {
    move->piece = NULL;
    move->new_rank = 0;
    move->new_file = 0;

    if (move->valid_moves) {
        list_foreach(move->valid_moves, (void(*)(void*))destroy_move);
        list_destroy(move->valid_moves);
    }

    move->valid_moves = NULL;
}

uint8_t is_valid_move(const Board* board, const Move* move) {
    List* moves = move->valid_moves;

    if (moves == NULL) {
        return 0;
    }

    uint8_t is_valid = 0;
    for (int32_t i = 0; i < moves->count; i++) {
        Move* m = (Move*)moves->items[i];
        if (m->piece == move->piece && m->new_rank == move->new_rank && m->new_file == move->new_file) {
            is_valid = 1;
        }
    }

    return is_valid;
}

List* get_valid_moves(const Board* board, PieceState* piece) {
    switch (piece->piece.kind)
    {
    case PIECE_KIND_PAWN:
        return get_pawn_moves(board, piece);
    case PIECE_KIND_KNIGHT:
        return get_knight_moves(board, piece);
    case PIECE_KIND_BISHOP:
        return get_bishop_moves(board, piece);
    case PIECE_KIND_ROOK:
        return get_rook_moves(board, piece);
    case PIECE_KIND_QUEEN:
        return get_queen_moves(board, piece);
    case PIECE_KIND_KING:
        return get_king_moves(board, piece);

    default:
        return list_create(0);
    }
}

uint8_t move_piece(Board* board, const Move* move) {
    if (!is_valid_move(board, move)) {
        return 0;
    }

    move->piece->rank = move->new_rank;
    move->piece->file = move->new_file;

    return 1;
}

List* get_pawn_moves(const Board* board, PieceState* piece) {
    int8_t direction = piece->piece.color == PIECE_COLOR_WHITE ? 1 : -1;
    PieceColor other_color = piece->piece.color == PIECE_COLOR_WHITE ? PIECE_COLOR_BLACK : PIECE_COLOR_WHITE;

    List* moves = list_create(1);

    if (piece->rank == BOARD_SIZE || piece->rank == 0) {
        return moves;
    }

    // Forward Movement
    if (!has_piece_on_square(board, piece->rank + direction, piece->file)) {
        list_add(moves, create_move(piece, piece->rank + direction, piece->file));

        if (direction == 1 && piece->rank == 2 || direction == -1 && piece->rank == 7) {
            list_add(moves, create_move(piece, piece->rank + direction * 2, piece->file));
        }
    }

    // Capturing
    if (piece->file != 1 && has_piece_color_on_square(board, piece->rank + direction, piece->file - 1, other_color)) {
        list_add(moves, create_move(piece, piece->rank + direction, piece->file - 1));
    }

    if (piece->file != BOARD_SIZE && has_piece_color_on_square(board, piece->rank + direction, piece->file + 1, other_color)) {
        list_add(moves, create_move(piece, piece->rank + direction, piece->file + 1));
    }

    // En Passant
    // TODO

    return moves;
}

List* get_knight_moves(const Board* board, PieceState* piece) {
    static Vector directions[8] = {
        { 1,  2},
        { 2,  1},
        { 2, -1},
        { 1, -2},
        {-1, -2},
        {-2, -1},
        {-2,  1},
        {-1,  2},
    };

    // TODO: Move common code to function
    List* moves = list_create(0);

    for (uint8_t i = 0; i < 8; i++) {
        List* directional_moves = get_direction_moves(board, piece, directions[i].x, directions[i].y, 1);
        list_add_range(moves, directional_moves);
        list_destroy(directional_moves);
    }

    return moves;
}

List* get_bishop_moves(const Board* board, PieceState* piece) {
    static Vector directions[4] = {
        { 1,  1},
        {-1, -1},
        {-1,  1},
        { 1, -1}
    };

    List* moves = list_create(0);

    for (uint8_t i = 0; i < 4; i++) {
        List* directional_moves = get_direction_moves(board, piece, directions[i].x, directions[i].y, BOARD_SIZE - 1);
        list_add_range(moves, directional_moves);
        list_destroy(directional_moves);
    }

    return moves;
}

List* get_rook_moves(const Board* board, PieceState* piece) {
    static Vector directions[4] = {
        { 1,  0},
        {-1,  0},
        { 0,  1},
        { 0, -1}
    };

    List* moves = list_create(0);

    for (uint8_t i = 0; i < 4; i++) {
        List* directional_moves = get_direction_moves(board, piece, directions[i].x, directions[i].y, BOARD_SIZE - 1);
        list_add_range(moves, directional_moves);
        list_destroy(directional_moves);
    }

    return moves;
}

List* get_queen_moves(const Board* board, PieceState* piece) {
    static Vector directions[8] = {
        { 1,  1},
        {-1, -1},
        {-1,  1},
        { 1, -1},
        { 1,  0},
        {-1,  0},
        { 0,  1},
        { 0, -1}
    };

    List* moves = list_create(0);

    for (uint8_t i = 0; i < 8; i++) {
        List* directional_moves = get_direction_moves(board, piece, directions[i].x, directions[i].y, BOARD_SIZE - 1);
        list_add_range(moves, directional_moves);
        list_destroy(directional_moves);
    }

    return moves;
}

List* get_king_moves(const Board* board, PieceState* piece) {
    static Vector directions[8] = {
        { 1,  1},
        {-1, -1},
        {-1,  1},
        { 1, -1},
        { 1,  0},
        {-1,  0},
        { 0,  1},
        { 0, -1}
    };

    List* moves = list_create(0);

    for (uint8_t i = 0; i < 8; i++) {
        List* directional_moves = get_direction_moves(board, piece, directions[i].x, directions[i].y, 1);
        list_add_range(moves, directional_moves);
        list_destroy(directional_moves);
    }

    // TODO: Castling

    return moves;
}

static List* get_direction_moves(const Board* board, PieceState* piece, uint8_t dir_x, uint8_t dir_y, uint8_t iterations) {
    uint8_t x = piece->file + dir_x;
    uint8_t y = piece->rank + dir_y;

    List* moves = list_create(0);

    for (uint8_t i = 0;
        i < iterations
        && NUM_IN_RANGE(x, -BOARD_SIZE, BOARD_SIZE)
        && NUM_IN_RANGE(y, -BOARD_SIZE, BOARD_SIZE)
        && NUM_IN_RANGE(x, 1, BOARD_SIZE)
        && NUM_IN_RANGE(y, 1, BOARD_SIZE);
        i++) {
        PieceState* other_piece = get_piece_on_square(board, y, x);

        if (other_piece && other_piece->piece.color == piece->piece.color) {
            return moves;
        }

        if (other_piece) {
            list_add(moves, create_move(piece, y, x));
            return moves;
        }

        list_add(moves, create_move(piece, y, x));

        x += dir_x;
        y += dir_y;
    }

    return moves;
}
