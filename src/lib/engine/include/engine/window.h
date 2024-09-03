#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

#define WINDOWPOS_UNDEFINED 0x1FFF0000u
#define WINDOWPOS_CENTERED 0x2FFF0000u

typedef enum {
    WINDOW_FLAGS_FULLSCREEN = 1,
    WINDOW_FLAGS_SHOWN = 2,
    WINDOW_FLAGS_HIDDEN = 4,
    WINDOW_FLAGS_RESIZEABLE = 8,
    WINDOW_FLAGS_MINIMIZED = 16,
    WINDOW_FLAGS_MAXIMIZED = 32
} WindowFlags;

typedef struct Window Window;

struct Window {
    void* window;
    uint32_t id;
    Window* prev;
    Window* next;
};

Window* create_window(const char* title, uint32_t x, uint32_t y, uint32_t width, uint32_t height, WindowFlags flags);
void destory_window(Window* window);

void get_window_size(const Window* window, uint32_t* width, uint32_t* height);

uint32_t get_window_id(const Window* window);
Window* get_window_from_id(uint32_t id);

#endif