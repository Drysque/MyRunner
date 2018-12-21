/*
** EPITECH PROJECT, 2018
** my_runner.c
** File description:
** a finite running game
*/

#include "runner.h"

static bool wait_for_start(bool *start_status, game_object **obj_box,
    sound_t **sound_box)
{
    while (*start_status == false)
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            *start_status = true;
    sfMusic_stop(sound_box[1]->music);
    sfMusic_play(sound_box[0]->music);
    sfMusic_play(sound_box[2]->music);
    sfSprite_setPosition(obj_box[1]->spr, (sfVector2f){500.0, 830.0});
    sfSprite_setPosition(obj_box[2]->spr, (sfVector2f){2000.0, 2000.0});
    return (*start_status);
}

void my_runner(void)
{
    sfEvent event;
    sfRenderWindow *window = create_my_window(1920, 1080, 32);
    game_object **obj_box = malloc(sizeof(game_object *) * 13);
    sound_t **sound_box = malloc(sizeof(sound_t *) * 5);
    bool start_status = false;
    // sfText score = sfText_create();

    create_my_ressources(window, obj_box, sound_box);
    while (sfRenderWindow_isOpen(window)) {
        draw_my_sprites(window, obj_box);
        sfRenderWindow_display(window);
        if (!start_status)
            wait_for_start(&start_status, obj_box, sound_box);
        close_my_window(window, event);
        move_env(obj_box);
        move_barry(obj_box);
        play_sounds(sound_box);
        sfRenderWindow_clear(window, sfBlack);
    }
    destroy_my_ressources(window, obj_box, sound_box);
}
