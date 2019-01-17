/*
** EPITECH PROJECT, 2018
** destroy_my_ressources.c
** File description:
** destoys the game ressources
*/

#include "runner.h"

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
    sound_t **sound_box, score_t *score)
{
    sfRenderWindow_destroy(window);
    for (int i = 0; i < 19; i++) {
        destroy_env(obj_box[i]);
        free(obj_box[i]);
    }
    for (int i = 0; i < 14; i++) {
        destroy_music(sound_box[i]);
        free(sound_box[i]);
    }
    free(obj_box);
    free(sound_box);
    sfText_destroy(score->score_str);
    sfFont_destroy(score->font);
    free(score);
}
