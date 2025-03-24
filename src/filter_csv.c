/*
** EPITECH PROJECT, 2025
** filter_csv.c
** File description:
** Filtering a dataframe.
*/

#include "../include/header_cuddle.h"

static int dup_data_condition(dataframe_t *result, dataframe_t *dataframe,
    int i, int j)
{
    result->data[j] = df_duprow(dataframe, i);
    if (result->data[j] == NULL) {
        FREE("%3 %2 %1 %1", result->data, result->column_names,
            result->column_types, result);
        return -1;
    }
    j++;
    return j;
}

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool(*filter_func)(void *value))
{
    dataframe_t *result = NULL;
    int va = find_column(dataframe, column);
    int j = 0;

    if (va == -1 || dataframe == NULL || column == NULL || filter_func == NULL)
        return NULL;
    result = df_duplicate(dataframe);
    if (result == NULL)
        return NULL;
    for (int i = 0; i < dataframe->nb_rows; i++)
        FREE("%2", result->data[i]);
    for (int i = 0; i < dataframe->nb_rows; i++) {
        if (filter_func(dataframe->data[i][va]))
            j = dup_data_condition(result, dataframe, i, j);
        if (j == -1)
            return NULL;
    }
    result->data[j] = NULL;
    result->nb_rows = j;
    return result;
}
