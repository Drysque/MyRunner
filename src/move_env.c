/*
** EPITECH PROJECT, 2018
** move_env.c
** File description:
** moves the environnement, takes care of the parallax effect
*/

#include "runner.h"

static void parallax_mov(game_object *obj, int too_far, sfVector2f reset_pos)
{
    if (sfSprite_getPosition(obj->spr).x >= too_far)
        sfSprite_move(obj->spr, obj->vec);
    else
        sfSprite_setPosition(obj->spr, reset_pos);
}

void move_env(game_object **obj_box)
{
    if (sfSprite_getPosition(obj_box[0]->spr).x > -1500)
        sfSprite_move(obj_box[0]->spr, obj_box[0]->vec);
    for (int i = 3; i < 7; i++)
        parallax_mov(obj_box[i], -740, (sfVector2f){2196.0, 13.0});
    parallax_mov(obj_box[7], -1918, (sfVector2f){1920.0, 0.0});
    parallax_mov(obj_box[8], -1918, (sfVector2f){1920.0, 0.0});
    parallax_mov(obj_box[9], -2000, (sfVector2f){1920.0, 500.0});
    parallax_mov(obj_box[10], -1000, (sfVector2f){1920.0, 500.0});
    parallax_mov(obj_box[11], -1000, (sfVector2f){1920.0, 250.0});
    parallax_mov(obj_box[12], -1000, (sfVector2f){1920.0, 500.0});
}
