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
16 - Zapper SS
17 - Game Over
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
10 - zapper-fire

11 - missile-death
12 - laser-death
13 - zapper - death
*/

typedef struct sound_s
{
    sfMusic *music;
} sound_t;

typedef struct score_s
{
    long unsigned int score_number;
    sfFont *font;
    sfText *score_str;//display of score
} score_t;

int my_strlen(char const *str);
int get_lines(char const *str);
char *my_itoa(int nbr, int neg);
char **read_me(char const *filepath);
char *my_strcat(char *buffer, char *str);
char **my_str_to_line_array(char const *str);
char **file_to_array(char const *str, char **array);
void my_strncpy(char *dest, char const *src, int n);

void move_zapper(game_object *obj);
void move_missile(game_object *obj);
void move_env(game_object **obj_box);
void move_barry(game_object **obj_box);
void move_obstacles(game_object **obj_box);
void create_my_sounds(sound_t **sound_box);
void close_my_window(sfRenderWindow *window);
void move_laser(game_object *obj, int width);
void create_my_sprites(game_object **obj_box);
void init_my_ressources(game_object **obj_box);
int check_death(int go_on, game_object **obj_box);
void update_score(game_object **obj_box, score_t *score);
void init_my_score(sfRenderWindow *window, score_t *score);
void play_sounds(game_object **obj_box, sound_t **sound_box);
sfRenderWindow *create_my_window(int width, int height, int bpp);
void draw_my_sprites(sfRenderWindow *window, game_object **obj_box);
void monitor_death(sfRenderWindow *window, int *go_on,
    game_object **obj_box, sound_t **sound_box);
int spawn_obstacles(char **array_map, sfClock *game_clock,
    game_object **obj_box);
void animate_death(sfRenderWindow *window, game_object **obj_box,
    sound_t **sound_box);
void create_my_ressources(sfRenderWindow *window, game_object **obj_box,
    sound_t **sound_box, score_t *score);
void destroy_my_ressources(sfRenderWindow *window, game_object **obj_box,
    sound_t **sound_box, score_t *score);

#endif
