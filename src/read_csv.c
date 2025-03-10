/*
** EPITECH PROJECT, 2024
** read_csv.c
** File description:
** The file for reading the csv function.
*/
#include "../include/header_cuddle.h"

int count_columns(char *file, char const *separator)
{
    int cpt = 0;
    char *value = my_strtok(file, separator);

    while (value != NULL) {
        cpt++;
        value = my_strtok(NULL, separator);
    }
    return cpt;
}

int count_rows(char *file)
{
    int cpt = 0;

    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '\n')
            cpt++;
    }
    return cpt;
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    dataframe_t *data = malloc(sizeof(dataframe_t) * 1);
    char *file = open_file(filename);

    if (file == NULL || data == NULL)
        return NULL;
    if (separator == NULL)
        separator = ",";
    data->nb_columns = count_columns(file, separator);
    data->nb_rows = count_rows(file);
    return data;
}
