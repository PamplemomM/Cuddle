/*
** EPITECH PROJECT, 2025
** dataframe.h
** File description:
** The header for the datagrames.
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H

// ------------ DATAFRAME STRUCT ------------

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    // ...
} dataframe_t;

typedef enum {
    BOOL
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED // only used internally before the type is determined
} column_type_t;

// ------------ DATAFRAME FUNCTIONS ------------

// --- my_libc_functions.c ---
dataframe_t *df_read_csv (char const *filename, char const *separator);
int df_write_csv(dataframe_t *dataframe, char const *filename);

#endif /* DATAFRAME_H */
