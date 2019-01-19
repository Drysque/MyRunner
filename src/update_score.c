/*
** EPITECH PROJECT, 2018
** update_score.c
** File description:
** updates the score
*/

#include "runner.h"

void update_score(game_object **obj_box, score_t *score)
{
    score->score_number -= obj_box[3]->vec.x;
    sfText_setString(score->score_str,
        my_strcat("Score: ", my_itoa(score->score_number / 100, 0)));
}
