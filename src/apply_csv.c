/*
** EPITECH PROJECT, 2024
** apple_csv.c
** File description:
** The file for apply the csv file.
*/
#include "../include/header_cuddle.h"

static void *apply_func(void *value)
{
    int *new_value = malloc(sizeof(int));

    *new_value = *(int *)value * 2;
    return new_value;
}


dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value))
{
    return NULL;
}