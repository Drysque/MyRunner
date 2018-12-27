/*
** EPITECH PROJECT, 2018
** my_runner.c
** File description:
** a finite running game
*/

#include "runner.h"

static void wait_for_start(bool *start_status, game_object **obj_box,
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
}

int my_runner(char **av)
{
    sfEvent event;
    sfRenderWindow *window = create_my_window(1920, 1080, 32);
    game_object **obj_box = malloc(sizeof(game_object *) * 14);
    sound_t **sound_box = malloc(sizeof(sound_t *) * 5);
    char **array_map = file_to_array(av[1], array_map);
    sfClock *game_clock = sfClock_create();
    bool start_status = false;
    bool go_on = true;

    if (array_map == NULL)
        go_on = false;
    printf("%s\n", "into array done");
    create_my_ressources(window, obj_box, sound_box);
    printf("%s\n", "launching game");
    while (sfRenderWindow_isOpen(window) && go_on) {
        draw_my_sprites(window, obj_box);
        sfRenderWindow_display(window);
        if (!start_status)
            wait_for_start(&start_status, obj_box, sound_box);
        close_my_window(window, event);
        move_env(obj_box);
        move_barry(obj_box);
        move_obstacles(obj_box);
        go_on = spawn_obstacles(array_map, game_clock, obj_box, sound_box); //will just read the array and teleport sprite in front of player (or random in infite). move_env will take care of the rest
        if (!go_on)
            printf("%s\n", "leaving by end of map");
        play_sounds(obj_box, sound_box);
        // sfRenderWindow_clear(window, sfBlack); useless now
    }
    destroy_my_ressources(window, obj_box, sound_box);
    printf("%s\n", "ending game.the array was: ");
    for (int i = 0; array_map && array_map[i]; i++)
        printf("%s\n", array_map[i]);
    return 0;
}
