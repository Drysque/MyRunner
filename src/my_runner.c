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

static void start_and_quit(bool *start_status, game_object **obj_box,
    sound_t **sound_box, sfRenderWindow *window)
{
    if (!(*start_status))
        *start_status = wait_for_start(obj_box, sound_box, window);
    close_my_window(window);
}

static void animate_screen(game_object **obj_box, sound_t **sound_box,
    sfRenderWindow *window, score_t *score)
{
    draw_my_sprites(window, obj_box);
    sfRenderWindow_drawText(window, score->score_str, NULL);
    sfRenderWindow_display(window);
    move_env(obj_box);
    move_barry(obj_box);
    move_obstacles(obj_box);
    play_sounds(obj_box, sound_box);
    update_score(obj_box, score);
}

int my_runner(char **av)
{
    sfRenderWindow *window = create_my_window(1920, 1080, 32);
    game_object **obj_box = malloc(sizeof(game_object *) * 19);
    sound_t **sound_box = malloc(sizeof(sound_t *) * 14);
    score_t *score = malloc(sizeof(score_t));
    char **array_map = file_to_array(av[1], array_map);
    bool start_status = false;
    int go_on = 0;

    if (!array_map)
        go_on = 84;
    create_my_ressources(window, obj_box, sound_box, score);
    while (sfRenderWindow_isOpen(window) && (!go_on || go_on == 3)) {
        animate_screen(obj_box, sound_box, window, score);
        start_and_quit(&start_status, obj_box, sound_box, window);
        go_on = spawn_obstacles(array_map, obj_box);
        monitor_death(window, &go_on, obj_box, sound_box);
    }
    destroy_my_ressources(window, obj_box, sound_box, score);
    return go_on;
}
