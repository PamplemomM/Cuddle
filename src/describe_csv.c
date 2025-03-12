/*
** EPITECH PROJECT, 2024
** describe_csv.c
** File description:
** The file describing the csv datas.
*/
#include "../include/header_cuddle.h"

// **********************************
// ---- FUNCTION IS NOT FINISHED ----
// **********************************
// You can touch it if you want

static double get_in_num(void *ptr, column_type_t type)
{
    if (ptr == NULL)
        return SUCCESS;
    if (type == INT)
        return (double)(*(int *)ptr);
    if (type == UINT)
        return (double)(*(unsigned int *)ptr);
    if (type == FLOAT)
        return (*(double *)ptr);
    return SUCCESS;
}

static double min_value(dataframe_t *dataframe, int i)
{
    double result = 0.0;
    double value = 0.0;
    double first = 0.0;
    void *ptr = NULL;

    for (int i = 0; i < dataframe->nb_rows; i++) {
        ptr = dataframe->data[i][i];
        if (ptr == NULL)
            continue;
            value = get_in_num(ptr, dataframe->column_types[i]);
        if (first == 0)
            result = value;
        first = 1;
        if (value < result)
            result = value;
    }
    return result;
}

static double max_value(dataframe_t *dataframe, int i)
{
    double result = 0.0;
    double value = 0.0;
    double first = 0.0;
    void *ptr = NULL;

    for (int i = 0; i < dataframe->nb_rows; i++) {
        ptr = dataframe->data[i][i];
        if (ptr == NULL)
            continue;
            value = get_in_num(ptr, dataframe->column_types[i]);
        if (first == 0)
            result = value;
        first = 1;
        if (value > result)
            result = value;
    }
    return result;
}

static double root_mean_square(dataframe_t *dataframe, int i, int *count)
{
    double sum = 0.0;
    void *ptr = NULL;
    column_type_t type = dataframe->column_types[i];

    *count = 0;
    for (int i = 0; i < dataframe->nb_rows; i++) {
        ptr = dataframe->data[i][i];
        if (ptr == NULL)
            continue;
        sum += get_in_num(ptr, type);
        (*count)++;
    }
    return (*count > 0) ? (sum / *count) : 0.0;
}

static double standard_deviation(dataframe_t *dataframe, int i, double mean,
    int count)
{
    void *ptr = NULL;
    double sum_squares = 0.0;
    double result = 0.0;
    double diff = 0.0;
    column_type_t type = dataframe->column_types[i];

    for (int i = 0; i < dataframe->nb_rows; i++) {
        ptr = dataframe->data[i][i];
        if (ptr == NULL)
            continue;
        result = get_in_num(ptr, type);
        diff = result - mean;
        sum_squares += diff * diff;
    }
    return (count > 1) ? sqrt(sum_squares / count) : 0.0;
}

static void describe_numerical_column(dataframe_t *dataframe, int i)
{
    char *col_name = dataframe->column_names[i];
    int count = 0;
    double mean = root_mean_square(dataframe, i, &count);
    double std_dev = standard_deviation(dataframe, i, mean, count);
    double min_val = min_value(dataframe, i);
    double max_val = max_value(dataframe, i);

    mini_printf("Column: %s\n", col_name);
    mini_printf("Count: %d\n", count);
    mini_printf("Mean: %.2f\n", mean);
    mini_printf("Std: %.2f\n", std_dev);
    mini_printf("Min: %.2f\n", min_val);
    mini_printf("Max: %.2f\n", max_val);
    mini_printf("\n");
}

void df_describe(dataframe_t *dataframe)
{
    int size = 0;

    if (dataframe == NULL || dataframe->nb_columns <= 0 ||
        dataframe->nb_rows <= 0)
        return;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (dataframe->column_types[i] == INT ||
            dataframe->column_types[i] == UINT ||
            dataframe->column_types[i] == FLOAT) {
            describe_numerical_column(dataframe, i);
            size++;
        }
    }
}
