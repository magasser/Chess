#ifndef UI_H
#define UI_H

#include <stdint.h>

#include "color.h"
#include "event.h"
#include "layer.h"
#include "scene.h"
#include "render_object.h"
#include "renderer.h"
#include "window.h"
#include "texture.h"
#include "geometry/point.h"
#include "shapes/rectangle.h"
#include "components/button.h"

uint32_t ui_init();
void ui_quit();
void ui_get_error(char* buffer, uint32_t max_length);

#endif