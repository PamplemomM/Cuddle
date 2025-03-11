/*
** EPITECH PROJECT, 2024
** my_is_numbull.c
** File description:
** Function that tells if a char is a num.
*/
#include "../../include/header_cuddle.h"

int my_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return 0;
    }
    return 1;
}

int my_isfloat(char const *str)
{
    int cpt = 0;

    if (str[0] < 48 || str[0] > 57)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 46)
            cpt++;
        if ((str[i] < 48 || str[i] > 57) && str[i] != 46)
            return 0;
    }
    return (cpt == 1) ? 1 : 0;
}

int my_isbool(char const *str)
{
    char *lower = NULL;
    int result;

    if (str == NULL)
        return false;
    lower = my_strdup(str);
    lower = my_strlowercase(lower);
    result = (my_strcmp(lower, "true") == 0 ||
        my_strcmp(lower, "false") == 0) ? 1 : 0;
    free(lower);
    return result;
}

int my_istrue(char const *str)
{
    return (my_strcmp(str, "TRUE") == 0 ||
        my_strcmp(str, "true") == 0) ? 1 : 0;
}
