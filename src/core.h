#ifndef CORE_H
#define CORE_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "utils/list.h"

typedef void (*Action)();
typedef void (*Func1)(void*);

typedef struct {
    uint8_t r, g, b, a;
} Color;

#endif