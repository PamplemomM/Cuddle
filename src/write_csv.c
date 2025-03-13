/*
** EPITECH PROJECT, 2024
** write_csv.c
** File description:
** The file for writing the csv function.
*/
#include "../include/header_cuddle.h"

static int write_to_int(void *value, int fd)
{
    char *result = NULL;

    if (value == NULL)
        return ERROR;
    result = my_its(((int *)value)[0]);
    write(fd, result, my_strlen(result));
    free(result);
    return SUCCESS;
}

static int write_to_float(void *value, int fd)
{
    char *result = NULL;

    if (value == NULL)
        return ERROR;
    sprintf(result, "%f", ((float *)value)[0]);
    write(fd, result, my_strlen(result));
    free(result);
    return SUCCESS;
}

static int write_to_bool(void *value, int fd)
{
    char *result = NULL;
    bool bool_value;

    if (value == NULL)
        return ERROR;
    bool_value = (bool)value;
    result = my_strdup((bool_value == true) ? "true" : "false");
    write(fd, result, my_strlen(result));
    free(result);
    return SUCCESS;
}

static int write_to_uint(void *value, int fd)
{
    char *result = NULL;

    if (value == NULL)
        return ERROR;
    sprintf(result, "%ud", ((unsigned int *)value)[0]);
    write(fd, result, my_strlen(result));
    free(result);
    return SUCCESS;
}

static int my_void_strdup(void *value, int fd)
{
    char *result = NULL;

    if (value == NULL)
        return ERROR;
    result = my_strdup((char *)value);
    write(fd, result, my_strlen(result));
    free(result);
    return SUCCESS;
}

static int write_data_type(void **data, column_type_t *types, int i, int fd)
{
    int (*array[])(void *, int fd) = {write_to_bool, write_to_int,
        write_to_uint, write_to_float, my_void_strdup, NULL};

    if (types[i] >= BOOL && types[i] <= STRING)
        return array[types[i]](data[i], fd);
}

static void my_write_line_csv(void **data, column_type_t *types,
    int len, int fd)
{
    char *temp = NULL;

    for (int i = 0; i < len; i++) {
        if (i != 0)
            write(fd, ",", 1);
        write_data_type(data, types, i, fd);
    }
    write(fd, "\n", 1);
}

/*
NE REGARDER PAS DERRIERE VOUS !!
Il sont ici, ils nous regardent a travers nos corps, ne vous retournez pas.
Ils arrivent, bientot, faites attention.
*/
int df_write_csv(dataframe_t *dataframe, char const *filename)
{
    int fd;

    if (dataframe == NULL)
        return ERROR;
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00664);
    if (fd == -1)
        return ERROR;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (i != 0)
            write(fd, ",", 1);
        write(fd, dataframe->column_names[i],
            my_strlen(dataframe->column_names[i]));
    }
    write(fd, "\n", 1);
    for (int j = 0; j < dataframe->nb_rows; j++)
        my_write_line_csv(dataframe->data[j], dataframe->column_types,
            dataframe->nb_columns, fd);
    close(fd);
    return SUCCESS;
}
