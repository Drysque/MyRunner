/*
** EPITECH PROJECT, 2018
** draw_my_sprites
** File description:
** draw the sprites on the window
*/

#include "runner.h"

static void sprite_drawer(sfRenderWindow *window, game_object **obj_box,
    char *str)
{
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawSprite(window, obj_box[str[i] - 48]->spr, NULL);
}

void draw_my_sprites(sfRenderWindow *window, game_object **obj_box)
{
    sfRenderWindow_drawSprite(window, obj_box[7]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[8]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[12]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[11]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[9]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[10]->spr, NULL);
    sprite_drawer(window, obj_box, "023456");
    sfRenderWindow_drawSprite(window, obj_box[1]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[13]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[14]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[15]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[16]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[17]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[18]->spr, NULL);
}
