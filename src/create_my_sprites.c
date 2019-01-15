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
    create_env(obj_box[1], "./image_src/BarrySheet.png");
    create_env(obj_box[2], "./image_src/LabEntry.png");
    create_env(obj_box[3], "./image_src/Slide.png");
    create_env(obj_box[4], "./image_src/EmptySlide.png");
    create_env(obj_box[5], "./image_src/Slide.png");
    create_env(obj_box[6], "./image_src/EmptySlide.png");
    create_env(obj_box[7], "./image_src/Space-Space.png");
    create_env(obj_box[8], "./image_src/Earth-Space.png");
    create_env(obj_box[9], "./image_src/Earth.png");
    create_env(obj_box[10], "./image_src/Moon.png");
    create_env(obj_box[11], "./image_src/Mars.png");
    create_env(obj_box[12], "./image_src/Saturn.png");
    create_env(obj_box[13], "./image_src/MissileSheet.png");
    create_env(obj_box[14], "./image_src/MissileWarn.png");
    create_env(obj_box[15], "./image_src/LaserSheet.png");
    create_env(obj_box[16], "./image_src/ZapperSheet.png");
    create_env(obj_box[17], "./image_src/GO.png");
}
