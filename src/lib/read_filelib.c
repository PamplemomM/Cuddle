/*
** EPITECH PROJECT, 2024
** read_file_lib.c
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

char *dup_result(char *result, char *line, int len)
{
    static size_t total_size = 0;
    char *temp = realloc(result, total_size + len + 2);

    if (temp == NULL)
        return NULL;
    result = temp;
    my_strcpy(result + total_size, line);
    total_size += len;
    result[total_size] = '\n';
    result[total_size + 1] = '\0';
    total_size++;
    return result;
}

char *read_file(int fd)
{
    char *result = NULL;
    char *new_result = NULL;
    int size = 256;
    char *line = read_line(fd, size);

    while (line != NULL) {
        new_result = dup_result(result, line, my_strlen(line));
        free(line);
        line = read_line(fd, size);
        if (new_result == NULL) {
            free(result);
            return NULL;
        }
        result = new_result;
    }
    free(line);
    return result;
}

char *open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *result = NULL;

    if (fd < 0)
        return NULL;
    result = read_file(fd);
    close(fd);
    return result;
}
