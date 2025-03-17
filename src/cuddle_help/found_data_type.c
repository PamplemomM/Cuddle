/*
** EPITECH PROJECT, 2024
** detect_type.c
** File description:
** The file for detecting the type of the datas.
*/
#include "../../include/header_cuddle.h"

static void *convert_to_bool(char const *value)
{
    bool *result = malloc(sizeof(bool));

    if (result == NULL || value == NULL)
        return NULL;
    *result = (my_strcmp(value, "true") == 0 || my_strcmp(value, "1") == 0);
    return result;
}

static void *convert_to_int(char const *value)
{
    int *result = malloc(sizeof(int));

    if (result == NULL || value == NULL)
        return NULL;
    *result = atoi(value);
    return result;
}

static void *convert_to_uint(char const *value)
{
    unsigned int *result = malloc(sizeof(unsigned int));

    if (result == NULL || value == NULL)
        return NULL;
    *result = (unsigned int)atoi(value);
    return result;
}

static void *convert_to_float(char const *value)
{
    float *result = malloc(sizeof(float));

    if (result == NULL || value == NULL)
        return NULL;
    *result = atof(value);
    return result;
}

static void *convert_to_str(char const *value)
{
    char *result = malloc(sizeof(char) * (my_strlen(value) + 1));

    if (result == NULL)
        return NULL;
    my_strcpy(result, value);
    return result;
}

void *found_data_type(char *value, column_type_t type)
{
    void *(*array[])(char const *) = {convert_to_bool, convert_to_int,
        convert_to_uint, convert_to_float, convert_to_str, NULL};

    if (type >= BOOL && type <= STRING)
        return array[type](value);
    if (value == NULL)
        return NULL;
    return my_strdup(value);
}
