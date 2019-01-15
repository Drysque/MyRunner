/*
** EPITECH PROJECT, 2018
** animate_death.c
** File description:
** animates the death
*/

#include "runner.h"

static void after_death_warning(game_object **obj_box)
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

static void after_death_zapper(game_object *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->clock);

    if (time.microseconds > 100000.0) {
        if (obj->rect.top + 48 >= (48 * 4) + 0)
            obj->rect.top = 0;
        else
            obj->rect.top += 48;
        sfClock_restart(obj->clock);
    }
    sfSprite_setTextureRect(obj->spr, obj->rect);
}

static void after_death_obstacles(game_object **obj_box, int move)
{
    int missile_width = sfSprite_getPosition(obj_box[13]->spr).x;
    int laser_width = sfSprite_getPosition(obj_box[15]->spr).x;
    int zapper_width = sfSprite_getPosition(obj_box[16]->spr).x;

    if (missile_width > -150)
        move_missile(obj_box[13]);
    if (laser_width > -2000)
        move_laser(obj_box[15], laser_width);
    if (zapper_width > -400)
        after_death_zapper(obj_box[16]);
    after_death_warning(obj_box);
    obj_box[1]->rect.left = 177;
    obj_box[1]->rect.top = 0;
    sfSprite_setTextureRect(obj_box[1]->spr, obj_box[1]->rect);
    if (sfSprite_getPosition(obj_box[1]->spr).y < 800) {
        if (sfSprite_getPosition(obj_box[1]->spr).y < 149)
            obj_box[1]->vec.y = 0.0;
        sfSprite_move(obj_box[1]->spr,
            (sfVector2f){0.0, obj_box[1]->vec.y += 0.3});
    }
}

static void after_death_env(game_object *obj, int too_far, float move)
{
    if (sfSprite_getPosition(obj->spr).x >= too_far)
        sfSprite_move(obj->spr, (sfVector2f){move, 0.0});
    else
        sfSprite_setPosition(obj->spr, (sfVector2f){2196.0, 13.0});
}

void animate_death(sfRenderWindow *window, game_object **obj_box,
    sound_t **sound_box)
{
    sfClock *death_clock = sfClock_create();
    float move = -9.0;

    while (sfClock_getElapsedTime(death_clock).microseconds / 500000 < 4) {
        play_sounds(obj_box, sound_box);
        after_death_env(obj_box[3], -740, move);
        after_death_env(obj_box[4], -740, move);
        after_death_env(obj_box[5], -740, move);
        after_death_env(obj_box[6], -740, move);
        after_death_env(obj_box[16], -740, move);
        draw_my_sprites(window, obj_box);
        sfRenderWindow_display(window);
        after_death_obstacles(obj_box, move);
        move = (move < 0) ? move + 0.1 : 0;
    }
}
