/*
** EPITECH PROJECT, 2024
** head_tail_csv.c
** File description:
** The file for reading the head and tail of csv file.
*/
#include "../include/header_cuddle.h"

// **********************************
// ---- FUNCTION IS NOT FINISHED ----
// **********************************
// You can touch it if you want

static column_type_t *my_column_types_dup(column_type_t *column_types, int len)
{
    column_type_t *res;

    if (column_types == NULL)
        return NULL;
    res = malloc(sizeof(column_type_t) * (len + 1));
    if (res == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        res[i] = column_types[i];
    res[len] = -1;
    return res;
}

static void ***my_data_dupbetween(void)
{
    return NULL;
}

static dataframe_t *dupbetween(dataframe_t *dataframe, int start, int end)
{
    dataframe_t *result;

    result = malloc(sizeof(dataframe_t));
    if (result == NULL)
        return NULL;
    result->nb_rows = start - end;
    result->nb_columns = dataframe->nb_columns;
    result->column_names = my_array_dup(dataframe->column_names);
    if (result->column_names == NULL)
        return FREE("%1", result);
    result->column_types = my_column_types_dup(dataframe->column_types,
        dataframe->nb_columns);
    if (result->column_types == NULL)
        return FREE("%2 %1", result->column_names, result);
    result->data = my_data_dupbetween();
    if (result->data == NULL)
        return FREE("%1 %2 %1", result->column_types,
            result->column_names, result);
    return result;
}

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *result;

    if (dataframe == NULL || nb_rows <= 0)
        return NULL;
    nb_rows = MIN(dataframe->nb_rows, nb_rows);
    return dupbetween(dataframe, 0, nb_rows);
}

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *result;

    if (dataframe == NULL || nb_rows <= 0)
        return NULL;
    nb_rows = MIN(dataframe->nb_rows, nb_rows);
    return dupbetween(dataframe,
    dataframe->nb_rows - nb_rows, dataframe->nb_rows);
}
