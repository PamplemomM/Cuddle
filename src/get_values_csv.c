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

    if (dataframe == NULL)
        return NULL;
    position = find_column(dataframe, column);
    if (position == -1)
        return NULL;
    return dataframe->data[row][position];
}

void **df_get_values(dataframe_t *dataframe, const char *column)
{
    if (dataframe == NULL)
        return NULL;
    return NULL;
}

void **df_get_unique_values(dataframe_t *dataframe, const char *column)
{
    if (dataframe == NULL)
        return NULL;
    return NULL;
}
