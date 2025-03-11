/*
** EPITECH PROJECT, 2024
** my_strtok.c
** File description:
** The file for my_strtok function.
*/
#include "../../include/header_cuddle.h"

static int is_delimiter(char c, char const *delim)
{
    char *d = (char *)delim;

    for (int i = 0; d[i] != '\0'; i++) {
        if (c == d[i])
            return 1;
    }
    return SUCCESS;
}

static char *skip_delimiters(char *str, char const *delim)
{
    char *ptr = str;

    while (*ptr != '\0') {
        if (is_delimiter(*ptr, delim) == 0)
            break;
        ptr++;
    }
    return (*ptr == '\0') ? NULL : ptr;
}

static char *find_token_end(char *str, char const *delim)
{
    char *ptr = str;

    while (*ptr != '\0') {
        if (is_delimiter(*ptr, delim) == 1) {
            *ptr = '\0';
            return ptr + 1;
        }
        ptr++;
    }
    return NULL;
}

char *my_strtok(char *str, char const *delim)
{
    char *start;
    static char *saved_ptr = NULL;

    if (str != NULL)
        saved_ptr = str;
    if (saved_ptr == NULL)
        return NULL;
    start = skip_delimiters(saved_ptr, delim);
    if (start == NULL) {
        saved_ptr = NULL;
        return NULL;
    }
    saved_ptr = find_token_end(start, delim);
    return start;
}
