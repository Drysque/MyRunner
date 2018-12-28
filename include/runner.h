/*
** EPITECH PROJECT, 2018
** runner.h
** File description:
** includes protos for my_runner
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <stdio.h>

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

/*
0 - LabEmpty
1 - Barry SS
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
13 - Missile SS
14 - Missile Warn
15 - Laser SS
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
5 - missile-on
6 - missile-warn
7 - laser-warn
8 - laser-start
9 - laser-fire-stop
*/

typedef struct sound_s
{
    sfMusic *music;
} sound_t;

int my_strlen(char const *str);

void move_laser(game_object *obj, int width);
void move_missile(game_object *obj);
void move_env(game_object **obj_box);
char **read_me(char const *filepath);
void move_barry(game_object **obj_box);
void move_obstacles(game_object **obj_box);
void create_my_sounds(sound_t **sound_box);
char **my_str_to_line_array(char const *str);
void create_my_sprites(game_object **obj_box);
void init_my_ressources(game_object **obj_box);
char **file_to_array(char const *str, char **array);
void my_strncpy(char *dest, char const *src, int n);
void close_my_window(sfRenderWindow *window, sfEvent event);
void play_sounds(game_object **obj_box, sound_t **sound_box);
sfRenderWindow *create_my_window(int width, int height, int bpp);
void draw_my_sprites(sfRenderWindow *window, game_object **obj_box);
bool spawn_obstacles(char **array_map, sfClock *game_clock,
    game_object **obj_box);
void create_my_ressources(sfRenderWindow *window, game_object **obj_box,
    sound_t **sound_box);
void destroy_my_ressources(sfRenderWindow *window, game_object **obj_box,
    sound_t **sounds);

#endif
