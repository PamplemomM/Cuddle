/*
** EPITECH PROJECT, 2024
** write_csv.c
** File description:
** The file for writing the csv function.
*/
#include "../include/header_cuddle.h"

static void my_write_line_csv(void **data, int len, int fd)
{
    for (int i = 0; i < len; i++) {
        if (i != 0)
            write(fd, ",", 1);
        write(fd, (char *)data[i], my_strlen((char *)data[i]));
    }
    write(fd, "\n", 1);
}

int df_write_csv(dataframe_t *dataframe, char const *filename)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00444);

    if (fd == -1)
        return ERROR;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (i != 0)
            write(fd, ",", 1);
        write(fd, dataframe->column_names[i],
            my_strlen(dataframe->column_names[i]));
    }
    write(fd, "\n", 1);
    for (int j = 0; j < dataframe->nb_rows; j++)
        my_write_line_csv(dataframe->data[j], dataframe->nb_columns, fd);
    close(fd);
    return SUCCESS;
}
