/*
** EPITECH PROJECT, 2024
** read_csv.c
** File description:
** The file for reading the csv function.
*/
#include "../include/header_cuddle.h"

// ****************************************************
// ---- THE FUNCTION  IN THIS FILE IS NOT FINISHED ----
// ****************************************************
// Please, don't touch it

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

void set_column_names(dataframe_t *data, char **first)
{
    data->colomn_name = malloc(sizeof(char *) * data->nb_columns);
    for (int i = 0; i < data->nb_columns; i++) {
        data->colomn_name[i] = my_strdup(first[i]);
    }
}

int read_csv_next(dataframe_t *data, char *file, char const *separator)
{
    char **lines = my_str_to_word_array(file, "\n");
    char ***full_data;

    if (lines == NULL)
        return ERROR;
    full_data = malloc(sizeof(char **) * (data->nb_rows + 1));
    for (int i = 0; i <= data->nb_rows; i++) {
        full_data[i] = my_str_to_word_array(lines[i], separator);
        if (full_data[i] == NULL)
            return ERROR;
    }
    set_column_names(data, full_data[0]);
    return SUCCESS;
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
    if (read_csv_next(data, file, separator) == ERROR)
        return NULL;
    return data;
}
