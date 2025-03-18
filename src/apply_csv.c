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
    int value = 0;
    void *tmp = NULL;

    if (dataframe == NULL || column == NULL || apply_func == NULL)
        return NULL;
    value = find_column(dataframe, column);
    if (value == -1)
        return NULL;
    result = df_duplicate(dataframe);
    if (result == NULL)
        return NULL;
    for (int i = 0; i < dataframe->nb_rows; i++) {
        tmp = result->data[i][value];
        result->data[i][value] = apply_func(tmp);
        free(tmp);
        if (result->data[i][value] == NULL)
            return FREE("%3 %2 %1 %1", result->data, result->column_names,
                result->column_types, result);
    }
    return result;
}
