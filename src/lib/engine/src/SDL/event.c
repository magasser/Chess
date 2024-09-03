#include <engine/event.h>

#include <SDL2/SDL.h>

MouseButton get_button(uint8_t button_index);

uint32_t wait_event(Event* event) {

    SDL_Event sdl_event;
    event->type = 0;

    while (!event->type) {
        uint32_t result = SDL_WaitEvent(&sdl_event);

        if (!result) {
            return result;
        }

        switch (sdl_event.type) {
        case SDL_QUIT:
            event->type = QUIT_EVENT;
            event->quit.type = event->type;
            break;
        case SDL_KEYUP:
            event->type = KEY_UP_EVENT;
            event->key.type = event->type;
            event->key.window_id = sdl_event.key.windowID;
            event->key.repeat = sdl_event.key.repeat ? 1 : 0;
            break;
        case SDL_KEYDOWN:
            event->type = KEY_DOWN_EVENT;
            event->key.type = event->type;
            event->key.window_id = sdl_event.key.windowID;
            event->key.repeat = sdl_event.key.repeat ? 1 : 0;
            break;
        case SDL_MOUSEBUTTONUP:
            event->type = MOUSE_BUTTON_UP_EVENT;
            event->mouse_button.type = event->type;
            event->mouse_button.window_id = sdl_event.button.windowID;
            event->mouse_button.button = get_button(sdl_event.button.button);
            event->mouse_button.clicks = sdl_event.button.clicks;
            event->mouse_button.x = sdl_event.button.x;
            event->mouse_button.y = sdl_event.button.y;
            break;
        case SDL_MOUSEBUTTONDOWN:
            event->type = MOUSE_BUTTON_DOWN_EVENT;
            event->mouse_button.type = event->type;
            event->mouse_button.window_id = sdl_event.button.windowID;
            event->mouse_button.button = get_button(sdl_event.button.button);
            event->mouse_button.clicks = sdl_event.button.clicks;
            event->mouse_button.x = sdl_event.button.x;
            event->mouse_button.y = sdl_event.button.y;
            break;
        case SDL_MOUSEMOTION:
            event->type = MOUSE_MOVE_EVENT;
            event->mouse_move.type = event->type;
            event->mouse_move.window_id = sdl_event.motion.windowID;
            event->mouse_move.pressed = sdl_event.motion.state;
            event->mouse_move.x = sdl_event.motion.x;
            event->mouse_move.y = sdl_event.motion.y;
            event->mouse_move.x_rel = sdl_event.motion.xrel;
            event->mouse_move.x_rel = sdl_event.motion.yrel;
            break;
        case SDL_MOUSEWHEEL:
            event->type = MOUSE_WHEEL_EVENT;
            event->mouse_wheel.type = event->type;
            event->mouse_wheel.window_id = sdl_event.wheel.windowID;
            event->mouse_wheel.x = sdl_event.wheel.direction == SDL_MOUSEWHEEL_FLIPPED ? sdl_event.wheel.x * -1 : sdl_event.wheel.x;
            event->mouse_wheel.y = sdl_event.wheel.direction == SDL_MOUSEWHEEL_FLIPPED ? sdl_event.wheel.y * -1 : sdl_event.wheel.y;
            break;
        }
    }
}

MouseButton get_button(uint8_t button_index) {
    switch (button_index) {
    case SDL_BUTTON_LEFT:
        return MOUSE_BUTTON_LEFT;
    case SDL_BUTTON_RIGHT:
        return MOUSE_BUTTON_RIGHT;
    case SDL_BUTTON_MIDDLE:
        return MOUSE_BUTTON_MIDDLE;
    default:
        return MOUSE_BUTTON_UNKNOWN;
    }
}