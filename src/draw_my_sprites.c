/*
** EPITECH PROJECT, 2018
** draw_my_sprites
** File description:
** draw the sprites on the window
*/

#include "runner.h"

// static void sprite_drawer(sfRenderWindow *window, game_object **obj_box,
//     char *str)
// {
//     for (int i = 0; i < 13; i++)
//         sfRenderWindow_drawSprite(window, obj_box[str[i] - 48]->spr, NULL);
// }

void draw_my_sprites(sfRenderWindow *window, game_object **obj_box)
{
    //for
    sfRenderWindow_drawSprite(window, obj_box[7]->spr, NULL);//stars
    sfRenderWindow_drawSprite(window, obj_box[8]->spr, NULL);

    sfRenderWindow_drawSprite(window, obj_box[12]->spr, NULL);//planets
    sfRenderWindow_drawSprite(window, obj_box[11]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[9]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[10]->spr, NULL);

    sfRenderWindow_drawSprite(window, obj_box[0]->spr, NULL);//hallway
    sfRenderWindow_drawSprite(window, obj_box[2]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[3]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[4]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[5]->spr, NULL);
    sfRenderWindow_drawSprite(window, obj_box[6]->spr, NULL);

    sfRenderWindow_drawSprite(window, obj_box[1]->spr, NULL);//barry
    sfRenderWindow_drawSprite(window, obj_box[13]->spr, NULL);//missile
    sfRenderWindow_drawSprite(window, obj_box[14]->spr, NULL);//missile
    //
    // sprite_drawer(window, obj_box, "780234561");
}
