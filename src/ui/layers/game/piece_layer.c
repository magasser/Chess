#include "ui/layers/game/piece_layer.h"

#include <engine/engine.h>

#define PIECE_SIZE 60

static Point get_atlas_piece_location(PieceKind kind, PieceColor color);
static uint8_t get_square_from_point(const PieceLayer* layer, const Window* window, int32_t x, int32_t y, uint8_t* rank, uint8_t* file);
static uint8_t get_point_from_square(const PieceLayer* layer, const Window* window, uint8_t rank, uint8_t file, int32_t* x, int32_t* y);
static void set_moving_piece_location(PieceLayer* layer, const PieceState* piece, int32_t x, int32_t y);

static uint8_t piece_layer_handle_event(Layer* layer, Event* event);
static void piece_layer_update(PieceLayer* piece_layer);

PieceLayer* create_piece_layer(Renderer* renderer, GameContext* game) {
    PieceLayer* piece_layer = (PieceLayer*)malloc(sizeof(PieceLayer));

    piece_layer->layer.objects = list_create(32);
    piece_layer->game = game;
    piece_layer->layer.handle_event = piece_layer_handle_event;
    piece_layer->layer.update = (void(*)(Layer*))piece_layer_update;

    uint32_t width, height;
    get_window_size(renderer->window, &width, &height);

    Board board = game->board;

    Point top_left = {
        .x = (width / 2) - (board.file_count / 2) * PIECE_SIZE,
        .y = (height / 2) - (board.rank_count / 2) * PIECE_SIZE
    };

    // TODO: Find a way to handle asset paths
    Texture* atlas_texture = load_texture_from_svg(renderer, "resources/assets/pieces/piece_atlas.svg", PIECE_SIZE * 6, PIECE_SIZE * 2);

    for (uint32_t i = 0; i < board.piece_states->count; i++) {
        PieceState* state = (PieceState*)board.piece_states->items[i];
        RenderTexture* texture = (RenderTexture*)malloc(sizeof(RenderTexture));
        texture->object.type = RENDER_OBJECT_TEXTURE;
        texture->object.angle = 0.0;
        texture->object.x = top_left.x + PIECE_SIZE * (state->file - 1);
        texture->object.y = top_left.y + PIECE_SIZE * (state->rank - 1);
        texture->texture = atlas_texture;
        texture->location = get_atlas_piece_location(state->piece.kind, state->piece.color);
        texture->width = PIECE_SIZE;
        texture->height = PIECE_SIZE;

        list_add(piece_layer->layer.objects, texture);
    }

    return piece_layer;
}

static void piece_layer_update(PieceLayer* piece_layer) {
    for (int32_t i = 0; i < piece_layer->game->board.piece_states->count; i++) {
        PieceState* piece = (PieceState*)list_get(piece_layer->game->board.piece_states, i);
        RenderTexture* piece_texture = (RenderTexture*)list_get(piece_layer->layer.objects, i);
        piece_texture->object.disabled = !piece->is_alive;
    }
}

static Point get_atlas_piece_location(PieceKind kind, PieceColor color) {
    int32_t y = color == PIECE_COLOR_BLACK ? PIECE_SIZE : 0;

    switch (kind) {
    case PIECE_KIND_KING:
        return (Point) { PIECE_SIZE * 0, y };
    case PIECE_KIND_QUEEN:
        return (Point) { PIECE_SIZE * 1, y };
    case PIECE_KIND_BISHOP:
        return (Point) { PIECE_SIZE * 2, y };
    case PIECE_KIND_KNIGHT:
        return (Point) { PIECE_SIZE * 3, y };
    case PIECE_KIND_ROOK:
        return (Point) { PIECE_SIZE * 4, y };
    case PIECE_KIND_PAWN:
        return (Point) { PIECE_SIZE * 5, y };
    }
}

