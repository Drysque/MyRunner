/*
** EPITECH PROJECT, 2018
** move_missile.c
** File description:
** takes care of the missile animation and translation
*/

#include "runner.h"

static void move_missile_rect(game_object *obj, int reset, int offset)
{
    if (obj->rect.left == 135);
    else if (obj->rect.left == 90)
        obj->rect.left = reset;
    else
        obj->rect.left += offset;
    sfClock_restart(obj->clock);
}

void move_missile(game_object *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->clock);

    if (time.microseconds > 100000.0)
        move_missile_rect(obj, 0, 45);
    sfSprite_move(obj->spr, obj->vec);
    sfSprite_setTextureRect(obj->spr, obj->rect);
}
