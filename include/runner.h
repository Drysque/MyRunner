/*
** EPITECH PROJECT, 2018
** runner.h
** File description:
** includes protos for my_runner
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/*
0 - LabEmpty
1 - Slide
2 - menu
*/

typedef struct game_object_s
{
    sfTexture *tex;
    sfSprite *spr;
    sfVector2f vec;
    sfIntRect rect;
} game_object;

/*
0 - menu
1 - constant music
*/

typedef struct sound_s
{
    sfMusic *music;
} sound_t;

void create_my_sounds(sound_t **sound_box);
void create_my_sprites(game_object **obj_box);
void init_my_ressources(game_object **obj_box);
void close_my_window(sfRenderWindow *window, sfEvent event);
sfRenderWindow *create_my_window(int width, int height, int bpp);
void create_my_ressources(game_object **obj_box, sound_t **sounds);
void draw_my_sprites(sfRenderWindow *window, game_object **obj_box);
void destroy_my_ressources(sfRenderWindow *window, game_object **obj_box,
    sound_t **sounds);

#endif
