#include "game.h"

#include "core.h"

#include "piece.h"
#include "player.h"

#define INIT_PIECE(l, i, k, c, f, r) \
PieceState state = *((PieceState*)list_get(l, i)); \
state.kind = k; \
state.color = c; \
state.file = f; \
state.rank = r

void init_game(Game* game) {
    init_board(&game->game_context.board);
}