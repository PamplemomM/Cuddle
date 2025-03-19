/*
** EPITECH PROJECT, 2024
** to_type_csv.c
** File description:
** The file for the to_type csv datas.
*/
#include "../include/header_cuddle.h"

int detect_good_type_inside(dataframe_t *dataframe, int value, int i,
    column_type_t downcast)
{
    if (dataframe->data[i][value] == NULL)
        return ERROR;
    if ((downcast == INT || downcast == UINT)
        && my_isnum(*(char *)dataframe->data[i][value]) == 0)
        return ERROR;
    if (downcast == FLOAT && (my_isnum(*(char *)dataframe->data[i][value]) == 0
        || my_isfloat(*(char *)dataframe->data[i][value]) == 0))
        return ERROR;
    if (downcast == BOOL)
        return SUCCESS;
    return SUCCESS;
}

int detect_good_type(dataframe_t *dataframe, int value, column_type_t downcast)
{
    column_type_t type = detect_type(dataframe, value, dataframe->nb_rows);

    for (int i = 1; i < dataframe->nb_rows + 1; i++) {
        detect_good_type_inside(dataframe, value, i, downcast);
    }
    return SUCCESS;
}

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
    if (detect_good_type(dataframe, value, downcast) == ERROR
        || dup_data(dataframe, result) == ERROR) {
        df_free(result);
        return NULL;
    }
    return result;
}
