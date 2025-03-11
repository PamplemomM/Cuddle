/*
** EPITECH PROJECT, 2024
** my_free.c
** File description:
** The file that contains the my_free function.
*/
#include "../../include/header_cuddle.h"
#include <stdarg.h>

static int free_int_array(int **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return SUCCESS;
}

static int free_float_array(float **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return SUCCESS;
}

static int condition_flag(char const *s, int i, va_list arg)
{
    if (s[i + 1] == 's') {
        free(va_arg(arg, char *));
        i += 2;
    }
    if (s[i + 1] == 'a') {
        if (s[i + 2] == 's')
            free_word_array(va_arg(arg, char **));
        if (s[i + 2] == 'd' || s[i + 2] == 'i')
            free_int_array(va_arg(arg, int **));
        if (s[i + 2] == 'f')
            free_float_array(va_arg(arg, float **));
    }
    return i + 2;
}

void *my_free(char const *format, ...)
{
    va_list arg;

    va_start(arg, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%')
            i = condition_flag(format, i, arg);
    }
    va_end(arg);
    return NULL;
}
