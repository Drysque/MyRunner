/*
** EPITECH PROJECT, 2018
** check_death.c
** File description:
** checks the collision of the plahyer with the obstacles
*/

#include "runner.h"

static bool laser_collide(game_object **obj_box, sfMusic *laser_death)
{
    sfVector2f player = sfSprite_getPosition(obj_box[1]->spr);
    sfVector2f laser = sfSprite_getPosition(obj_box[15]->spr);
    bool min =  (player.y - 10) <= laser.y;
    bool max =  player.y >= (laser.y + 140);
    bool firing = obj_box[15]->rect.top > 307;

    if (!min && !max && firing) {
        if (sfMusic_getStatus(laser_death) != sfPlaying)
            sfMusic_play(laser_death);
        return true;
    }
    return false;
}

static bool missile_collide(sfSprite *player, game_object *obj, sfMusic *music)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(player);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(obj->spr);

    if (sfFloatRect_intersects(&rect1, &rect2, NULL)) {
        obj->rect.left = 135;
        sfSprite_setTextureRect(obj->spr, obj->rect);
        obj->vec.x = 0.0;
        if (sfMusic_getStatus(music) != sfPlaying)
            sfMusic_play(music);
        return true;
    }
    return false;
}

static bool zapper_collide(sfSprite *player, game_object *obj, sfMusic *music)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(player);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(obj->spr);

    if (sfFloatRect_intersects(&rect1, &rect2, NULL)) {
        if (sfMusic_getStatus(music) != sfPlaying)
            sfMusic_play(music);
        return true;
    }
    return false;
}

int check_death(int go_on, game_object **obj_box, sound_t **sound_box)
{
    if (go_on)
        return go_on;
    if (laser_collide(obj_box, sound_box[12]->music))
        return 1;
    if (missile_collide(obj_box[1]->spr, obj_box[13], sound_box[11]->music))
        return 1;
    if (zapper_collide(obj_box[1]->spr, obj_box[16], sound_box[13]->music))
        return 1;
    return 0;
}
