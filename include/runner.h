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

sfRenderWindow *create_my_window(int width, int height, int bpp);
void close_my_window(sfRenderWindow *window, sfEvent event);

#endif
