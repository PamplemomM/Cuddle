/*
** EPITECH PROJECT, 2024
** shape_info_csv.c
** File description:
** The file for shaping the csv datas.
*/
#include "../include/header_cuddle.h"

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    return (dataframe_shape_t){dataframe->nb_rows, dataframe->nb_columns};
}

void df_info(dataframe_t *dataframe)
{
    char *str[7] = {"bool", "int", "uint", "float", "string",
        "undefined", NULL};

    mini_printf("%d columns:\n", dataframe->nb_rows);
    for (int i = 0; i < dataframe->nb_rows; i++) {
        mini_printf("%s : %s", dataframe->column_names[i],
            str[dataframe->column_types[i]]);
    }
    return;
}
