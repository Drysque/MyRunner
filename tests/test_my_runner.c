/*
** EPITECH PROJECT, 2018
** test my runner
** File description:
** unit tests for my_runner
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "runner.h"

int my_runner(char **av);
int check_args(int ac, char **av, char **env);
void animate_screen(game_object **obj_box, sound_t **sound_box,
    sfRenderWindow *window, score_t *score);
void start_and_quit(bool *start_status, game_object **obj_box,
    sound_t **sound_box, sfRenderWindow *window);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_runner, test_my_runner)
{
    sfRenderWindow *window = create_my_window(1920, 1080, 32);
    game_object **obj_box = malloc(sizeof(game_object *) * 19);
    sound_t **sound_box = malloc(sizeof(sound_t *) * 14);
    score_t *score = malloc(sizeof(score_t));
    char **array_map = file_to_array("-i\0", array_map);
    bool start_status = true;
    int go_on = 0;

    if (!array_map)
        go_on = 84;
    create_my_ressources(window, obj_box, sound_box, score);
    animate_screen(obj_box, sound_box, window, score);
    start_and_quit(&start_status, obj_box, sound_box, window);
    go_on = spawn_obstacles(array_map, obj_box);
    monitor_death(window, &go_on, obj_box, sound_box);
    animate_death(window, obj_box, sound_box);
    destroy_my_ressources(window, obj_box, sound_box, score);
    cr_expect_eq(sfFalse, sfRenderWindow_isOpen(window));
}

Test(my_runner, unexisting_file, .init = redirect_all_stdout)
{
    char *av[] = {"./my_runner", "coucou", NULL};

    my_runner(av);
    cr_expect_stderr_eq_str("Could not open file\n");
}

Test(my_runner, invalid_file, .init = redirect_all_stdout)
{
    char *av[] = {"./my_runner", "Makefile", NULL};

    my_runner(av);
    cr_expect_stderr_eq_str("Invalid map\n");
}

Test(my_runner, my_null_env, .init = redirect_all_stdout)
{
    int ac = 1;
    char *av[] = {"./my_runner", NULL};
    char *env[] = {NULL};

    check_args(ac, av, env);
    cr_expect_stderr_eq_str("error\nNice try, but the program can't be used \
with an empty environment!\n");
}

Test(my_runner, my_usage1, .init = redirect_all_stdout)
{
    char *av[] = {"./my_runner", NULL};
    char *env[] = {"not null"};

    check_args(1, av, env);
    cr_expect_stdout_eq_str("USAGE:\n\t\
./my_runner <file>\n\t\tlaunches the game with the given map\n\t\
./my_runner -i\n\t\tlaunches the game in infinite mode and random obstacles\n\t\
./my_runner -h\n\t\tdisplays this message and quits\n\t\
./my_runner -m\n\t\tdisplays a message to help you build your map and quits\n\t\
./my_runner -e\n\t\tdisplays an example of a map and quits\n\
\nDESCRIPTION:\n\tMy_runner is a finite running game\n\
\tBuild your own map with obstacles\n\tPress SPACE to play\n\
\tPress Escape to quit\n\tHave fun!\n\nRETURN VALUES:\n\
\t0: Player left the game with escape\n\t1: Player died\n\
\t2: Victory\n\t84: Game could not launch (invalid map, ...)\n");
}

Test(my_runner, my_usage2, .init = redirect_all_stdout)
{
    char *av[] = {"./my_runner", "-h", NULL};
    char *env[] = {"not null"};

    check_args(2, av, env);
    cr_expect_stdout_eq_str("USAGE:\n\t\
./my_runner <file>\n\t\tlaunches the game with the given map\n\t\
./my_runner -i\n\t\tlaunches the game in infinite mode and random obstacles\n\t\
./my_runner -h\n\t\tdisplays this message and quits\n\t\
./my_runner -m\n\t\tdisplays a message to help you build your map and quits\n\t\
./my_runner -e\n\t\tdisplays an example of a map and quits\n\
\nDESCRIPTION:\n\tMy_runner is a finite running game\n\
\tBuild your own map with obstacles\n\tPress SPACE to play\n\
\tPress Escape to quit\n\tHave fun!\n\nRETURN VALUES:\n\
\t0: Player left the game with escape\n\t1: Player died\n\
\t2: Victory\n\t84: Game could not launch (invalid map, ...)\n");
}

Test(my_runner, my_obs, .init = redirect_all_stdout)
{
    char *av[] = {"./my_runner", "-m", NULL};
    char *env[] = {"not null"};

    check_args(2, av, env);
    cr_expect_stdout_eq_str("How to build a map? Good Question.\n\n\tFirst, \
you must create a readable file with 4 lines.\n\tThe first line will contain \
the obstacles for the ceiling, the second and third one for the middle of the \
screen and the fourth one for the ground.\n\nThere are different types of \
obstacles:\n\ta \'-\' will summon a homing missile. It will target the player \
no matter where you place it.\n\ta \'=\' will summon a laser that charges and \
shoots after a period of time.\n\ta \'x\' will summon a electrical field that \
doesn't move.\nA blank space is used to separate obstacles.\nAny collision \
with these obstacles will lead to death.\nThe game is considered finished when \
the game reaches the end of a line.\nIf you have trouble getting the length of \
each lines to match because of trailing spaces being deleted when a file is \
saved, you can use a \'\\\' at the end of the lines.\n\nIf the file contains \
any other character, the map is considered false and the game won't launch.\n\
If the file has more than 4 lines, the map is considered false and the game \
won't launch.\nIf the lines are of different length, the map is considered \
false and the game won't launch.\n\nRelaunch with -e for examples.\n");
}

Test(my_runner, my_example, .init = redirect_all_stdout)
{
    int ac = 2;
    char *av[] = {"./my_runner", "-e", NULL};
    char *env[] = {"not null"};

    check_args(ac, av, env);
    cr_expect_stdout_eq_str("EXAMPLES: Copy-paste them in a .txt file\nShort \
map with \\s to indicate the end of the game:\nx -\\\n   \\\n = \\\n   \
\\\nStandard long map:\n=   x -x=-=   x -x=-=   x -x=-\\\n  -x = = x  -x = = \
x  -x = = x\\\n- = - x  =- = - x  =- = - x  =\\\nx x = = x x x   = x x x   = x \
\\\n");
}

Test(my_runner, test_lib)
{
    char *str1 = "coucou\n";
    char *str0 = my_itoa(-4, 1);
    char *str2 = my_itoa(1, 0);
    char *str = my_strcat(str1, str2);
    char **array = my_str_to_line_array(str);
}
