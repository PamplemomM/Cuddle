/*
** EPITECH PROJECT, 2024
** void_dups_csv.c
** File description:
** The file for duplicating void pointers.
*/
#include "../include/header_cuddle.h"

static int my_void_bool_dup(void *dest, void *src)
{
    return ERROR;
}

static int my_void_int_dup(void *dest, void *src)
{
    return ERROR;
}

static int my_void_uint_dup(void *dest, void *src)
{
    return ERROR;
}

static int my_void_float_dup(void *dest, void *src)
{
    return ERROR;
}

static int my_void_str_dup(void *dest, void *src)
{
    return ERROR;
}

int my_void_dup(void *dest, void *src, column_type_t type)
{
    int (*func[])(void *dest, void *src) =
        {my_void_bool_dup, my_void_int_dup, my_void_uint_dup,
        my_void_float_dup, my_void_str_dup};

    return func[type](dest, src);
}

void **my_data_duprow(dataframe_t *dataframe, int row)
{
    void **data = malloc(sizeof(void *) * (dataframe->nb_columns + 1));

    if (data == NULL)
        return NULL;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (my_void_dup(data[i], dataframe->data[row][i],
            dataframe->column_types[i]) == ERROR)
            return FREE("%2", data);
    }
    data[dataframe->nb_columns] = NULL;
    return data;
}
