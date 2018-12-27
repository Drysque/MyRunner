/*
** EPITECH PROJECT, 2018
** play_sounds.c
** File description:
** plays the sounds when needed
*/

#include "runner.h"

void play_sounds(game_object **obj_box, sound_t **sound_box)
{
    bool playing = sfMusic_getStatus(sound_box[3]->music) == sfPlaying;

    if (sfKeyboard_isKeyPressed(sfKeySpace) && !playing)
        sfMusic_play(sound_box[3]->music);
    else if (!sfKeyboard_isKeyPressed(sfKeySpace) && playing) {
        sfMusic_play(sound_box[4]->music);
        sfMusic_pause(sound_box[3]->music);
    }
}
