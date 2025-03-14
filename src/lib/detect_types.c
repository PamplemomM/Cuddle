/*
** EPITECH PROJECT, 2024
** detect_type.c
** File description:
** The file for detecting the type of the datas.
*/
#include "../../include/header_cuddle.h"

column_type_t find_type(char ***data, int i, int j)
{
    if (data[j][i] == NULL)
        return UNDEFINED;
    if (my_isbool(data[j][i]) == 1)
        return BOOL;
    if (my_isnum(data[j][i]) == 1) {
        if (my_getnbr(data[j][i]) < 0)
            return INT;
        return UINT;
    }
    if (my_isfloat(data[j][i]) == 1)
        return FLOAT;
    return STRING;
}

column_type_t detect_type(char ***data, int i, int nb_rows)
{
    column_type_t result = NULL;
    column_type_t actual;

    for (int j = 1; j < nb_rows; j++) {
        actual = find_type(data, i, j);
        if (result == NULL)
            result = actual;
        if (actual == UNDEFINED)
            return UNDEFINED;
        if (actual == STRING && (result >= BOOL && result <= FLOAT))
            result = STRING;
        if (actual == INT && result == UINT)
            result = INT;
        if (actual == FLOAT && (result == INT || result == UINT))
            result = FLOAT;
    }
    return result;
}
