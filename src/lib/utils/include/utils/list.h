#ifndef LIST_H
#define LIST_H

#include <stdint.h>

typedef struct {
    int32_t capacity;
    int32_t count;
    void** items;
} List;

List* list_create(int32_t capacity);
void list_destroy(List* list);

void list_add(List* list, void* value);
uint8_t list_remove(List* list, void* value);

void* list_get(List* list, int32_t index);
void list_set(List* list, int32_t index, void* value);

int32_t list_index_of(List* list, void* value);

void list_foreach(List* list, void (*action)(void*));

#endif