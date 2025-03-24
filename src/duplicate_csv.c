/*
** EPITECH PROJECT, 2025
** duplicate_csv.c
** File description:
** Duplicating a dataframe.
*/

#include "../include/header_cuddle.h"

int dup_data(dataframe_t *dataframe, dataframe_t *result)
{
    result->data = malloc(sizeof(void **) * (dataframe->nb_rows + 1));
    if (result->data == NULL) {
        FREE("%2 %1 %1", result->separator, result->column_names,
            result->column_types, result);
        return ERROR;
    }
    for (int i = 0; i < dataframe->nb_rows; i++) {
        result->data[i] = df_duprow(dataframe, i);
        if (result->data[i] == NULL) {
            FREE("%3 %2 %1 %1", result->data, result->column_names,
                result->column_types, result);
            return ERROR;
        }
    }
    result->data[dataframe->nb_rows] = NULL;
    return SUCCESS;
}

dataframe_t *df_duplicate(dataframe_t *dataframe)
{
    dataframe_t *res = malloc(sizeof(dataframe_t) * 1);

    if (res == NULL)
        return NULL;
    if (dataframe == NULL)
        return FREE("%1", res);
    res->nb_columns = dataframe->nb_columns;
    res->nb_rows = dataframe->nb_rows;
    res->separator = my_strdup(dataframe->separator);
    res->column_names = my_array_dup(dataframe->column_names);
    if (res->separator == NULL || res->column_names == NULL)
        return FREE("%1 %2 %1", res->separator, res->column_names, res);
    res->column_types = malloc(sizeof(column_type_t) * (res->nb_columns + 1));
    if (res->column_types == NULL)
        return FREE("%1 %2 %1", res->separator, res->column_names, res);
    for (int i = 0; i < dataframe->nb_columns; i++)
        res->column_types[i] = dataframe->column_types[i];
    dup_data(dataframe, res);
    return res;
}
