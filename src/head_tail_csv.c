/*
** EPITECH PROJECT, 2024
** head_tail_csv.c
** File description:
** The file for reading the head and tail of csv file.
*/
#include "../include/header_cuddle.h"

// **********************************
// ---- FUNCTION IS NOT FINISHED ----
// **********************************
// You can touch it if you want
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows)
{
    int rows = 0;
    dataframe_t *result;

    if (dataframe == NULL || nb_rows <= 0) {
        return NULL;
    }
    if (nb_rows >= dataframe->nb_rows)
        rows = dataframe->nb_rows;
    
    result = malloc(sizeof(dataframe_t) * 1);
    return result;
}

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    return NULL;
}
