/*
** EPITECH PROJECT, 2024
** my_stringlib.c
** File description:
** The string.h functions.
*/
#include "../../include/header_cuddle.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && n > 1) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
        n--;
    }
    return s1[i] - s2[i];
}
