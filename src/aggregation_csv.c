/*
** EPITECH PROJECT, 2024
** agregation.c
** File description:
** The file for the aggregation of the csv file.
*/
#include "../include/header_cuddle.h"

dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate, void *(*agg_func)(void **values, int nb_values))
{
    if (dataframe == NULL)
        return NULL;
    return dataframe;
}

void *agg_func(void **values, int nb_values)
{
    int *sum = malloc(sizeof(int));

    *sum = 0;
    for (int i = 0; i < nb_values; i++)
        *sum += *(int *)values[i];
    return sum;
}
