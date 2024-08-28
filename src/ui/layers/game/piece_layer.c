#include "ui/layers/game/piece_layer.h"

#include <engine/engine.h>

#define PIECE_SIZE 60

Point get_piece_location(PieceKind kind, PieceColor color);

PieceLayer* create_piece_layer(Renderer* renderer, const Board* board) {
    PieceLayer* piece_layer = (PieceLayer*)malloc(sizeof(PieceLayer));

    piece_layer->layer.objects = list_create(32);
    piece_layer->board = board;

    uint32_t width, height;
    get_window_size(renderer->window, &width, &height);

    Point top_left = {
        .x = (width / 2) - (board->rank_count / 2) * PIECE_SIZE,
        .y = (height / 2) - (board->file_count / 2) * PIECE_SIZE
    };

    // TODO: Find a way to handle asset paths
    Texture* atlas_texture = load_texture_from_svg(renderer, "resources/assets/pieces/piece_atlas.svg", PIECE_SIZE * 6, PIECE_SIZE * 2);

    for (uint32_t i = 0; i < board->piece_states->count; i++) {
        PieceState* state = (PieceState*)board->piece_states->items[i];
        RenderTexture* texture = (RenderTexture*)malloc(sizeof(RenderTexture));
        texture->object.type = RENDER_OBJECT_TEXTURE;
        texture->object.angle = 0.0;
        texture->object.x = top_left.x + PIECE_SIZE * (state->rank - 1);
        texture->object.y = top_left.y + PIECE_SIZE * (state->file - 1);
        texture->texture = atlas_texture;
        texture->location = get_piece_location(state->piece.kind, state->piece.color);
        texture->width = PIECE_SIZE;
        texture->height = PIECE_SIZE;

        list_add(piece_layer->layer.objects, texture);
    }

    return piece_layer;
}

Point get_piece_location(PieceKind kind, PieceColor color) {
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
