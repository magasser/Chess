#ifndef GAME_H
#define GAME_H

#include "core.h"
#include "move.h"

typedef struct {

} MenuContext;

typedef struct GameContext {
    Board board;
    Move move;
    List* moves;
    void (*move_piece)(struct GameContext*, Move);
    PieceColor color_turn;
} GameContext;

typedef struct {
    MenuContext menu_context;
    GameContext game_context;
} Game;

void init_game(Game* game);

#endif