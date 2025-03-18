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
    #include <stdbool.h>
    #include <fcntl.h>
    #include <math.h>

    #include "dataframe.h"

    // maths :
    #define SQ(a) ((a) * (a))
    #define PI 3.141592653589793238462
    #define MIN(a, b) ((a) < (b) ? (a) : (b))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define ABS(x) ((x) < 0 ? -(x) : (x))

    // salade_de_free function :
    #define FREE(format, ...) salade_de_free(format, __VA_ARGS__)

    // defines :
    #define SUCCESS 0
    #define ERROR 84

    // Custom define :
    #define PRINT(x) _Generic((x), int : print_int, (char *) : print_string)(x)

// ------------ ARSENAL FUNCTIONS ------ ------

// --- salade_de_free.c ---
void *omnifree(void **thing, int dimension);
void *salade_de_free(char const *format, ...);


// ------------ LIB FUNCTIONS ------------

// --- my_libc_functions.c ---
int my_getnbr(char const *str);
int mini_printf(const char *format, ...);
char *my_strlowercase(char *str);

// --- my_string_lib.c ---
int my_strlen(char const *str);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

// --- my_str_to_word_array ---
char **my_str_to_word_array(char *str, char *delim);
int my_print_wa(char **wa);
char **my_array_dup(char **wa);

// --- my_strtok.c ---
char *my_strtok(char *str, char const *delim);

// --- read_filelib.c ---
char *read_line(int fd, int size);
char *dup_result(char *result, char *line, int len);
char *read_file(int fd);
char *open_file(char const *filepath);


// ------- CUDDLE FUNCTION HELPING -------

// --- found_column.c ---
int find_column(dataframe_t *dataframe, const char *column_name);

// --- detect_types.c ---
column_type_t detect_type(char ***data, int i, int nb_rows);

// --- my_isnumbool.c ---
int my_isnum(char const *str);
int my_isfloat(char const *str);
int my_isbool(char const *str);
int my_istrue(char const *str);

// --- found_data_type.c ---
void *found_data_type(char *value, column_type_t type);


// ------- CUDDLE DATAFRAME FUNCTIONS -------

// --- read_csv.c ---
void ***allocate_void_tab(dataframe_t *data);

// --- void_dups_csv.c ---
void *my_void_dup(void *value, column_type_t type);
void **my_data_duprow(dataframe_t *dataframe, int row);


#endif /* CUDDLE_H */
