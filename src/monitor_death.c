/*
** EPITECH PROJECT, 2018
** monitor_obstacles.c
** File description:
** manages collisions
*/

#include "runner.h"

static void animate_victory(sfRenderWindow *window,
    game_object **obj_box, int *go_on)
{
    static unsigned char alpha = 0;
    static sfClock *victory_clock = NULL;

    if (!victory_clock)
        victory_clock = sfClock_create();
    if (alpha < 255)
        sfSprite_setColor(obj_box[17]->spr, (sfColor){255, 255, 255, alpha++});
    else
        while (sfRenderWindow_isOpen(window)) {
            close_my_window(window);
            *go_on = 2;
        }
}

void monitor_death(sfRenderWindow *window, int *go_on,
    game_object **obj_box, sound_t **sound_box)
{
    *go_on = check_death(*go_on, obj_box, sound_box);
    if (*go_on == 1)
        animate_death(window, obj_box, sound_box);
    if (*go_on == 3)
        animate_victory(window, obj_box, go_on);
}
