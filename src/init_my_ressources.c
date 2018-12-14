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
    sfSprite_setPosition(obj_box[1]->spr, (sfVector2f){1389.0, 29.0});
    sfSprite_setScale(obj_box[1]->spr, (sfVector2f){2.11, 2.11});
    sfSprite_setScale(obj_box[2]->spr, (sfVector2f){3.0, 3.0});
    sfSprite_setPosition(obj_box[3]->spr, (sfVector2f){2000.0, 2000.0});
    sfSprite_setScale(obj_box[3]->spr, (sfVector2f){1.5, 1.5});
}
