/*
** EPITECH PROJECT, 2018
** move_laser.c
** File description:
** takes care of the laser animation and translation
*/

#include "runner.h"

static void move_laser_rect(game_object *obj, int reset, int offset, int frames)
{
    if (obj->rect.top + offset >= (offset * frames) + reset)
        obj->rect.top = reset;
    else
        obj->rect.top += offset;
    sfClock_restart(obj->clock);
}

void move_laser(game_object *obj, int width)
{
    sfTime time = sfClock_getElapsedTime(obj->clock);

    if (width > 40 || width < 0) {
        sfSprite_move(obj->spr, obj->vec);
        move_laser_rect(obj, 0, 0, 1);
    }
    else if (width > 5) {
        sfSprite_move(obj->spr, (sfVector2f){-0.5, 0.0});
        if (time.microseconds > 100000.0)
            move_laser_rect(obj, 77, 77, 3);
    }
    else {
        sfSprite_move(obj->spr, (sfVector2f){-0.095, 0.0});
        if (time.microseconds > 100000.0)
            move_laser_rect(obj, 308, 77, 2);
    }
    sfSprite_setTextureRect(obj->spr, obj->rect);
}
