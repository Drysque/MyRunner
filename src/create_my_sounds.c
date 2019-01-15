/*
** EPITECH PROJECT, 2018
** create_my_sounds.c
** File description:
** creates the sounds
*/

#include "runner.h"

static void create_music(sound_t *sound, char const *path)
{
    sound->music = sfMusic_createFromFile(path);
}

void create_my_sounds(sound_t **sound_box)
{
    create_music(sound_box[0], "./sound_src/Joyride.ogg");
    create_music(sound_box[1], "./sound_src/class.ogg");
    create_music(sound_box[2], "./sound_src/smash.wav");
    create_music(sound_box[3], "./sound_src/jet_on.wav");
    create_music(sound_box[4], "./sound_src/jet_off.wav");
    create_music(sound_box[5], "./sound_src/missile_on.wav");
    create_music(sound_box[6], "./sound_src/missile_warning.wav");
    create_music(sound_box[7], "./sound_src/laser_warning.wav");
    create_music(sound_box[8], "./sound_src/laser_start.wav");
    create_music(sound_box[9], "./sound_src/laser_fire.ogg");
    create_music(sound_box[10], "./sound_src/zapper_fire.wav");
    sfMusic_setVolume(sound_box[0]->music, 35.0);
    sfMusic_setVolume(sound_box[1]->music, 35.0);
    sfMusic_setVolume(sound_box[2]->music, 35.0);
}
