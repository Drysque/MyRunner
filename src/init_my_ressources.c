/*
** EPITECH PROJECT, 2018
** init_my_ressources.c
** File description:
** -
*/

#include "runner.h"

void init_my_ressources(game_object **obj_box)
{
    sfSprite_setScale(obj_box[0]->spr, (sfVector2f){3.0, 3.0});
    sfSprite_setScale(obj_box[1]->spr, (sfVector2f){1.5, 1.5});
    sfSprite_setScale(obj_box[2]->spr, (sfVector2f){3.0, 3.0});
    //for
    sfSprite_setScale(obj_box[3]->spr, (sfVector2f){2.115, 2.115});
    sfSprite_setScale(obj_box[4]->spr, (sfVector2f){2.115, 2.115});
    sfSprite_setScale(obj_box[5]->spr, (sfVector2f){2.115, 2.115});
    sfSprite_setScale(obj_box[6]->spr, (sfVector2f){2.115, 2.115});
    //
    sfSprite_setScale(obj_box[13]->spr, (sfVector2f){3.0, 3.0});
    sfSprite_setPosition(obj_box[1]->spr, (sfVector2f){2000.0, 2000.0});
    //for
    sfSprite_setPosition(obj_box[3]->spr, (sfVector2f){1389.0, 13.0});
    sfSprite_setPosition(obj_box[4]->spr, (sfVector2f){2127.0, 13.0});
    sfSprite_setPosition(obj_box[5]->spr, (sfVector2f){2865.0, 13.0});
    sfSprite_setPosition(obj_box[6]->spr, (sfVector2f){3603.0, 13.0});
    //
    sfSprite_setPosition(obj_box[8]->spr, (sfVector2f){1920.0, 0.0});
    sfSprite_setPosition(obj_box[9]->spr, (sfVector2f){500.0, 500.0});
    sfSprite_setPosition(obj_box[10]->spr, (sfVector2f){500.0, 500.0});
    sfSprite_setPosition(obj_box[11]->spr, (sfVector2f){1000.0, 250.0});
    sfSprite_setPosition(obj_box[12]->spr, (sfVector2f){800.0, 500.0});
    sfSprite_setPosition(obj_box[13]->spr, (sfVector2f){2000.0, 200.0});
    //for
    obj_box[0]->vec.x = -9.0;//hallway
    obj_box[3]->vec.x = -9.0;
    obj_box[4]->vec.x = -9.0;
    obj_box[5]->vec.x = -9.0;
    obj_box[6]->vec.x = -9.0;

    obj_box[7]->vec.x = -3.0;//stars
    obj_box[8]->vec.x = -3.0;

    obj_box[9]->vec.x = -6.0;//planets
    obj_box[10]->vec.x = -7.5;
    obj_box[11]->vec.x = -4.2;
    obj_box[12]->vec.x = -3.6;
    obj_box[13]->vec.x = -40.0;
    // obj_box[1]->vec = (sfVector2f){0.0, 0.0};
    obj_box[1]->clock = sfClock_create();
    obj_box[13]->clock = sfClock_create();
    obj_box[1]->rect = (sfIntRect){0, 0, 59, 66};
    obj_box[13]->rect = (sfIntRect){0, 0, 45, 29};
}
