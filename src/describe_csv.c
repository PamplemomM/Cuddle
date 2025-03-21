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

static float get_in_num(void *ptr, column_type_t type)
{
    float result = 0;

    if (ptr == NULL)
        return SUCCESS;
    if (type == INT)
        result = *(int *)ptr;
    if (type == UINT)
        result = *(unsigned int *)ptr;
    if (type == FLOAT)
        result = *(float *)ptr;
    return (float)result;
}

static double min_value(dataframe_t *dataframe, int i)
{
    double result = 0.0;
    float value = 0.0;
    float first = 0.0;
    void *ptr = NULL;
    column_type_t type = dataframe->column_types[i];

    for (int j = 0; j < dataframe->nb_rows; j++) {
        ptr = dataframe->data[j][i];
        if (ptr == NULL)
            continue;
        value = get_in_num(ptr, type);
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
    float value = 0.0;
    float first = 0.0;
    void *ptr = NULL;
    column_type_t type = dataframe->column_types[i];

    for (int j = 0; j < dataframe->nb_rows; j++) {
        ptr = dataframe->data[j][i];
        if (ptr == NULL)
            continue;
        value = get_in_num(ptr, type);
        if (first == 0)
            result = value;
        first = 1;
        if (value > result)
            result = value;
    }
    return result;
}

static float get_mean(dataframe_t *dataframe, int i, int *count)
{
    float sum = 0.0;
    void *ptr = NULL;
    static int res = 0;
    column_type_t type = dataframe->column_types[i];

    *count = 0;
    for (int j = 0; j < dataframe->nb_rows; j++) {
        ptr = dataframe->data[j][i];
        if (ptr == NULL)
            continue;
        sum += get_in_num(ptr, type);
        (*count)++;
    }
    return (sum > 0) ? (sum / *count) : 0.0;
}

static float standard_deviation(dataframe_t *dataframe, int i,
    double mean, int count)
{
    void *ptr = NULL;
    float sum_squares = 0.0;
    float result = 0.0;
    float diff = 0.0;
    column_type_t type = dataframe->column_types[i];

    for (int j = 0; j < dataframe->nb_rows; j++) {
        ptr = dataframe->data[j][i];
        if (ptr == NULL)
            continue;
        result = get_in_num(ptr, type);
        diff = result - mean;
        sum_squares += diff * diff;
    }
    if (count <= 1)
        return 0;
    return sqrt(sum_squares / count);
}

static void describe_numerical_column(dataframe_t *dataframe, int i)
{
    int count = 1;
    double mean = get_mean(dataframe, i, &count);

    printf("Column: %s\n", dataframe->column_names[i]);
    printf("Count: %d\n", count);
    printf("Mean: %.2f\n", mean);
    printf("Std: %.2f\n", standard_deviation(dataframe, i, mean, count));
    printf("Min: %.2f\n", min_value(dataframe, i));
    printf("Max: %.2f\n", max_value(dataframe, i));
}

void df_describe(dataframe_t *dataframe)
{
    if (dataframe == NULL || dataframe->nb_columns <= 0 ||
        dataframe->nb_rows <= 0)
        return;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (dataframe->column_types[i] == INT ||
            dataframe->column_types[i] == UINT ||
            dataframe->column_types[i] == FLOAT) {
            describe_numerical_column(dataframe, i);
        }
    }
}
