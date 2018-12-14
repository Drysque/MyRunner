/*
** EPITECH PROJECT, 2018
** draw_my_sprites
** File description:
** draw the sprites on the window
*/

#include "runner.h"

void draw_my_sprites(sfRenderWindow *window, game_object **obj_box)
{
    sfRenderWindow_drawSprite(window, obj_box[0]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[1]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[2]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[3]->spr, NULL);
}
