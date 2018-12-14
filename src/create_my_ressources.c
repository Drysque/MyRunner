/*
** EPITECH PROJECT, 2018
** create_my_ressources.c
** File description:
** creates the game ressources
*/

#include "runner.h"

void create_my_ressources(game_object **obj_box, sound_t **sound_box)
{
    for (int i = 0; i < 4; i++)
        obj_box[i] = malloc(sizeof(game_object));
    for (int i = 0; i < 3; i++)
        sound_box[i] = malloc(sizeof(sound_t));
    create_my_sprites(obj_box);
    create_my_sounds(sound_box);
    init_my_ressources(obj_box);
    sfMusic_play(sound_box[1]->music);
}
