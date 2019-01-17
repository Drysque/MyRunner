/*
** EPITECH PROJECT, 2018
** spawn_obstacles.c
** File description:
** spawns the obstacles
*/

#include "runner.h"

static void random_spawn(game_object **obj_box, sfVector2f front_player,
    sfVector2f ind_laser, sfVector2f ind_zapper)
{
    int random_gen = rand() % 5;

    switch (random_gen) {
        case 0: sfSprite_setPosition(obj_box[13]->spr, front_player);
            break;
        case 1: sfSprite_setPosition(obj_box[15]->spr, ind_laser);
            break;
        case 2: case 3: sfSprite_setPosition(obj_box[16]->spr, ind_zapper);
            break;
        default: break;
    }
}

static void summon_obs(char *obstacles, game_object **obj_box, int line)
{
    sfVector2f front_player = {3200, sfSprite_getPosition(obj_box[1]->spr).y};
    sfVector2f ind_laser = {2025, (line * 223) + 80};
    sfVector2f ind_zapper = {1920, (line * 217) + 150};

    if (line > 3)
        return;
    switch (obstacles[line]) {
        case '-': sfSprite_setPosition(obj_box[13]->spr, front_player);
            break;
        case 'x': sfSprite_setPosition(obj_box[16]->spr, ind_zapper);
            break;
        case '=': sfSprite_setPosition(obj_box[15]->spr, ind_laser);
            break;
        case 'i': random_spawn(obj_box, front_player, ind_laser, ind_zapper);
            break;
        default: break;
    }
    summon_obs(obstacles, obj_box, ++line);
}

static int set_obstacles(char **array_map, game_object **obj_box,
    sfClock *game_clock)
{
    char *obstacles = malloc(sizeof(char) * 4);
    static int current_slot = 0;

    if (array_map[0][current_slot] == '\0')
        return 3;
    for (int i = 0; i < 4; i++)
        obstacles[i] = array_map[i][current_slot];
    if (array_map[0][current_slot] != 'i')
        current_slot++;
    summon_obs(obstacles, obj_box, 0);
    sfClock_restart(game_clock);
    free(obstacles);
    return 0;
}

int spawn_obstacles(char **array_map, game_object **obj_box)
{
    static sfClock *game_clock = NULL;
    sfInt64 elapsed = 0;

    if (game_clock == NULL)
        game_clock = sfClock_create();
    elapsed = sfClock_getElapsedTime(game_clock).microseconds / 500000;
    if (elapsed > 8)
        return (set_obstacles(array_map, obj_box, game_clock));
    return 0;
}
