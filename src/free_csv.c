/*
** EPITECH PROJECT, 2025
** free_csv.c
** File description:
** The freedom of the dataframe (bring back liberty).
*/

#include "../include/header_cuddle.h"

void df_free(dataframe_t *dataframe)
{
    if (dataframe == NULL)
        return;
    FREE("%1 %3 %1 %2 %1", dataframe->separator, dataframe->data,
        dataframe->column_types, dataframe->column_names, dataframe);
}
