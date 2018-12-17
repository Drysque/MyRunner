/*
** EPITECH PROJECT, 2018
** move_env.c
** File description:
** moves the environnement, takes care of the parallax effect
*/

#include "runner.h"

static void parallax_mov(game_object **obj_box, int i)
{
    if (sfSprite_getPosition(obj_box[i]->spr).x > -750)
        sfSprite_move(obj_box[i]->spr, obj_box[i]->vec);
    else
        sfSprite_setPosition(obj_box[i]->spr, (sfVector2f){2200.0, 13.0});
}

void move_env(game_object **obj_box)
{
    if (sfSprite_getPosition(obj_box[0]->spr).x > -1500)
        sfSprite_move(obj_box[0]->spr, obj_box[0]->vec);
    //for
    parallax_mov(obj_box, 3);
    parallax_mov(obj_box, 4);
    parallax_mov(obj_box, 5);
    parallax_mov(obj_box, 6);
    //
}
