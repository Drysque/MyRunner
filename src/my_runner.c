/*
** EPITECH PROJECT, 2018
** my_runner.c
** File description:
** -
*/

#include <stdlib.h>
#include "runner.h"

void my_runner(void)
{
    sfEvent event;
    sfRenderWindow *window = create_my_window(1920, 1080, 32);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        close_my_window(window, event);
    }
    sfRenderWindow_destroy(window);
}
