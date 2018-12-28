/*
** EPITECH PROJECT, 2018
** destroy_my_ressources.c
** File description:
** destoys the game ressources
*/

#include "runner.h"

static void free_all(game_object **obj_box, sound_t **sound_box)
{
    for (int i = 0; i < 16; i++)
        free(obj_box[i]);
    for (int i = 0; i < 10; i++)
        free(sound_box[i]);
    free(obj_box);
    free(sound_box);
}

static void destroy_env(game_object *obj)
{
    sfTexture_destroy(obj->tex);
    sfSprite_destroy(obj->spr);
}

static void destroy_music(sound_t *sound)
{
    sfMusic_stop(sound->music);
    sfMusic_destroy(sound->music);
}

void destroy_my_ressources(sfRenderWindow *window, game_object **obj_box,
    sound_t **sound_box)
{
    sfRenderWindow_destroy(window);
    destroy_env(obj_box[0]);
    destroy_env(obj_box[1]);
    destroy_env(obj_box[2]);
    destroy_env(obj_box[3]);
    destroy_env(obj_box[4]);
    destroy_env(obj_box[5]);
    destroy_env(obj_box[6]);
    destroy_env(obj_box[7]);
    destroy_env(obj_box[8]);
    destroy_env(obj_box[9]);
    destroy_env(obj_box[10]);
    destroy_env(obj_box[11]);
    destroy_env(obj_box[12]);
    destroy_env(obj_box[13]);
    destroy_env(obj_box[14]);
    destroy_env(obj_box[15]);
    destroy_music(sound_box[0]);
    destroy_music(sound_box[1]);
    destroy_music(sound_box[2]);
    destroy_music(sound_box[3]);
    destroy_music(sound_box[4]);
    destroy_music(sound_box[5]);
    destroy_music(sound_box[6]);
    destroy_music(sound_box[7]);
    destroy_music(sound_box[8]);
    destroy_music(sound_box[9]);
    free_all(obj_box, sound_box);
}
