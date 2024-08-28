#include "board_layer.h"

#define SQUARE_SIZE 60

BoardLayer* create_board_layer(Renderer* renderer, const Board* board) {
    BoardLayer* board_layer = (BoardLayer*)malloc(sizeof(BoardLayer));

    board_layer->layer.objects = list_create(64);
    board_layer->board = board;

    uint32_t width, height;
    get_window_size(renderer->window, &width, &height);

    Point top_left = {
        .x = (width / 2) - (board->rank_count / 2) * SQUARE_SIZE,
        .y = (height / 2) - (board->file_count / 2) * SQUARE_SIZE
    };

    Rectangle* rectangles = (Rectangle*)calloc(board->rank_count * board->file_count, sizeof(Rectangle));

    for (uint32_t rank = 0; rank < board->rank_count; rank++) {
        for (uint8_t file = 0; file < board->file_count; file++) {
            uint8_t color = (rank + file) % 2 != 0 ? 200 : 55;
            Color square_color = { color, color, color, 255 };

            Rectangle* rectangle = &rectangles[rank + file * board->rank_count];
            rectangle->shape.object.type = RENDER_OBJECT_SHAPE;
            rectangle->shape.object.x = top_left.x + rank * SQUARE_SIZE;
            rectangle->shape.object.y = top_left.y + file * SQUARE_SIZE;
            rectangle->shape.type = SHAPE_RECTANGLE;
            rectangle->shape.color = square_color;
            rectangle->width = SQUARE_SIZE;
            rectangle->height = SQUARE_SIZE;

            list_add(board_layer->layer.objects, rectangle);
        }
    }

    return board_layer;
}