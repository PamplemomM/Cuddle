/*
** EPITECH PROJECT, 2024
** read_line.c.c
** File description:
** The file for reading a line.
*/
#include "../../include/header_cuddle.h"

char *read_line(int fd, int size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));
    int i = 0;
    int res = 0;

    if (buffer == NULL)
        return NULL;
    while (i < size) {
        res = read(fd, &buffer[i], 1);
        if (res <= 0 || buffer[i] == '\n')
            break;
        i++;
    }
    if (res <= 0 && i == 0) {
        free(buffer);
        return NULL;
    }
    buffer[i] = '\0';
    return buffer;
}