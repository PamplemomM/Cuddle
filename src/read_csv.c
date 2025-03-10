/*
** EPITECH PROJECT, 2024
** read_csv.c
** File description:
** The file for reading the csv function.
*/
#include "../include/header_cuddle.h"

int count_columns(char *line, char const *separator)
{
    return SUCCESS;
}

int count_rows(int fd)
{
    return SUCCESS;
}

dataframe_t *create_dataframe(int nb_columns, int nb_rows)
{
    return NULL;
}

dataframe_t *init_csv(char const *filename, int *fd, char **separator, char **line)
{
    dataframe_t *data = malloc(sizeof(dataframe_t) * 1);
    int len = 0;
    
    *fd = open(filename, O_RDONLY);
    if (fd < 0)
        return NULL;
    if (*separator == NULL)
        *separator = ",";
    *line = read_line(fd, len);
    if (*line == NULL) {
        close(fd);
        return NULL;
    }
    return data;
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    int fd;
    char *line = NULL;
    dataframe_t *data = init_csv(filename, &fd, &separator, &line);
    int nb_columns = 0;
    int nb_rows = 0;

    if (data == NULL)
        return NULL;
    nb_columns = count_columns(line, separator);
    nb_rows = count_rows(fd) - 1;
    data = create_dataframe(nb_columns, nb_rows);
    close(fd);
    if (data == NULL) {
        free(line);
        return NULL;
    }
    close(fd);
    return data;
}
