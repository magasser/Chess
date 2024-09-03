#include <utils/list.h>

#include <stdlib.h>

static void list_reallocate(List* list);

List* list_create(int32_t capacity) {
    List* list = (List*)malloc(sizeof(List));

    list->capacity = capacity;
    list->count = 0;
    list->items = calloc(capacity, sizeof(void*));

    return list;
}

void list_destroy(List* list) {
    free(list->items);
    free(list);
}

void list_add(List* list, void* value) {
    int32_t count = list->count + 1;

    if (count > list->capacity) {
        list_reallocate(list);
    }

    list->items[list->count] = value;
    list->count = count;
}

uint8_t list_remove(List* list, void* value) {
    int32_t index = list_index_of(list, value);

    if (index == -1) {
        return 0;
    }

    if (list->count == 1) {
        list->items[0] = NULL;
        list->count = 0;
        return 1;
    }

    for (int32_t i = index + 1; i < list->count; i++) {
        list->items[i - 1] = list->items[i];
    }

    list->count--;
    list->items[list->count] = NULL;

    return 1;
}

void list_clear(List* list) {
    for (int32_t i = 0; i < list->count; i++) {
        list->items[i] = NULL;
    }

    list->count = 0;
}

void* list_get(List* list, int32_t index) {
    return list->items[index];
}

void list_set(List* list, int32_t index, void* value) {
    list->items[index] = value;
}

int32_t list_index_of(List* list, const void* value) {
    for (int32_t i = 0; i < list->count; i++) {
        if (list->items[i] == value) {
            return i;
        }
    }

    return -1;
}

void list_foreach(List* list, void (*action)(void*)) {
    for (int32_t i = 0; i < list->count; i++) {
        action(list->items[i]);
    }
}

static void list_reallocate(List* list) {
    int32_t capacity = 1 + list->capacity * 1.3f;

    if (capacity < list->capacity) {
        capacity = 0xFFFFFFFF;
    }

    void** items = calloc(capacity, sizeof(void*));

    for (int32_t i = 0; i < list->count; i++) {
        items[i] = list->items[i];
    }

    free(list->items);

    list->items = items;
    list->capacity = capacity;
}