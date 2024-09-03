#include <engine/window.h>

struct Windows {
    Window* first;
    Window* last;
};

static struct Windows windows;
static uint8_t has_window = 0;

void on_window_create(Window* window) {
    if (!has_window) {
        windows.first = window;
        windows.last = window;
        window->prev = NULL;
        window->next = NULL;
        has_window = 1;
        return;
    }

    windows.last->next = window;
    window->prev = windows.last;
    windows.last = window;
}

void on_window_destroy(Window* window) {
    if (window->next && window->prev) {
        window->next->prev = window->prev;
        window->prev->next = window->next;
    }
    else if (window->next) {
        window->next->prev = NULL;
    }
    else if (window->prev) {
        window->prev->next = NULL;
    }
    else {
        has_window = 0;
    }
}

uint32_t get_window_id(const Window* window) {
    return window->id;
}
Window* get_window_from_id(uint32_t id) {
    Window* window = windows.first;
    for (;window->next; window) {
        if (window->id == id) {
            return window;
        }
    }

    return window;
}