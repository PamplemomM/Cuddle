/*
** EPITECH PROJECT, 2025
** to_type_csv.c
** File description:
** Converting data types.
*/

#include "../include/header_cuddle.h"
#include <string.h>

static int is_string(dataframe_t *dataframe, int i, int value,
    column_type_t new)
{
    column_type_t old = dataframe->column_types[value];
    char *data = NULL;

    if (old != STRING)
        return 1;
    if (new == UNDEFINED || new == STRING)
        return SUCCESS;
    data = (char *)dataframe->data[i][value];
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

static int is_int(dataframe_t *dataframe, int i, int value,
    column_type_t new)
{
    column_type_t old = dataframe->column_types[value];
    int *data = NULL;

    if (old != INT || new == UNDEFINED || new == STRING)
        return SUCCESS;
    data = (int *)dataframe->data[i][value];
    if (new == BOOL) {
        dataframe->data[i][value] = (data == 0) ? (bool *)false : (bool *)true;
        return SUCCESS;
    }
    if (new == UINT) {
        if (data < 0)
            return -1;
        return SUCCESS;
    }
    if (new == FLOAT) {
        dataframe->data[i][value] = (float *)data;
        return SUCCESS;
    }
    return 1;
}

static int is_float(dataframe_t *dataframe, int i, int value,
    column_type_t new)
{
    float *data = NULL;

    if (new == UNDEFINED || new == FLOAT || new == STRING)
        return SUCCESS;
    data = (float *)dataframe->data[i][value];
    switch (new) {
    case BOOL:
        dataframe->data[i][value] = (data == 0) ? (bool *)false : (bool *)true;
        return SUCCESS;
    case UINT:
        if (data < 0)
            return -1;
        dataframe->data[i][value] = (unsigned int *)data;
        return SUCCESS;
    default:
        dataframe->data[i][value] = (int *)data;
        return SUCCESS;
    }
    return 1;
}

static int is_uint(dataframe_t *dataframe, int i, int value,
    column_type_t new)
{
    column_type_t old = dataframe->column_types[value];
    unsigned int *data = NULL;

    if (old != UINT || new == UNDEFINED || new == STRING)
        return SUCCESS;
    data = (unsigned int *)dataframe->data[i][value];
    if (new == BOOL) {
        dataframe->data[i][value] = (data == 0) ? (bool *)false : (bool *)true;
        return SUCCESS;
    }
    if (new == INT) {
        dataframe->data[i][value] = (int *)data;
        return SUCCESS;
    }
    if (new == FLOAT) {
        dataframe->data[i][value] = (float *)data;
        return SUCCESS;
    }
    return 1;
}

static int is_bool(dataframe_t *dataframe, int i, int value,
    column_type_t new)
{
    column_type_t old = dataframe->column_types[value];
    bool *data = NULL;

    if (old != BOOL || new == UNDEFINED || new == STRING)
        return SUCCESS;
    data = (bool *)dataframe->data[i][value];
    if (new == UINT || new == INT) {
        dataframe->data[i][value] = (data == false) ? (int *)0 : (int *)1;
        return SUCCESS;
    }
    if (new == FLOAT) {
        dataframe->data[i][value] = (data == false) ? (float *)0 : (float *)1;
        return SUCCESS;
    }
    return 1;
}

int found_and_convert(dataframe_t *dataframe, int i, int value,
    column_type_t new)
{
    if (new == UNDEFINED)
        return SUCCESS;
    if (new == STRING && is_string(dataframe, i, value, new) == 0)
        return SUCCESS;
    if (new == INT && is_int(dataframe, i, value, new) == 0)
        return SUCCESS;
    if (new == FLOAT && is_float(dataframe, i, value, new) == 0)
        return SUCCESS;
    if (new == UINT && is_uint(dataframe, i, value, new) == 0)
        return SUCCESS;
    if (new == BOOL && is_bool(dataframe, i, value, new) == 0)
        return SUCCESS;
    return ERROR;
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
        if (returning == ERROR) {
            df_free(result);
            return NULL;
        }
    }
    result->column_types[value] = downcast;
    return result;
}
