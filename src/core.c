#include "core.h"

Array* create_array(size_t item_size, uint32_t length) {
    Array* array = (Array*)malloc(sizeof(Array));

    array->items = malloc(item_size * length);

    return array;
}

void destroy_array(Array* array) {
    free(array->items);
    free(array);
}