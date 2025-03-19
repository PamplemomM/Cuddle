/*
** EPITECH PROJECT, 2024
** get_values.c
** File description:
** The file for getting values of the csv datas.
*/
#include "../include/header_cuddle.h"

void *df_get_value(dataframe_t *dataframe, int row, const char *column)
{
    int position = 0;

    if (dataframe == NULL || column == NULL)
        return NULL;
    position = find_column(dataframe, column);
    if (position == -1)
        return NULL;
    return dataframe->data[row][position];
}

void **df_get_values(dataframe_t *dataframe, const char *column)
{
    int position = 0;
    void **new;

    if (dataframe == NULL || column == NULL)
        return NULL;
    new = malloc(sizeof(void *) * (dataframe->nb_rows + 1));
    if (new == NULL)
        return NULL;
    position = find_column(dataframe, column);
    if (position == -1)
        return FREE("%1", new);
    for (int i = 0; i < dataframe->nb_rows; i++)
        new[i] = dataframe->data[i][position];
    new[dataframe->nb_rows] = NULL;
    return new;
}

void **df_get_unique_values(dataframe_t *dataframe, const char *column)
{
    if (dataframe == NULL || column == NULL)
        return NULL;
    return NULL;
}
