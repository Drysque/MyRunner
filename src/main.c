/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** test
*/

void my_runner(void);
int check_args(int ac, char **av, char **env);

int main(int ac, char **av, char **env)
{
    if (!check_args(ac, av, env))
        return (84);
    my_runner();
    return (0);
}
