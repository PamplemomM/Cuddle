/*
** EPITECH PROJECT, 2025
** sort_csv.c
** File description:
** Data sorting.
*/

#include "../include/header_cuddle.h"

int sort_dataframe(dataframe_t *new, int val,
    bool(*sort_func)(void *value1, void *value2))
{
    void **tmp;

    for (int i = 0; i < new->nb_rows - 1; i++) {
        if (sort_func(new->data[i][val], new->data[i + 1][val])) {
            tmp = new->data[i];
            new->data[i] = new->data[i + 1];
            new->data[i + 1] = tmp;
            sort_dataframe(new, val, sort_func);
        }
    }
    return SUCCESS;
}

dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool(*sort_func)(void *value1, void *value2))
{
    dataframe_t *new;
    int val = find_column(dataframe, column);

    if (val == -1 || dataframe == NULL || sort_func == NULL || column == NULL)
        return NULL;
    new = df_duplicate(dataframe);
    if (new == NULL)
        return NULL;
    sort_dataframe(new, val, sort_func);
    return new;
}
