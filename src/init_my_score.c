/*
** EPITECH PROJECT, 2018
** init_my_score.c
** File description:
** inits the score
*/

#include "runner.h"

void init_my_score(score_t *score)
{
    score->score_number = 0;
    score->font = sfFont_createFromFile("font/NewAthleticM54.ttf");
    score->score_str = sfText_create();
    sfText_setFont(score->score_str, score->font);
    sfText_setCharacterSize(score->score_str, 50);
    sfText_setString(score->score_str, "Score: 0");
    sfText_setPosition(score->score_str, (sfVector2f){1685.0, 100.0});
}
