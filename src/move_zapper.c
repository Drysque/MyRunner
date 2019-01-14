/*
** EPITECH PROJECT, 2018
** move_missile.c
** File description:
** takes care of the zapper animation and translation
*/

#include "runner.h"

static void move_zapper_rect(game_object *obj, int reset, int offset)
{

    if (obj->rect.top + offset >= (offset * 4) + reset)
        obj->rect.top = reset;
    else
        obj->rect.top += offset;
    sfClock_restart(obj->clock);
}

void move_zapper(game_object *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->clock);

    if (time.microseconds > 100000.0)
        move_zapper_rect(obj, 0, 48);
    sfSprite_move(obj->spr, obj->vec);
    sfSprite_setTextureRect(obj->spr, obj->rect);
}
