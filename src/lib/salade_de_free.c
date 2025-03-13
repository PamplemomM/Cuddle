/*
** EPITECH PROJECT, 2024
** salade_de_free.c
** File description:
** Free anything.
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

void *omnifree(void **thing, int dimension)
{
    if (thing == NULL)
        return NULL;
    if (dimension > 1) {
        for (int i = 0; thing[i] != NULL; i++)
            omnifree((void **)thing[i], dimension - 1);
    }
    free(thing);
    thing = NULL;
    return NULL;
}

void *salade_de_free(char const *format, ...)
{
    va_list arg;

    va_start(arg, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%')
            omnifree(va_arg(arg, void **), format[i + 1] - '0');
    }
    va_end(arg);
    return NULL;
}
