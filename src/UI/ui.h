#ifndef UI_H
#define UI_H

#include "core.h"

uint32_t ui_init();
void ui_quit();
void ui_get_error(char* buffer, uint32_t maxLength);

#endif