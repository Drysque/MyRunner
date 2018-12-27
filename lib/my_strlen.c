/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Day04 task03 my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (i; str[i]; i++);
    return (i);
}
