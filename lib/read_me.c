/*
** EPITECH PROJECT, 2018
** read_me.c
** File description:
** reads the file
*/

#include <fcntl.h>
#include <sys/stat.h>
#include "runner.h"

static bool wrong_char(char c)
{
    if (c != 'x' && c != '-' && c != ' ' && c != '\n' && c != '=' && c != '\\')
        return true;
    return false;
}

static bool check_file_quality(char const *str)
{
    for (int i = 0; str && str[i]; i++)
        if (wrong_char(str[i]))
            return false;
    if (get_lines(str) != 4)
        return false;
    return true;
}

static int get_file_size(char const *file)
{
    struct stat sb;

    lstat(file, &sb);
    return (sb.st_size);
}

static char **my_error(char const *error, int length, int fd)
{
    write(2, error, length);
    close(fd);
    return (NULL);
}

char **read_me(char const *filepath)
{
    int fd = 0;
    int size = 0;
    char *buffer = NULL;

    if ((fd = open(filepath, O_RDONLY)) == -1)
        return (my_error("Could not open file\n", 20, fd));
    if ((size = get_file_size(filepath)) <= 0)
        return (my_error("Invalid file\n", 13, fd));
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return (my_error("Malloc failed\n", 14, fd));
    if ((read(fd, buffer, size)) == -1)
        return (my_error("Could not read file\n", 20, fd));
    if (!check_file_quality(buffer))
        return (my_error("Invalid map\n", 12, fd));
    close(fd);
    return (my_str_to_line_array(buffer));
}
