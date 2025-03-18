/*
** EPITECH PROJECT, 2024
** apple_csv.c
** File description:
** The file for apply the csv file.
*/
#include "../include/header_cuddle.h"

dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value))
{
    dataframe_t *result;
    if (dataframe == NULL || column == NULL || apply_func == NULL)
        return NULL;
    result = df_duplicate(dataframe);
    if (result == NULL)
        return NULL;
    return result;
}
