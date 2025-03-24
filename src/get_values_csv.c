/*
** EPITECH PROJECT, 2025
** get_values.c
** File description:
** Retrieving specific values from a dataframe.
*/

#include "../include/header_cuddle.h"

void *df_get_value(dataframe_t *dataframe, int row, const char *column)
{
    int position = 0;

    if (dataframe == NULL || column == NULL)
        return NULL;
    position = find_column(dataframe, column);
    if (position == -1)
        return NULL;
    return dataframe->data[row][position];
}

void **df_get_values(dataframe_t *dataframe, const char *column)
{
    int position = 0;
    void **new;

    if (dataframe == NULL || column == NULL)
        return NULL;
    new = malloc(sizeof(void *) * (dataframe->nb_rows + 1));
    if (new == NULL)
        return NULL;
    position = find_column(dataframe, column);
    if (position == -1)
        return FREE("%1", new);
    for (int i = 0; i < dataframe->nb_rows; i++)
        new[i] = dataframe->data[i][position];
    new[dataframe->nb_rows] = NULL;
    return new;
}

static void **add_value_tolist(void ***list, void *value, column_type_t type)
{
    void **new;
    int len = 0;

    if (*list != NULL) {
        while ((*list)[len] != NULL)
            len++;
    }
    new = malloc(sizeof(void *) * (len + 2));
    if (new == NULL)
        return FREE("%2", *list);
    for (int i = 0; i < len; i++)
        new[i] = (*list)[i];
    new[len] = my_void_dup(value, type);
    if (new[len] == NULL)
        return FREE("%1 %2", new, *list);
    new[len + 1] = NULL;
    FREE("%1", *list);
    *list = new;
    return *list;
}

static int values_compare(void *v1, void *v2, column_type_t type)
{
    if (type == BOOL)
        return *(bool *)v1 == *(bool *)v2;
    if (type == INT)
        return *(int *)v1 == *(int *)v2;
    if (type == UINT)
        return *(unsigned int *)v1 == *(unsigned int *)v2;
    if (type == FLOAT)
        return *(float *)v1 == *(float *)v2;
    if (type == STRING)
        return my_strcmp((char *)v1, (char *)v2) == 0;
    return 1;
}

static void **add_if_unique(void ***list, void *value, column_type_t type)
{
    if (*list == NULL)
        return add_value_tolist(list, value, type);
    for (int i = 0; (*list)[i] != NULL; i++) {
        if (values_compare((*list)[i], value, type) == 1)
            return *list;
    }
    return add_value_tolist(list, value, type);
}

void **df_get_unique_values(dataframe_t *dataframe, const char *column)
{
    int position = 0;
    void **new = NULL;

    if (dataframe == NULL || column == NULL)
        return NULL;
    position = find_column(dataframe, column);
    if (position == -1)
        return FREE("%1", new);
    for (int i = 0; i < dataframe->nb_rows; i++) {
        if (add_if_unique(&new, dataframe->data[i][position],
            dataframe->column_types[position]) == NULL)
            return NULL;
    }
    return new;
}
