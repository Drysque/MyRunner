/*
** EPITECH PROJECT, 2018
** check_death.c
** File description:
** checks the collision of the plahyer with the obstacles
*/

#include "runner.h"

static bool laser_collide(game_object **obj_box)
{
    sfVector2f player = sfSprite_getPosition(obj_box[1]->spr);
    sfVector2f laser = sfSprite_getPosition(obj_box[15]->spr);
    bool min =  (player.y - 10) <= laser.y;
    bool max =  player.y >= (laser.y + 140);
    bool firing = obj_box[15]->rect.top > 307;

    if (!min && !max && firing)
        return true;
    return false;
}

static bool sprite_collide(sfSprite *player, sfSprite *obs_spr)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(player);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(obs_spr);

    if (sfFloatRect_intersects(&rect1, &rect2, NULL))
        return true;
    return false;
}

int check_death(int go_on, game_object **obj_box)
{
    if (go_on)
        return go_on;
    if (laser_collide(obj_box))
        return 1;
    if (sprite_collide(obj_box[1]->spr, obj_box[13]->spr))
        return 1;
    if (sprite_collide(obj_box[1]->spr, obj_box[16]->spr))
        return 1;
    return 0;
}
