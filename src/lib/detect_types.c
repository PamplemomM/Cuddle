/*
** EPITECH PROJECT, 2024
** detect_type.c
** File description:
** The file for detecting the type of the datas.
*/
#include "../../include/header_cuddle.h"

column_type_t detect_type(char *str)
{
    column_type_t result;

    if (my_isbool(str) == 1)
        result = BOOL;
    return result;
}
