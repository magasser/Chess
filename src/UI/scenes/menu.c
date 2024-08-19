#include "menu.h"

#include "UI/components/button.h"

Scene* create_menu_scene() {
    Scene* scene = (Scene*)malloc(sizeof(Scene));

    scene->buttons = (Button*)malloc(sizeof(Button) * 1);
    scene->buttons[0] = { 600, 300, 150, 50, NULL };

    return scene;
}
