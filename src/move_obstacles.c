/*
** EPITECH PROJECT, 2018
** move_obstacles.c
** File description:
** takes care of the obstacles animation
*/

#include "runner.h"

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
    int missile_width = sfSprite_getPosition(obj_box[13]->spr).x;
    int laser_width = sfSprite_getPosition(obj_box[15]->spr).x;
    int zapper_width = sfSprite_getPosition(obj_box[16]->spr).x;

    if (missile_width > -150)
        move_missile(obj_box[13]);
    if (laser_width > -2000)
        move_laser(obj_box[15], laser_width);
    if (zapper_width > -400)
        move_zapper(obj_box[16]);
    move_warning(obj_box);
}
