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
    score->score_disp = sfText_create();
}
