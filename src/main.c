/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** test
*/
#include <stdio.h>
int my_runner(char **av);
int check_args(int ac, char **av, char **env);

int main(int ac, char**av, char **env)
{
    if (!check_args(ac, av, env))
        return (84);
    printf("%s\n", "args are good");
    return (my_runner(av));
}
