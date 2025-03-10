/*
** EPITECH PROJECT, 2024
** filter_csv.c
** File description:
** The file for filtering the csv datas.
*/
#include "../include/header_cuddle.h"

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool(*filter_func)(void *value))
{
    return NULL;
}

bool filter_func(void *value)
{
    return *(int *)value > 30;
}