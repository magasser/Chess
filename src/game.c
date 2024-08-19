#include "game.h"

#include "core.h"

#include "piece.h"
#include "player.h"

GameContext* create_game() {
    return NULL;
}
void destroy_game(GameContext* context) {
    free(context);
}