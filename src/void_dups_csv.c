/*
** EPITECH PROJECT, 2024
** void_dups_csv.c
** File description:
** The file for duplicating void pointers.
*/
#include "../include/header_cuddle.h"

static void *my_void_bool_dup(void *value)
{
    bool *result = malloc(sizeof(bool));

    if (result == NULL)
        return NULL;
    result = (bool *)value;
    return result;
}

static void *my_void_int_dup(void *value)
{
    int *result = malloc(sizeof(int));

    if (result == NULL)
        return NULL;
    result = (int *)value;
    return result;
}

static void *my_void_uint_dup(void *value)
{
    unsigned int *result = malloc(sizeof(unsigned int));

    if (result == NULL)
        return NULL;
    result = (unsigned int *)value;
    return result;
}

static void *my_void_float_dup(void *value)
{
    float *result = malloc(sizeof(float));

    if (result == NULL)
        return NULL;
    result = (float *)value;
    return result;
}

static void *my_void_str_dup(void *value)
{
    char *result = malloc(sizeof(char) * (my_strlen((char *)value) + 1));

    if (result == NULL)
        return NULL;
    my_strcpy(result, value);
    return result;
}

void *my_void_dup(void *value, column_type_t type)
{
    void *(*func[])(void *value) = {my_void_bool_dup, my_void_int_dup,
        my_void_uint_dup, my_void_float_dup, my_void_str_dup};

    return func[type](value);
}

void **my_data_duprow(dataframe_t *dataframe, int row)
{
    void **data = malloc(sizeof(void *) * (dataframe->nb_columns + 1));

    if (data == NULL)
        return NULL;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        data[i] = my_void_dup(dataframe->data[row][i],
            dataframe->column_types[i]);
        if (data[i] == NULL)
            return FREE("%2", data);
    }
    data[dataframe->nb_columns] = NULL;
    return data;
}
