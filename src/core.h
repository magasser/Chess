#ifndef CORE_H
#define CORE_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef void (*Action)();
typedef void (*Func1)(void*);

typedef struct {
    void* items;
    uint32_t length;
} Array;

Array* create_array(size_t itemSize, uint32_t length);
void destroy_array(Array* array);

#endif