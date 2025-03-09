/*
** EPITECH PROJECT, 2025
** header_cuddle.h
** File description:
** The header for the cuddle project.
*/

#ifndef CUDDLE_H
    #define CUDDLE_H

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>

    #include "dataframe.h"

    // maths :
    #define SQ(a) ((a) * (a))
    #define PI 3.141592653589793238462
    #define MIN(a, b) ((a) < (b) ? (a) : (b))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define ABS(x) ((x) < 0 ? -(x) : (x))

    //defines :
    #define SUCCESS 0
    #define ERROR 84

// ------------ LIB FUNCTIONS ------------

// --- my_libc_functions.c ---
int my_strlen(char const *str);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
int mini_printf(const char *format, ...);

// --- my_str_to_word_array ---
char **my_str_to_word_array(char *str);
void free_word_array(char **wa);
int my_print_wa(char **wa);

// --- my_strtok.c ---
char *my_strtok(char *str, char const *delim);


// ------------ IS FUNCTIONS ------------

// --- my_isnumbool.c
int my_isnum(char const str);
int my_isbool(char const *str);

#endif /* CUDDLE_H */
