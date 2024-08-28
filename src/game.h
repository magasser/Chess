#ifndef GAME_H
#define GAME_H

#include "core.h"
#include "board.h"

typedef struct {

} MenuContext;

typedef struct {
    Board board;
} GameContext;

typedef struct {
    MenuContext menu_context;
    GameContext game_context;
} Game;

void init_game(Game* game);

#endif