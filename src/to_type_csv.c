/*
** EPITECH PROJECT, 2024
** to_type_csv.c
** File description:
** The file for the to_type csv datas.
*/
#include "../include/header_cuddle.h"

dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast)
{
    return NULL;
}

void *apply_func(void *value)
{
    char *str = (char *)value;

    if (str[my_strlen(str) - 1] == 'e')
        str[my_strlen(str) - 1] = '\0';
    return str;
}
