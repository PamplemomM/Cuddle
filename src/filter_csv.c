/*
** EPITECH PROJECT, 2024
** filter_csv.c
** File description:
** The file for filtering the csv datas.
*/
#include "../include/header_cuddle.h"

bool filter_func(void *value)
{
    return *(int *)value > 30;
}

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool(*filter_func)(void *value))
{
    if (dataframe == NULL)
        return NULL;
    return dataframe;
}
