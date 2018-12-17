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
    sfSprite_setPosition(obj_box[1]->spr, (sfVector2f){2000.0, 2000.0});
    sfSprite_setPosition(obj_box[3]->spr, (sfVector2f){1389.0, 13.0});
    sfSprite_setPosition(obj_box[4]->spr, (sfVector2f){2127.0, 13.0});
    sfSprite_setPosition(obj_box[5]->spr, (sfVector2f){2865.0, 13.0});
    sfSprite_setPosition(obj_box[6]->spr, (sfVector2f){3603.0, 13.0});
    sfSprite_setPosition(obj_box[7]->spr, (sfVector2f){0.0, 200.0});
    //for
    obj_box[0]->vec.x = -1.0;
    obj_box[3]->vec.x = -1.0;
    obj_box[4]->vec.x = -1.0;
    obj_box[5]->vec.x = -1.0;
    obj_box[6]->vec.x = -1.0;
    //
}
