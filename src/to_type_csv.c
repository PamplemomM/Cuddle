/*
** EPITECH PROJECT, 2024
** to_type_csv.c
** File description:
** The file for the to_type csv datas.
*/
#include "../include/header_cuddle.h"
#include <string.h>

int is_string(dataframe_t *dataframe, int i, int value,
    column_type_t new)
{
    column_type_t old = dataframe->column_types[value];
    char *data = NULL;

    if (old == STRING)
        return 1;
    data = (char *)dataframe->data[i][value];
    if (new == UNDEFINED || new == STRING)
        return SUCCESS;
    if (new == BOOL && my_isbool(data) == 1)
        return SUCCESS;
    if ((new == INT || new == UINT) && my_isnum(data) == 1) {
        if (new == UINT && my_getnbr(data) < 0)
            return -1;
        return SUCCESS;
    }
    if (new == FLOAT && my_isfloat(data) == 1)
        return SUCCESS;
    return 1;
}

int found_and_convert(dataframe_t *dataframe, int i, int value,
    column_type_t downcast)
{
    if (is_string(dataframe, i, value, downcast) == 1)
        return SUCCESS;
    return SUCCESS;
}

dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast)
{
    dataframe_t *result = NULL;
    int value = find_column(dataframe, column);
    int returning = 0;

    if (value == -1 || dataframe == NULL || column == NULL)
        return NULL;
    result = df_duplicate(dataframe);
    if (result == NULL)
        return NULL;
    for (int i = 0; i < dataframe->nb_rows; i++) {
        returning = found_and_convert(dataframe, i, value, downcast);
        if (returning == -1) {
            df_free(result);
            return NULL;
        }
    }
    result->column_types[value] = downcast;
    return result;
}
