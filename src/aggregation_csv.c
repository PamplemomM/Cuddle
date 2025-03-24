/*
** EPITECH PROJECT, 2025
** aggregation.c
** File description:
** Aggregate data.
*/

#include "../include/header_cuddle.h"

dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate, void *(*agg_func)(void **values, int nb_values))
{
    if (dataframe == NULL || aggregate_by == NULL || to_aggregate == NULL ||
        agg_func == NULL)
        return NULL;
    return dataframe;
}
