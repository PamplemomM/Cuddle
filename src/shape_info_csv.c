/*
** EPITECH PROJECT, 2024
** shape_info_csv.c
** File description:
** The file for shaping the csv datas.
*/
#include "../include/header_cuddle.h"

// ---------------------------------------------------
// ------ THE FUNCTION IN THIS FILE IS FINISHED ------
// ---------------------------------------------------
// Please, don't touch it

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    return (dataframe_shape_t){dataframe->nb_rows, dataframe->nb_columns};
}

void df_info(dataframe_t *dataframe)
{
    static char *str[7] = {"bool", "int", "uint", "float", "string",
        "undefined", NULL};

    mini_printf("%d columns:\n", dataframe->nb_columns);
    for (int i = 0; i < dataframe->nb_columns; i++) {
        mini_printf("- %s: %s\n", dataframe->column_names[i],
            str[dataframe->column_types[i]]);
    }
}
