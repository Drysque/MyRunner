/*
** EPITECH PROJECT, 2018
** create_my_ressources.c
** File description:
** creates the game ressources
*/

#include "runner.h"

void create_my_ressources(sfRenderWindow *window, game_object **obj_box,
    sound_t **sound_box, score_t *score)
{
    sfRenderWindow_setFramerateLimit(window, 60);
    srand(time(NULL));
    for (int i = 0; i < 19; i++)
        obj_box[i] = malloc(sizeof(game_object));
    for (int i = 0; i < 14; i++)
        sound_box[i] = malloc(sizeof(sound_t));
    create_my_sprites(obj_box);
    create_my_sounds(sound_box);
    init_my_ressources(obj_box);
    init_my_score(score);
    sfMusic_play(sound_box[1]->music);
    sfMusic_setLoop(sound_box[0]->music, sfTrue);
    sfMusic_setLoop(sound_box[1]->music, sfTrue);
    sfMusic_setLoop(sound_box[3]->music, sfTrue);
}
