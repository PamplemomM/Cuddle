/*
** EPITECH PROJECT, 2024
** detect_type.c
** File description:
** The file for detecting the type of the datas.
*/
#include "../../include/header_cuddle.h"

column_type_t detect_type(char *str)
{
    if (str == NULL)
        return UNDEFINED;
    if (my_isbool(str) == 1)
        return BOOL;
    if (my_isnum(str) == 1)
        return (my_getnbr(str) < 0) ? INT : UINT;
    if (my_isfloat(str) == 1)
        return FLOAT;
    return STRING;
}
