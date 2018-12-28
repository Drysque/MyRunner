/*
** EPITECH PROJECT, 2018
** spawn_obstacles.c
** File description:
**
*/

#include "runner.h"

static void random_spawn(game_object **obj_box, int line,
    sfVector2f front_player, sfVector2f indicated)
{
    int random_gen = rand() % 10;

    switch (random_gen) {
        case 0: sfSprite_setPosition(obj_box[13]->spr, front_player);
            printf("%s\n", "MISSILE");
            break;
        case 1: sfSprite_setPosition(obj_box[15]->spr, indicated);
        printf("%s\n", "LASER");
            break;
        case 2: case 3: printf("%s\n", "ELEC");
            break;
        default: printf("%s\n", "NOTHING");
            break;
    }
}

static void summon_obs(char *obstacles, game_object **obj_box, int line)
{
    sfVector2f front_player = {3200, sfSprite_getPosition(obj_box[1]->spr).y};
    sfVector2f indicated = {2025, (line * 223) + 80};

    if (line > 3)
        return;
    switch (obstacles[line]) {
        case '-': sfSprite_setPosition(obj_box[13]->spr, front_player);
            break;
        case 'x': //sfSprite_setPosition(obj_box[elec], sfVector2f(1000, 200))
            break;
        case '=': sfSprite_setPosition(obj_box[15]->spr, indicated);
            break;
        case 'i': random_spawn(obj_box, line, front_player, indicated);
            break;
        default: break;
    }
    summon_obs(obstacles, obj_box, ++line);
}

static bool set_obstacles(char **array_map, game_object **obj_box,
    sfClock *game_clock)
{
    char *obstacles = malloc(sizeof(char) * 4);
    static int current_slot = 0;

    //add score
    if (array_map[0][current_slot] == '\0')
        return false;
    for (int i = 0; i < 4; i++) {
        obstacles[i] = array_map[i][current_slot];
        printf("char:%c\\\n", array_map[i][current_slot]);
    }
    if (array_map[0][current_slot] != 'i')
        current_slot++;
    summon_obs(obstacles, obj_box, 0);
    sfClock_restart(game_clock);
    free(obstacles);
    return true;
}

bool spawn_obstacles(char **array_map, sfClock *game_clock,
    game_object **obj_box)
{
    sfInt64 elapsed = sfClock_getElapsedTime(game_clock).microseconds / 500000;

    if (elapsed > 6)
        return (set_obstacles(array_map, obj_box, game_clock));
    return true;
}
