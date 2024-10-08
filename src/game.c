#include "game.h"

#include "core.h"

#include "piece.h"
#include "player.h"

static void game_move_piece(GameContext* context, Move move);
static void game_capture_piece(const GameContext* context, PieceState* piece);
static void game_promote_pawn(PieceState* pawn);

void init_game(Game* game) {
    init_board(&game->game_context.board);

    game->game_context.moves = list_create(0);
    game->game_context.move_piece = game_move_piece;
    game->game_context.color_turn = PIECE_COLOR_WHITE;

    game->game_context.move.piece = NULL;
    game->game_context.move.valid_moves = NULL;
    game->game_context.move.new_rank = 0;
    game->game_context.move.new_file = 0;
}

static void game_move_piece(GameContext* context, Move move) {
    PieceState* capturable = get_piece_on_square(&context->board, move.new_rank, move.new_file);

    if (!move_piece(&context->board, &move)) {
        return;
    }

    if (capturable) {
        game_capture_piece(context, capturable);
    }

    Move* m = (Move*)malloc(sizeof(Move));
    *m = move;

    list_add(context->moves, m);

    context->color_turn = context->color_turn == PIECE_COLOR_WHITE ? PIECE_COLOR_BLACK : PIECE_COLOR_WHITE;
}

static void game_capture_piece(const GameContext* context, PieceState* piece) {
    piece->is_alive = 0;
}