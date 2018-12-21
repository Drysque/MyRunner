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
1 - Barry
2 - LabEntry (menu)
3 - Slide
4 - EmptySlide
5 - Slide2
6 - EmptySlide2
7 - Space-Space
8 - Earth-Space
9 - Earth
10 - Moon
11 - Mars
12 - Saturn
*/

typedef struct game_object_s
{
    sfTexture *tex;
    sfSprite *spr;
    sfVector2f vec;
    sfIntRect rect;
    sfClock *clock;
} game_object;

/*
0 - constant music
1 - menu
2 - Smash
3 - jet-on
4 - jet-off
*/

typedef struct sound_s
{
    sfMusic *music;
} sound_t;

void move_env(game_object **obj_box);
void play_sounds(sound_t **sound_box);
void move_barry(game_object **obj_box);
void create_my_sounds(sound_t **sound_box);
void create_my_sprites(game_object **obj_box);
void init_my_ressources(game_object **obj_box);
void close_my_window(sfRenderWindow *window, sfEvent event);
sfRenderWindow *create_my_window(int width, int height, int bpp);
void draw_my_sprites(sfRenderWindow *window, game_object **obj_box);
void create_my_ressources(sfRenderWindow *window, game_object **obj_box,
    sound_t **sound_box);
void destroy_my_ressources(sfRenderWindow *window, game_object **obj_box,
    sound_t **sounds);

#endif
