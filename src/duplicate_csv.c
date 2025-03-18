/*
** EPITECH PROJECT, 2024
** duplicate_csv.c
** File description:
** The file for duplicate the csv file.
*/
#include "../include/header_cuddle.h"

static int dup_data(dataframe_t *dataframe, dataframe_t *result)
{
    result->data = malloc(sizeof(void **) * (dataframe->nb_rows + 1));
    if (result->data == NULL) {
        FREE("%2 %1 %1", result->column_names,result->column_types, result);
        return ERROR;
    }
    for (int i = 0; i < dataframe->nb_rows; i++) {
        result->data[i] = my_data_duprow(dataframe, i);
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
    dataframe_t *result = malloc(sizeof(dataframe_t) * 1);

    if (result == NULL)
        return NULL;
    if (dataframe == NULL)
        return FREE("%1", result);
    result->nb_columns = dataframe->nb_columns;
    result->nb_rows = dataframe->nb_rows;
    result->column_names = my_array_dup(dataframe->column_names);
    if (result->column_names == NULL)
        return FREE("%1", result);
    result->column_types = malloc(sizeof(column_type_t) * (result->nb_columns + 1));
    if (result->column_types == NULL)
        return FREE("%2 %1", result->column_names, result);
    for (int i = 0; i < dataframe->nb_columns; i++) {
        result->column_types[i] = dataframe->column_types[i];
    }
    dup_data(dataframe, result);
    return result;
}
