/*
** EPITECH PROJECT, 2024
** filter_csv.c
** File description:
** The file for filtering the csv datas.
*/
#include "../include/header_cuddle.h"

static int dup_data_condition(dataframe_t *result, dataframe_t *dataframe, int i,
    int *j)
{
    mini_printf("Writing ");
    mini_printf("%d in result[%d]\n", *(int *)dataframe->data[i][1], *j);
    result->data[*j] = df_duprow(dataframe, i);
    if (result->data[*j] == NULL) {
        return ERROR;
    }
    (*j)++;
    result->data[*j] = NULL;
    return SUCCESS;
}

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool(*filter_func)(void *value))
{
    dataframe_t *result = NULL;
    int val = find_column(dataframe, column);
    int error_check = 0;
    int j = 0;

    if (val == -1 || dataframe == NULL || column == NULL ||
        filter_func == NULL)
        return NULL;
    result = df_duplicate(dataframe);
    if (result == NULL)
        return NULL;
    for (int i = 0; i < dataframe->nb_rows; i++)
        FREE("%2", result->data[i]);
    for (int i = 0; i < dataframe->nb_rows; i++) {
        mini_printf("sending to %d from data[%d][%d] and val = %d\n", *(int *)dataframe->data[i][1], i, 1, val);
        if (filter_func(dataframe->data[i][1]))
            error_check = dup_data_condition(result, dataframe, i, &j);
        if (error_check == ERROR)
            return FREE("%3 %2 %1 %1", result->data, result->column_names,
                result->column_types, result);
    }
    return result;
}
