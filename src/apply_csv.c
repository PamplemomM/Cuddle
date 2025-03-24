/*
** EPITECH PROJECT, 2025
** apple_csv.c
** File description:
** Applying a function to a specific column within a dataframe.
*/

#include "../include/header_cuddle.h"

dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value))
{
    dataframe_t *result;
    int val = find_column(dataframe, column);
    void *tmp = NULL;

    if (val == -1 || dataframe == NULL || column == NULL || apply_func == NULL)
        return NULL;
    result = df_duplicate(dataframe);
    if (result == NULL)
        return NULL;
    for (int i = 0; i < dataframe->nb_rows; i++) {
        tmp = result->data[i][val];
        result->data[i][val] = my_void_dup(apply_func(tmp),
            dataframe->column_types[val]);
        my_free(tmp);
        if (result->data[i][val] == NULL)
            return FREE("%3 %2 %1 %1", result->data, result->column_names,
                result->column_types, result);
    }
    return result;
}
