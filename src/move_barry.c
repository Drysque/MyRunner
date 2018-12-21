/*
** EPITECH PROJECT, 2018
** move_barry.c
** File description:
** takes care of barry's animation
*/

#include "runner.h"

static void move_barry_rect(sfIntRect *rect, int reset, int offset)
{
    if (rect->left + offset >= (offset * 3) + reset)
        rect->left = reset;
    else
        rect->left += offset;
}

static void barry_run(game_object *obj, int height)
{
    sfTime time = sfClock_getElapsedTime(obj->clock);

    if (time.microseconds > 100000.0) {
        if (height > 828) {
            obj->rect.top = 0;
            move_barry_rect(&obj->rect, 0, 59);
            sfClock_restart(obj->clock);
        }
        // if (height <= 828) {
        else {
            obj->rect.top = 66;
            move_barry_rect(&obj->rect, 59, 59);
            sfClock_restart(obj->clock);
        }
    }
    sfSprite_setTextureRect(obj->spr, obj->rect);
}

static void barry_jump(game_object *obj, int height)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && height > 150)//go up
        obj->vec.y += -0.1;
    else if (height < 830)// go down
        obj->vec.y += 0.1;
    if (height >= 150 && height <= 830)//entre les 2
        sfSprite_move(obj->spr, obj->vec);
    else if (height < 150) {//over
        sfSprite_setPosition(obj->spr, (sfVector2f){500.0, 151.0});
        obj->vec.y = 0.0;
    }
    else {
        sfSprite_setPosition(obj->spr, (sfVector2f){500.0, 829.0});
        obj->vec.y = 0.0;
    }
}

void move_barry(game_object **obj_box)
{
    int height = sfSprite_getPosition(obj_box[1]->spr).y;

    barry_jump(obj_box[1], height);
    barry_run(obj_box[1], height);
}
