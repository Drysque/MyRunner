/*
** EPITECH PROJECT, 2018
** file_to_array.c
** File description:
** takes the filepath and returns an array
*/

#include "runner.h"

static char **create_infinite_array(char **array)
{
    array = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 4; i++) {
        array[i] = malloc(sizeof(char) * 2);
        array[i][0] = 'i';
        array[i][1] = '\0';
    }
    array[4] = NULL;
    return (array);
}

static bool long_enough(char const *str)
{
    int count = 0;

    for (count = 0; str && str[count]; count++);
    if (count < 2)
        return false;
    return true;
}

static bool is_infinite(char const *str)
{
    if (str[0] == '-' && str[1] == 'i' && str[2] == '\0')
        return true;
    return false;
}

char **file_to_array(char const *str, char **array)
{
    if (!long_enough(str))
        return NULL;
    else if (is_infinite(str))
        return (create_infinite_array(array));
    else
        return (read_me(str));
}
