/*
** EPITECH PROJECT, 2018
** init_my_ressources.c
** File description:
** initialises the ressources
*/

#include "runner.h"

static void set_sprites_pos(game_object **obj_box)
{
    sfSprite_setPosition(obj_box[1]->spr, (sfVector2f){2000.0, 2000.0});
    sfSprite_setPosition(obj_box[3]->spr, (sfVector2f){1389.0, 13.0});
    sfSprite_setPosition(obj_box[4]->spr, (sfVector2f){2127.0, 13.0});
    sfSprite_setPosition(obj_box[5]->spr, (sfVector2f){2865.0, 13.0});
    sfSprite_setPosition(obj_box[6]->spr, (sfVector2f){3603.0, 13.0});
    sfSprite_setPosition(obj_box[8]->spr, (sfVector2f){1920.0, 0.0});
    sfSprite_setPosition(obj_box[9]->spr, (sfVector2f){500.0, 500.0});
    sfSprite_setPosition(obj_box[10]->spr, (sfVector2f){500.0, 500.0});
    sfSprite_setPosition(obj_box[11]->spr, (sfVector2f){1000.0, 250.0});
    sfSprite_setPosition(obj_box[12]->spr, (sfVector2f){800.0, 500.0});
    sfSprite_setPosition(obj_box[18]->spr, (sfVector2f){400.0, 170.0});
    for (int i = 13; i < 17; i++)
        sfSprite_setPosition(obj_box[i]->spr, (sfVector2f){-2000.0, 0.0});
}

static void set_sprites_scale(game_object **obj_box)
{
    sfSprite_setScale(obj_box[0]->spr, (sfVector2f){3.0, 3.0});
    sfSprite_setScale(obj_box[1]->spr, (sfVector2f){1.5, 1.5});
    sfSprite_setScale(obj_box[2]->spr, (sfVector2f){3.0, 3.0});
    for (int i = 3; i < 7; i++)
        sfSprite_setScale(obj_box[i]->spr, (sfVector2f){2.115, 2.115});
    sfSprite_setScale(obj_box[13]->spr, (sfVector2f){3.0, 3.0});
    sfSprite_setScale(obj_box[14]->spr, (sfVector2f){2.5, 2.5});
    sfSprite_setScale(obj_box[15]->spr, (sfVector2f){3.175, 3.175});
    sfSprite_setScale(obj_box[16]->spr, (sfVector2f){3.175, 3.175});
    sfSprite_setColor(obj_box[17]->spr, (sfColor){255, 255, 255, 0});
    sfSprite_setScale(obj_box[18]->spr, (sfVector2f){1.70, 1.70});
}

static void set_sprites_vec(game_object **obj_box)
{
    obj_box[0]->vec = (sfVector2f){-9.0, 0.0};
    obj_box[1]->vec = (sfVector2f){0.0, 0.0};
    for (int i = 3; i < 7; i++)
        obj_box[i]->vec = (sfVector2f){-9.0, 0.0};
    obj_box[7]->vec = (sfVector2f){-3.0, 0.0};
    obj_box[8]->vec = (sfVector2f){-3.0, 0.0};
    obj_box[9]->vec = (sfVector2f){-6.0, 0.0};
    obj_box[10]->vec = (sfVector2f){-7.5, 0.0};
    obj_box[11]->vec = (sfVector2f){-4.2, 0.0};
    obj_box[12]->vec = (sfVector2f){-3.6, 0.0};
    obj_box[13]->vec = (sfVector2f){-40.0, 0.0};
    obj_box[15]->vec = (sfVector2f){-40.0, 0.0};
    obj_box[16]->vec = (sfVector2f){-9.0, 0.0};
    obj_box[18]->vec = (sfVector2f){0.0, -12.0};
}

void init_my_ressources(game_object **obj_box)
{
    set_sprites_scale(obj_box);
    set_sprites_pos(obj_box);
    obj_box[1]->clock = sfClock_create();
    obj_box[13]->clock = sfClock_create();
    obj_box[15]->clock = sfClock_create();
    obj_box[16]->clock = sfClock_create();
    set_sprites_vec(obj_box);
    obj_box[1]->rect = (sfIntRect){0, 0, 59, 66};
    obj_box[13]->rect = (sfIntRect){0, 0, 45, 29};
    obj_box[15]->rect = (sfIntRect){0, 0, 608, 77};
    obj_box[16]->rect = (sfIntRect){0, 0, 118, 48};
}
