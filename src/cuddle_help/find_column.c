/*
** EPITECH PROJECT, 2025
** find_column.c
** File description:
** Finding a column's index by name.
*/

#include "../../include/header_cuddle.h"

int find_column(dataframe_t *dataframe, const char *column_name)
{
    if (dataframe == NULL || column_name == NULL)
        return -1;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (my_strcmp(dataframe->column_names[i], column_name) == 0)
            return i;
    }
    return -1;
}
