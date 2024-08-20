#ifndef UI_H
#define UI_H

#include "core.h"

#include "UI/ui.h"
#include "UI/window.h"
#include "UI/renderer.h"
#include "UI/event.h"

uint32_t ui_init();
void ui_quit();
void ui_get_error(char* buffer, uint32_t max_length);

#endif