/*
** EPITECH PROJECT, 2018
** spawn_obstacles.c
** File description:
**
*/

#include "runner.h"

/*while arraymap pas fini, faire apparaitre les objets lus.
'-i' = map avec 1 colonne de 'i'. Lecture = lit une colonne
et passe à la suivante si char != i
si colonne lu = i, aléatoire et ne pas apsser à la suivante
*/

static void summon_obs(char *obstacles, game_object **obj_box, int line)
{
    if (line > 3)
        return;
    // printf("line:%d\\\n", line);
    switch (obstacles[line]) {
        case '-': sfSprite_setPosition(obj_box[13]->spr, (sfVector2f){2000, (line + 1) * 200});
            break;
        case 'x': //sfSprite_setPosition(obj_box[elec], sfVector2f(1000, 200))
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
    if (array_map[0][current_slot] == '\0') {//reached end of map
        printf("%s\n", "STOP");
        return false;
    }
    printf("%d\n", current_slot);
    for (int i = 0; i < 4; i++) {//read obs
        obstacles[i] = array_map[i][current_slot];
        printf("char:%c\\\n", array_map[i][current_slot]);
    }
    // printf("time: %d\n", current_slot);
    if (array_map[0][current_slot] != 'i') //if not infinite, move to next one
        current_slot++;
    summon_obs(obstacles, obj_box, 0);
    sfClock_restart(game_clock);
    free(obstacles);
    return true;
}

bool spawn_obstacles(char **array_map, sfClock *game_clock,
    game_object **obj_box, sound_t **sound_box)
{
    sfInt64 elapsed = sfClock_getElapsedTime(game_clock).microseconds / 500000;

    // if (elapsed > 3)
    if (elapsed > 1)
        return (set_obstacles(array_map, obj_box, game_clock));
    return true;
}
