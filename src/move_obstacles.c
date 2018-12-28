/*
** EPITECH PROJECT, 2018
** move_obstacles.c
** File description:
** takes care of the obstacles animation
*/

#include "runner.h"

static void move_obs_rect(game_object *obj, int reset, int offset)
{

    if (obj->rect.left + offset >= (offset * 3) + reset)
        obj->rect.left = reset;
    else
        obj->rect.left += offset;
    sfClock_restart(obj->clock);
}

static void move_missile(game_object *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->clock);

    if (time.microseconds > 100000.0) {
        move_obs_rect(obj, 0, 45);
    }
    sfSprite_move(obj->spr, obj->vec);
    sfSprite_setTextureRect(obj->spr, obj->rect);
}

static void move_warning(game_object **obj_box)
{
    int width = sfSprite_getPosition(obj_box[13]->spr).x;
    int height = sfSprite_getPosition(obj_box[1]->spr).y;
    sfVector2f warn_player = {1800, height};
    sfVector2f front_player = {width, height};

    if (width > 2000) {
        sfSprite_setPosition(obj_box[13]->spr, front_player);
        sfSprite_setPosition(obj_box[14]->spr, warn_player);
    }
    else
        sfSprite_setPosition(obj_box[14]->spr, (sfVector2f){2000, 2000});
}

void move_obstacles(game_object **obj_box)
{
    int width = sfSprite_getPosition(obj_box[13]->spr).x;

    if (width > -150)
        move_missile(obj_box[13]);
    move_warning(obj_box);
}
