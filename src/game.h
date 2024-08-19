#ifndef GAME_H
#define GAME_H

#include "board.h"

typedef enum {
    GAME_SCENE_MENU,
    GAME_SCENE_CHESS
} GameScene;

typedef struct {

} MenuContext;

typedef struct {
    Board board;
} ChessContext;

typedef struct {
    GameScene scene;
    MenuContext menu_context;
    ChessContext chess_context;
} GameContext;

GameContext* create_game();
void destroy_game(GameContext* context);

#endif