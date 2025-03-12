/*
** EPITECH PROJECT, 2024
** free_csv.c
** File description:
** The file for the freedom of the datas (Bring back liberty).
*/
#include "../include/header_cuddle.h"

// ---------------------------------------------------
// ------ THE FUNCTION IN THIS FILE IS FINISHED ------
// ---------------------------------------------------
// Please, don't touch it

void df_free(dataframe_t *dataframe)
{
    if (dataframe == NULL)
        return;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (dataframe->column_names[i] != NULL)
            free(dataframe->column_names[i]);
    }
    if (dataframe->column_names != NULL)
        free(dataframe->column_names);
    if (dataframe->column_types != NULL)
        free(dataframe->column_types);
    if (dataframe->data == NULL) {
        free(dataframe);
        return;
    }
    for (int i = 0; i < dataframe->nb_columns; i++) {
        salade_de_free("%av", dataframe->data[i]);
    }
    free(dataframe->data);
    free(dataframe);
}
