/*
** EPITECH PROJECT, 2018
** move_barry.c
** File description:
** takes care of barry's animation
*/

#include "runner.h"

static void move_barry_rect(game_object *obj, int top, int reset, int offset)
{
    obj->rect.top = top;
    if (obj->rect.left + offset >= (offset * 3) + reset)
        obj->rect.left = reset;
    else
        obj->rect.left += offset;
    sfClock_restart(obj->clock);
}

static void barry_run(game_object *obj, int height)
{
    sfTime time = sfClock_getElapsedTime(obj->clock);

    if (time.microseconds > 100000.0) {
        if (height > 828)
            move_barry_rect(obj, 0, 0, 59);
        else if (sfKeyboard_isKeyPressed(sfKeySpace))
            move_barry_rect(obj, 66, 59, 59);
        else
            obj->rect.left = 0;
    }
    sfSprite_setTextureRect(obj->spr, obj->rect);
}

static void barry_jump(game_object *obj, int height)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && height > 150)
        obj->vec.y += -0.6;
    else if (height < 830)
        obj->vec.y += 0.6;
    obj->vec.y = obj->vec.y + 0;
    if (height >= 150 && height <= 830)
        sfSprite_move(obj->spr, obj->vec);
    else if (height < 150) {
        sfSprite_setPosition(obj->spr, (sfVector2f){500.0, 151.0});
        obj->vec.y = 0.0;
    }
    else if (sfKeyboard_isKeyPressed(sfKeySpace)) {
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
