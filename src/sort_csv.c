/*
** EPITECH PROJECT, 2024
** sort_csv.c
** File description:
** The file for sorting the csv datas.
*/
#include "../include/header_cuddle.h"

int sort_dataframe(dataframe_t *dataframe, const char *column,
    bool(*sort_func)(void *value1, void *value2))
{
    return SUCCESS;
}

dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool(*sort_func)(void *value1, void *value2))
{
    dataframe_t *new;

    if (dataframe == NULL || sort_func == NULL || column == NULL)
        return NULL;
    new = malloc(sizeof(dataframe_t));
    if (new == NULL)
        return NULL;
    new->column_names = my_array_dup(dataframe->column_names);
    if (new->column_names == NULL)
        return FREE("%1", new);
    new->nb_columns = dataframe->nb_columns;
    new->nb_rows = dataframe->nb_rows;
    return dataframe;
}
