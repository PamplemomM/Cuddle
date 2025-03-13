/*
** EPITECH PROJECT, 2024
** filter_csv.c
** File description:
** The file for filtering the csv datas.
*/
#include "../include/header_cuddle.h"

bool filter_func(void *value)
{
    return *(int *)value > 30;
}

int find_column(dataframe_t *dataframe, const char *column_name)
{
    int i = 0;

    for (i = 0; i < dataframe->nb_columns; i++) {
        if (strcmp(dataframe->column_names[i], column_name) == 0)
            return i;
    }
    return -1;
}

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool(*filter_func)(void *value))
{
    dataframe_t *result = malloc(sizeof(dataframe_t));
    int col;
    int row;

    if (result == NULL || dataframe == NULL || column == NULL)
        return NULL;
    col = find_column(dataframe, column);
    if (col == -1)
        return NULL;
    result->data = allocate_void_tab(dataframe);
    if (result->data == NULL)
        return FREE("%1", result);
    result->column_types = my_array_dup(dataframe->column_types);
    if (result->data == NULL)
        return FREE("%2 %1", result->data, result);
    return result;
}
