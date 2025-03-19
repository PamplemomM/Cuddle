/*
** EPITECH PROJECT, 2024
** to_type_csv.c
** File description:
** The file for the to_type csv datas.
*/
#include "../include/header_cuddle.h"

dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast)
{
    dataframe_t *result = NULL;
    int value = find_column(dataframe, column);

    if (value == -1 || dataframe == NULL || column == NULL)
        return NULL;
    result = df_duplicate(dataframe);
    if (result == NULL)
        return NULL;
    FREE("%3", result->data);
    result->column_types[value] = downcast;
    if (dup_data(dataframe, result) == ERROR) {
        df_free(result);
        return NULL;
    }
    return result;
}
