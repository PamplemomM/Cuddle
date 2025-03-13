/*
** EPITECH PROJECT, 2024
** filter_csv.c
** File description:
** The file for filtering the csv datas.
*/
#include "../include/header_cuddle.h"

bool filter_func(void *value)
{
    return *(int *)value > 30;
}

int find_column(dataframe_t *result, dataframe_t *dataframe,
    const char *column_name)
{
    result->nb_rows = dataframe->nb_rows;
    result->nb_columns = dataframe->nb_columns;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (my_strcmp(dataframe->column_names[i], column_name) == 0)
            return i;
    }
    return -1;
}

int add_row(dataframe_t *result, dataframe_t *data, int row)
{
    void **new_row;
    void ***new_data;

    new_row = malloc(sizeof(void *) * (result->nb_columns + 1));
    if (new_row == NULL)
        return ERROR;
    for (int i = 0; i < result->nb_columns; i++)
        new_row[i] = data->data[row][i];
    new_row[result->nb_columns] = NULL;
    new_data = malloc(sizeof(void **) * (result->nb_rows + 2));
    if (new_data == NULL)
        return ERROR;
    for (int i = 0; i < result->nb_rows; i++)
        new_data[i] = result->data[i];
    new_data[result->nb_rows] = new_row;
    new_data[result->nb_rows + 1] = NULL;
    result->data = new_data;
    result->nb_rows++;
    return SUCCESS;
}

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool(*filter_func)(void *value))
{
    dataframe_t *result = malloc(sizeof(dataframe_t));
    int colomn;
    int row;

    if (result == NULL || dataframe == NULL || column == NULL)
        return NULL;
    result->column_names = my_array_dup(dataframe->column_names);
    if (result->column_names == NULL)
        return FREE("%1", result);
    colomn = find_column(result, dataframe, column);
    if (colomn == -1)
        return FREE("%2 %1", result->column_names, result);
    for (row = 0; row < dataframe->nb_rows; row++) {
        if (filter_func(dataframe->data[row][colomn]) &&
            add_row(result, dataframe, row) == ERROR)
            return FREE("%2 %3%1", result->column_names, result->data, result);
    }
    return result;
}
