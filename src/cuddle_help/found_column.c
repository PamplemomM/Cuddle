/*
** EPITECH PROJECT, 2024
** find_column.c
** File description:
** Function that find the column.tells if a char is a num
*/
#include "../../include/header_cuddle.h"

int find_column(dataframe_t *result, dataframe_t *dataframe,
    const char *column_name)
{
    result->nb_rows = dataframe->nb_rows;
    result->nb_columns = dataframe->nb_columns;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (my_strcmp(dataframe->column_names[i], column_name) == 0)
            return i;
    }
    return -1;
}