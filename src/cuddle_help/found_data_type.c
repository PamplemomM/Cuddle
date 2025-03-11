/*
** EPITECH PROJECT, 2024
** detect_type.c
** File description:
** The file for detecting the type of the datas.
*/
#include "../../include/header_cuddle.h"

static void *found_data_type2(char *value, column_type_t type, void *result)
{
    if (type == UINT) {
        result = malloc(sizeof(unsigned int));
        if (result == NULL)
            return NULL;
        result = (unsigned int)atoi(value);
        return result;
    }
    if (type == FLOAT) {
        result = malloc(sizeof(float));
        if (result == NULL)
            return NULL;
        result = (float)atof(value);
        return result;
    }
    return my_strdup(value);
}

void *found_data_type(char *value, column_type_t type)
{
    void *result;

    if (type == BOOL) {
        result = malloc(sizeof(bool));
        if (result == NULL)
            return NULL;
        result = (my_strcmp(value, "true") == 0 || my_strcmp(value, "1") == 0);
        return result;
    }
    if (type == INT) {
        result = malloc(sizeof(int));
        if (result == NULL)
            return NULL;
        result = atoi(value);
        return result;
    }
    return found_data_type2(value, type, result);
}
