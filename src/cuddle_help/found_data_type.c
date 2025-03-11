/*
** EPITECH PROJECT, 2024
** detect_type.c
** File description:
** The file for detecting the type of the datas.
*/
#include "../../include/header_cuddle.h"

static void *convert_to_int(char *value)
{
    int *result = malloc(sizeof(int));

    if (result == NULL)
        return NULL;
    *result = atoi(value);
    return result;
}

static void *convert_to_float(char *value)
{
    float *result = malloc(sizeof(float));

    if (result == NULL)
        return NULL;
    *result = atof(value);
    return result;
}

static void *convert_to_bool(char *value)
{
    bool *result = malloc(sizeof(bool));

    if (result == NULL)
        return NULL;
    *result = (my_strcmp(value, "true") == 0 || my_strcmp(value, "1") == 0);
    return result;
}

static void *convert_to_uint(char *value)
{
    unsigned int *result = malloc(sizeof(unsigned int));

    if (result == NULL)
        return NULL;
    *result = (unsigned int)atoi(value);
    return result;
}

void *found_data_type(char *value, column_type_t type)
{
    static void *(*converters[])(char *) = {convert_to_bool, convert_to_int,
        convert_to_uint, convert_to_float, my_strdup, NULL};

    if (type >= BOOL && type <= STRING)
        return converters[type](value);
    else
        return my_strdup(value);
}
