/*
** create_my_sprites.c
** File description:
** EPITECH PROJECT, 2018
** -
*/

#include "runner.h"

static void create_env(game_object *obj, char const *path)
{
    obj->tex = sfTexture_createFromFile(path, NULL);
    obj->spr = sfSprite_create();
    sfSprite_setTexture(obj->spr, obj->tex, sfTrue);
}

void create_my_sprites(game_object **obj_box)
{
    create_env(obj_box[0], "./image_src/LabEmpty.png");
    create_env(obj_box[1], "./image_src/run1.png");
    create_env(obj_box[2], "./image_src/LabEntry.png");
    create_env(obj_box[3], "./image_src/Slide.png");
    create_env(obj_box[4], "./image_src/EmptySlide.png");
    create_env(obj_box[5], "./image_src/Slide.png");
    create_env(obj_box[6], "./image_src/EmptySlide.png");
    create_env(obj_box[7], "./image_src/XP-pix.jpg");
}
