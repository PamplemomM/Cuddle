/*
** EPITECH PROJECT, 2025
** shape_info_csv.c
** File description:
** Shape and info functions.
*/

#include "../include/header_cuddle.h"

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    dataframe_shape_t result = {0, 0};

    if (dataframe == NULL)
        return result;
    result.nb_rows = dataframe->nb_rows;
    result.nb_columns = dataframe->nb_columns;
    return result;
}

void df_info(dataframe_t *dataframe)
{
    static char *str[7] = {"bool", "int", "unsigned int", "float", "string",
        "undefined", NULL};

    mini_printf("%d columns:\n", dataframe->nb_columns);
    for (int i = 0; i < dataframe->nb_columns; i++) {
        mini_printf("- %s: %s\n", dataframe->column_names[i],
            str[dataframe->column_types[i]]);
    }
}
