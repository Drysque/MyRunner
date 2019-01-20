/*
** EPITECH PROJECT, 2018
** my_usage.c
** File description:
** prints the usage for my_runner
*/

#include <stdlib.h>
#include <unistd.h>
#include "runner.h"

static bool my_example(void)
{
    char const example[] = "EXAMPLES: Copy-paste them in a .txt file\nShort \
map with \\s to indicate the end of the game:\nx -\\\n   \\\n = \\\n   \\\n\
Standard long map:\n=   x -x=-=   x -x=-=   x -x=-\\\n  -x = = x  -x = = x  -x \
= = x\\\n- = - x  =- = - x  =- = - x  =\\\nx x = = x x x   = x x x   = x \\\n";

    write(1, example, my_strlen(example));
    return false;
}

static bool my_obs(void)
{
    char const obs[] = "How to build a map? Good Question.\n\n\tFirst, you \
must create a readable file with 4 lines.\n\tThe first line will contain the \
obstacles for the ceiling, the second and third one for the middle of the \
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
false and the game won't launch.\n\nRelaunch with -e for examples, or use the \
maps folder.\n";

    write(1, obs, my_strlen(obs));
    return false;
}

static bool my_usage(void)
{
    char const usage[] = "USAGE:\n\t\
./my_runner <file>\n\t\tlaunches the game with the given map\n\t\
./my_runner -i\n\t\tlaunches the game in infinite mode and random obstacles\n\t\
./my_runner -h\n\t\tdisplays this message and quits\n\t\
./my_runner -m\n\t\tdisplays a message to help you build your map and quits\n\t\
./my_runner -e\n\t\tdisplays an example of a map and quits\n\
\nDESCRIPTION:\n\
\tMy_runner is a finite running game\n\
\tBuild your own map with obstacles\n\
\tPress SPACE to play\n\
\tPress Escape to quit\n\
\tHave fun!\n\
\nRETURN VALUES:\n\
\t0: Player left the game with escape\n\
\t1: Player died\n\
\t2: Victory\n\
\t84: Game could not launch (invalid map, ...)\n";

    write(1, usage, my_strlen(usage));
    return false;
}

static bool my_null_env(void)
{
    char const error[] = "error\n";
    char const try[] = "Nice try, but the program can't be ";
    char const env[] = "used with an empty environment!\n";

    write(2, error, my_strlen(error));
    write(2, try, my_strlen(try));
    write(2, env, my_strlen(env));
    return false;
}

bool check_args(int ac, char **av, char **env)
{
    if (env[0] == NULL)
        return my_null_env();
    if (ac != 2 || (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0'))
        return my_usage();
    if (av[1][0] == '-' && av[1][1] == 'm' && av[1][2] == '\0')
        return my_obs();
    if (av[1][0] == '-' && av[1][1] == 'e' && av[1][2] == '\0')
        return my_example();
    return true;
}
