/*
** EPITECH PROJECT, 2024
** head_tail_csv.c
** File description:
** The file for reading the head and tail of csv file.
*/
#include "../include/header_cuddle.h"

// **********************************
// ---- FUNCTION IS FINISHED ----
// **********************************
// I'll touch you if you touch it

static column_type_t *my_column_types_dup(dataframe_t *dataframe)
{
    column_type_t *res;
    int len = dataframe->nb_columns;

    if (dataframe->column_types == NULL)
        return NULL;
    res = malloc(sizeof(column_type_t) * (len + 1));
    if (res == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        res[i] = dataframe->column_types[i];
    res[len] = -1;
    return res;
}

static void ***my_data_dupbetween(dataframe_t *dataframe, int start, int end)
{
    void ***data;
    int len = end - start;

    if (dataframe->data == NULL)
        return NULL;
    data = malloc(sizeof(void **) * (len + 1));
    if (data == NULL)
        return NULL;
    for (int i = start; i < end; i++) {
        data[i - start] = df_duprow(dataframe, i);
        if (data[i - start] == NULL)
            return FREE("%3", data);
    }
    data[len] = NULL;
    return data;
}

static dataframe_t *dupbetween(dataframe_t *dataframe, int start, int end)
{
    dataframe_t *res;

    res = malloc(sizeof(dataframe_t));
    if (res == NULL)
        return NULL;
    res->nb_rows = end - start;
    res->nb_columns = dataframe->nb_columns;
    res->separator = my_strdup(dataframe->separator);
    res->column_names = my_array_dup(dataframe->column_names);
    if (res->separator == NULL || res->column_names == NULL)
        return FREE("%1 %2 %1", res->separator, res->column_names, res);
    res->column_types = my_column_types_dup(dataframe);
    if (res->column_types == NULL)
        return FREE("%2 %1", res->column_names, res);
    res->data = my_data_dupbetween(dataframe, start, end);
    if (res->data == NULL)
        return FREE("%1 %2 %1", res->column_types, res->column_names, res);
    return res;
}

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows)
{
    if (dataframe == NULL || nb_rows <= 0)
        return NULL;
    nb_rows = MIN(dataframe->nb_rows, nb_rows);
    return dupbetween(dataframe, 0, nb_rows);
}

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    if (dataframe == NULL || nb_rows <= 0)
        return NULL;
    nb_rows = MIN(dataframe->nb_rows, nb_rows);
    return dupbetween(dataframe,
    dataframe->nb_rows - nb_rows, dataframe->nb_rows);
}
