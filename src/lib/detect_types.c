/*
** EPITECH PROJECT, 2024
** detect_type.c
** File description:
** The file for detecting the type of the datas.
*/
#include "../../include/header_cuddle.h"

column_type_t detect_type(char *str)
{
    column_type_t result = STRING;

    if (my_isbool(str) == 1)
        result = BOOL;
    if (my_isnum(str) == 1)
        result = (my_getnbr(str) < 0) ? INT : UINT;
    if (my_isfloat(str) == 1)
        result = FLOAT;
    return result;
}
