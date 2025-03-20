/*
** EPITECH PROJECT, 2025
** dataframe.h
** File description:
** The header for the datagrames.
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <math.h>

// ------------ DATAFRAME STRUCT ------------

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED // only used internally before the type is determined
} column_type_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
    char *separator;
} dataframe_t;

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

// ------------ DATAFRAME FUNCTIONS ------------

// --- read_csv.c ---
dataframe_t *df_read_csv(char const *filename, char const *separator);

// --- write_csv.c ---
int df_write_csv(dataframe_t *dataframe, char const *filename);

// --- head_tail_csv.c ---
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);

// --- shape_info_csv.c ---
dataframe_shape_t df_shape(dataframe_t *dataframe);
void df_info(dataframe_t *dataframe);

// --- describe_csv.c ---
void df_describe(dataframe_t *dataframe);

// --- filter_csv.c ---
dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool(*filter_func)(void *value));
bool filter_func(void *value);

// --- sort_csv.c ---
dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool(*sort_func)(void *value1, void *value2));
bool sort_func(void *value1, void *value2);

// --- aggregation_csv.c ---
dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate,
    void *(*agg_func)(void **values, int nb_values));
void *agg_func(void **values, int nb_values);

// --- filter_csv.c ---
dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value));
// void *apply_func(void *value);

// --- to_type_csv.c ---
dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast);
// void *apply_func(void *value);

// --- get_values_csv.c ---
void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);

// --- free_csv.c ---
void df_free(dataframe_t *dataframe);

// ------------- BONUS -------------

// --- duplicate_csv.c ---
dataframe_t *df_duplicate(dataframe_t *dataframe);

// --- void_dups_csv.c ---
void **df_duprow(dataframe_t *dataframe, int row);


#endif /* DATAFRAME_H */
