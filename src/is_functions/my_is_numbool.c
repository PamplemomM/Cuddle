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

static char *my_strlowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
    }
    return str;
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
