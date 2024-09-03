#include "hint_layer.h"

#define SQUARE_SIZE 60

static void update_hint_layer(HintLayer* layer);

HintLayer* create_hint_layer(Renderer* renderer, const GameContext* game) {
    HintLayer* hint_layer = (HintLayer*)malloc(sizeof(HintLayer));

    hint_layer->layer.handle_event = layer_handle_event_nop;
    hint_layer->layer.update = (void(*)(Layer*))update_hint_layer;
    hint_layer->layer.objects = list_create(0);
    hint_layer->game = game;
    hint_layer->renderer = renderer;
}

static void update_hint_layer(HintLayer* layer) {
    if (layer->game->move.piece == NULL) {
        for (int32_t i = 0; i < layer->layer.objects->count; i++) {
            free(layer->layer.objects->items[i]);
        }
        list_clear(layer->layer.objects);
        return;
    }

    uint32_t width, height;
    get_window_size(layer->renderer->window, &width, &height);

    Point top_left = {
        .x = (width / 2) - (layer->game->board.file_count / 2) * SQUARE_SIZE,
        .y = (height / 2) - (layer->game->board.rank_count / 2) * SQUARE_SIZE
    };

    List* moves = layer->game->move.valid_moves;

    for (uint32_t i = 0; i < moves->count; i++) {
        Color square_color = { 0, 255, 0, 50 };

        Move* move = (Move*)moves->items[i];

        Rectangle* rectangle = (Rectangle*)calloc(1, sizeof(Rectangle));
        rectangle->shape.object.type = RENDER_OBJECT_SHAPE;
        rectangle->shape.object.x = top_left.x + (move->new_file - 1) * SQUARE_SIZE;
        rectangle->shape.object.y = top_left.y + (move->new_rank - 1) * SQUARE_SIZE;
        rectangle->shape.type = SHAPE_RECTANGLE;
        rectangle->shape.color = square_color;
        rectangle->width = SQUARE_SIZE;
        rectangle->height = SQUARE_SIZE;

        list_add(layer->layer.objects, rectangle);
    }
}
