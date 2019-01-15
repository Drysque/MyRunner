/*
** EPITECH PROJECT, 2018
** my_runner.c
** File description:
** a finite running game
*/

#include "runner.h"

static bool wait_for_start(game_object **obj_box, sound_t **sound_box,
    sfRenderWindow *window)
{
    bool new_status = false;

    while (!new_status && sfRenderWindow_isOpen(window)) {
        close_my_window(window);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            new_status = true;
    }
    sfMusic_stop(sound_box[1]->music);
    sfMusic_play(sound_box[0]->music);
    sfMusic_play(sound_box[2]->music);
    sfSprite_setPosition(obj_box[1]->spr, (sfVector2f){500.0, 830.0});
    sfSprite_setPosition(obj_box[2]->spr, (sfVector2f){2000.0, 2000.0});
    return new_status;
}

int my_runner(char **av)
{
    sfRenderWindow *window = create_my_window(1920, 1080, 32);
    game_object **obj_box = malloc(sizeof(game_object *) * 18);
    sound_t **sound_box = malloc(sizeof(sound_t *) * 11);
    score_t *score = malloc(sizeof(score_t));
    sfClock *game_clock = sfClock_create();
    char **array_map = NULL;
    bool start_status = false;
    int go_on = 0;

    if ((array_map = file_to_array(av[1], array_map)) == NULL)
        go_on = 84;
    create_my_ressources(window, obj_box, sound_box, score);
    while (sfRenderWindow_isOpen(window) && (!go_on || go_on == 3)) {
        //
        draw_my_sprites(window, obj_box);
        sfRenderWindow_display(window);
        move_env(obj_box);
        move_barry(obj_box);
        move_obstacles(obj_box);
        play_sounds(obj_box, sound_box);
        update_score(obj_box, score);
        //
        if (!start_status)
            start_status = wait_for_start(obj_box, sound_box, window);
        close_my_window(window);
        //
        go_on = spawn_obstacles(array_map, game_clock, obj_box);
        monitor_death(window, &go_on, obj_box, sound_box);
    }
    destroy_my_ressources(window, obj_box, sound_box, score);
    return go_on;
}
