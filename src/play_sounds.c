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

    if (0 < width && width < 1920 && !playing)
        sfMusic_play(sound_box[5]->music);
    playing = sfMusic_getStatus(sound_box[6]->music) == sfPlaying;
    if (width > 3000 && !playing)
        sfMusic_play(sound_box[6]->music);
}

static void play_laser(game_object **obj_box, sound_t **sound_box)
{
    int width = sfSprite_getPosition(obj_box[15]->spr).x;
    bool charge_playing = sfMusic_getStatus(sound_box[7]->music) == sfPlaying;
    bool fire_playing = sfMusic_getStatus(sound_box[9]->music) == sfPlaying;

    if (width > 40 || width < 0);
    else if (width > 5) {
        if (!charge_playing)
            sfMusic_play(sound_box[7]->music);
    }
    else if (width > 0){
        if (!fire_playing) {
            sfMusic_play(sound_box[8]->music);
            sfMusic_play(sound_box[9]->music);
        }
    }
}

void play_sounds(game_object **obj_box, sound_t **sound_box)
{
    play_jetpack(sound_box);
    play_missile(obj_box, sound_box);
    play_laser(obj_box, sound_box);
}
