/*
** EPITECH PROJECT, 2024
** sort_csv.c
** File description:
** The file for sorting the csv datas.
*/
#include "../include/header_cuddle.h"

dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool(*sort_func)(void *value1, void *value2))
{
    return NULL;
}

bool sort_func(void *value1, void *value2)
{
    return *(int *)value1 > *(int *)value2;
}