static uint8_t piece_layer_handle_event(Layer* layer, Event* event) {
    PieceLayer* piece_layer = (PieceLayer*)layer;

    switch (event->type) {
    case MOUSE_BUTTON_DOWN_EVENT:
        if (event->mouse_button.button != MOUSE_BUTTON_LEFT) {
            return 0;
        }

        uint8_t rank, file;
        if (!get_square_from_point(piece_layer, get_window_from_id(event->mouse_button.window_id), event->mouse_button.x, event->mouse_button.y, &rank, &file)) {
            return 0;
        }

        PieceState* piece = get_piece_on_square(&piece_layer->game->board, rank, file);

        if (!piece) {
            return 0;
        }

        if (piece->piece.color != piece_layer->game->color_turn) {
            return 1;
        }

        Move* move = &piece_layer->game->move;

        move->piece = piece;
        move->valid_moves = get_valid_moves(&piece_layer->game->board, piece);

        set_moving_piece_location(piece_layer, move->piece, event->mouse_button.x, event->mouse_button.y);

        return 1;
    case MOUSE_BUTTON_UP_EVENT:
        if (event->mouse_button.button != MOUSE_BUTTON_LEFT) {
            return 0;
        }

        move = &piece_layer->game->move;

        if (!move->piece) {
            return 0;
        }


        Window* window = get_window_from_id(event->mouse_button.window_id);
        if (!get_square_from_point(piece_layer, window, event->mouse_button.x, event->mouse_button.y, &rank, &file)) {
            return 0;
        }

        move->new_file = file;
        move->new_rank = rank;

        piece_layer->game->move_piece(piece_layer->game, *move);

        int32_t x, y;
        if (!get_point_from_square(piece_layer, window, move->piece->rank, move->piece->file, &x, &y)) {
            return 0;
        }

        set_moving_piece_location(piece_layer, move->piece, x, y);

        reset_move(move);

        return 1;
    case MOUSE_MOVE_EVENT:
        if (!piece_layer->game->move.piece) {
            return 0;
        }

        set_moving_piece_location(piece_layer, piece_layer->game->move.piece, event->mouse_move.x, event->mouse_move.y);

        return 1;
    }
}

static uint8_t get_square_from_point(const PieceLayer* layer, const Window* window, int32_t x, int32_t y, uint8_t* rank, uint8_t* file) {
    uint32_t width, height;
    get_window_size(window, &width, &height);

    Point top_left = {
        .x = (width / 2) - (layer->game->board.file_count / 2) * PIECE_SIZE,
        .y = (height / 2) - (layer->game->board.rank_count / 2) * PIECE_SIZE
    };

    Point bottom_right = {
        .x = (width / 2) + (layer->game->board.file_count / 2) * PIECE_SIZE,
        .y = (height / 2) + (layer->game->board.rank_count / 2) * PIECE_SIZE
    };

    if (x < top_left.x || y < top_left.y || x > bottom_right.x || y > bottom_right.y) {
        return 0;
    }

    int32_t zero_x = x - top_left.x;
    int32_t zero_y = y - top_left.y;

    *file = zero_x / PIECE_SIZE + 1;
    *rank = zero_y / PIECE_SIZE + 1;

    return 1;
}

static uint8_t get_point_from_square(const PieceLayer* layer, const Window* window, uint8_t rank, uint8_t file, int32_t* x, int32_t* y) {
    uint32_t width, height;
    get_window_size(window, &width, &height);

    Point top_left = {
        .x = (width / 2) - (layer->game->board.file_count / 2) * PIECE_SIZE,
        .y = (height / 2) - (layer->game->board.rank_count / 2) * PIECE_SIZE
    };

    *x = top_left.x + PIECE_SIZE * file - PIECE_SIZE / 2;
    *y = top_left.y + PIECE_SIZE * rank - PIECE_SIZE / 2;

    return 1;
}

static void set_moving_piece_location(PieceLayer* layer, const PieceState* piece, int32_t x, int32_t y) {
    int32_t index = list_index_of(layer->game->board.piece_states, piece);

    if (index != -1) {
        RenderTexture* piece_texture = (RenderTexture*)list_get(layer->layer.objects, index);
        piece_texture->object.x = x - PIECE_SIZE / 2;
        piece_texture->object.y = y - PIECE_SIZE / 2;
    }
}
