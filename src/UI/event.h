#ifndef EVENT_H
#define EVENT_H

#include "core.h"

typedef enum {
    QUIT_EVENT = 1,
    KEY_DOWN_EVENT,
    KEY_UP_EVENT,
    MOUSE_BUTTON_DOWN_EVENT,
    MOUSE_BUTTON_UP_EVENT,
    MOUSE_MOVE_EVENT,
    MOUSE_WHEEL_EVENT,
} EventType;

typedef struct {
    EventType type;
} QuitEvent;

typedef struct {
    EventType type;
    uint8_t repeat;
} KeyEvent;

typedef enum {
    MOUSE_BUTTON_UNKNOWN = 1,
    MOUSE_BUTTON_LEFT,
    MOUSE_BUTTON_RIGHT,
    MOUSE_BUTTON_MIDDLE,
} MouseButton;

typedef struct {
    EventType type;
    MouseButton button;
    uint8_t clicks;
    uint8_t pressed;
    int32_t x;
    int32_t y;
} MouseButtonEvent;

typedef struct {
    EventType type;
    uint8_t pressed;
    int32_t x;
    int32_t y;
    int32_t x_rel;
    int32_t y_rel;
} MouseMoveEvent;

typedef struct {
    EventType type;
    int32_t x;
    int32_t y;
} MouseWheelEvent;

typedef struct {
    EventType type;
    QuitEvent quit;
    KeyEvent key;
    MouseButtonEvent mouse_button;
    MouseMoveEvent mouse_move;
    MouseWheelEvent mouse_wheel;
} Event;

uint32_t wait_event(Event* event);

#endif