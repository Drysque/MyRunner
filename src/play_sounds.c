/*
** EPITECH PROJECT, 2018
** play_sounds.c
** File description:
** plays the sounds when needed
*/

#include "runner.h"

static void play_jetpack(sound_t **sound_box)
{
    bool playing = sfMusic_getStatus(sound_box[3]->music) == sfPlaying;

    if (sfKeyboard_isKeyPressed(sfKeySpace) && !playing)
        sfMusic_play(sound_box[3]->music);
    else if (!sfKeyboard_isKeyPressed(sfKeySpace) && playing) {
        sfMusic_play(sound_box[4]->music);
        sfMusic_pause(sound_box[3]->music);
    }
}

static void play_missile(game_object **obj_box, sound_t **sound_box)
{
    int width = sfSprite_getPosition(obj_box[13]->spr).x;
    bool playing = sfMusic_getStatus(sound_box[5]->music) == sfPlaying;
    bool playing2 = sfMusic_getStatus(sound_box[6]->music) == sfPlaying;

    if (0 < width && width < 1920 && !playing)
        sfMusic_play(sound_box[5]->music);
    if (width > 3000 && !playing2)
        sfMusic_play(sound_box[6]->music);
}

void play_sounds(game_object **obj_box, sound_t **sound_box)
{
    play_jetpack(sound_box);
    play_missile(obj_box, sound_box);
}
