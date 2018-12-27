/*
** EPITECH PROJECT, 2018
** my_str_to_line_array
** File description:
** my_str_to_line_array
*/

#include "runner.h"

static int get_lines(char const *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            count++;
    return (count);
}

char **my_str_to_line_array(char const *str)
{
    int a = 0;
    int length = 0;
    char **array = malloc(sizeof(char *) * (get_lines(str) + 1));

    for (int i = 0; str != 0 && str[i] != '\0'; i++) {
        for (i; str[i] != '\n' && str[i] != '\0'; i++)
            length++;
        if (str[i] == '\n' || str[i] == '\0') {
            array[a] = malloc(sizeof(char) * (length + 1));
            my_strncpy(array[a], &str[i - length], length);
            length = 0;
            a++;
        }
    }
    array[a] = NULL;
    return (array);
}
