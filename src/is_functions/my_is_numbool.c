/*
** EPITECH PROJECT, 2024
** my_is_numbull.c
** File description:
** Function that tells if a char is a num.
*/
#include "../../include/header_cuddle.h"

int my_isnum(char const str)
{
    return (str >= 48 && str <= 57) ? 1 : 0;
}

int my_isbool(char const *str)
{
    return (my_strcmp(str, "TRUE") == 0 ||
        my_strcmp(str, "true") == 0) ? 1 : 0;
}
