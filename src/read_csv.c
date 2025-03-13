/*
** EPITECH PROJECT, 2024
** read_csv.c
** File description:
** The file for reading the csv function.
*/
#include "../include/header_cuddle.h"

// ---------------------------------------------------
// ------ THE FUNCTION IN THIS FILE IS FINISHED ------
// ---------------------------------------------------
// Please, don't touch it

static int count_columns(char *file, char const *separator)
{
    int cpt = 0;
    char *dup = my_strdup(file);
    char *value = my_strtok(dup, separator);

    while (value != NULL) {
        cpt++;
        value = my_strtok(NULL, separator);
    }
    free(dup);
    return cpt;
}

static int count_rows(char *file)
{
    int cpt = 0;

    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '\n')
            cpt++;
    }
    return cpt;
}

/*
Est ce que ce texte sera inutile ?
Je ne sais pas, mais ce qui est certain c'est qu'il a ete ecrit et c'est
    quelque chose d'interessant de savoir ca, on mourra moins bete apres
    avoir lu des comment des codes.
*/
static int set_column_names(dataframe_t *data, char **first)
{
    data->column_names = malloc(sizeof(char *) * (data->nb_columns + 1));
    if (data->column_names == NULL)
        return ERROR;
    for (int i = 0; i < data->nb_columns; i++) {
        data->column_names[i] = my_strdup(first[i]);
        if (data->column_names[i] == NULL) {
            FREE("%2", data->column_names);
            return ERROR;
        }
    }
    data->column_names[data->nb_columns] = NULL;
    return SUCCESS;
}

void ***allocate_void_tab(dataframe_t *data)
{
    void ***new_data = malloc(sizeof(void **) * (data->nb_rows + 1));

    if (new_data == NULL)
        return NULL;
    for (int i = 0; i < data->nb_rows; i++) {
        new_data[i] = malloc(sizeof(void *) * (data->nb_columns + 1));
        if (new_data[i] == NULL)
            return FREE("%2", new_data);
        new_data[i][data->nb_columns] = NULL;
    }
    new_data[data->nb_rows] = NULL;
    return new_data;
}

static int set_void_tab(dataframe_t *data, char ***file)
{
    data->data = allocate_void_tab(data);
    if (data->data == NULL)
        return ERROR;
    for (int i = 0; i < data->nb_rows; i++) {
        for (int j = 0; j < data->nb_columns; j++) {
            data->data[i][j] = found_data_type(file[i + 1][j],
                data->column_types[j]);
        }
    }
    return SUCCESS;
}

static char ***get_full_data(dataframe_t *data, char *file,
    char const *separator)
{
    char **lines = my_str_to_word_array(file, "\n");
    char *sep = my_strdup(separator);
    char ***full_data;

    if (lines == NULL)
        return NULL;
    data->nb_columns = count_columns(lines[0], separator);
    full_data = malloc(sizeof(char **) * (data->nb_rows + 2));
    if (full_data == NULL)
        return FREE("%2", lines);
    for (int i = 0; i < data->nb_rows + 1; i++) {
        full_data[i] = my_str_to_word_array(lines[i], sep);
        if (full_data[i] == NULL)
            return FREE("%1 %2 %3", sep, lines, full_data);
    }
    FREE("%1 %2", sep, lines);
    full_data[data->nb_rows + 1] = NULL;
    return full_data;
}

static int read_csv_next(dataframe_t *data, char *file, char const *separator)
{
    char ***full_data = get_full_data(data, file, separator);

    if (full_data == NULL)
        return ERROR;
    if (full_data[0] != NULL) {
        if (set_column_names(data, full_data[0]) == ERROR) {
            FREE("%3", full_data);
            return ERROR;
        }
    }
    data->column_types = malloc(sizeof(int) * data->nb_columns);
    if (data->column_types == NULL) {
        FREE("%3", full_data);
        return ERROR;
    }
    for (int i = 0; i < data->nb_columns; i++)
        data->column_types[i] = detect_type(full_data[1][i]);
    set_void_tab(data, full_data);
    return SUCCESS;
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    dataframe_t *data = malloc(sizeof(dataframe_t) * 1);
    char *file;
    char *sep = NULL;

    if (data == NULL)
        return NULL;
    file = open_file(filename);
    if (file == NULL)
        return FREE("%1", data);
    if (separator == NULL)
        sep = my_strdup(",");
    else
        sep = my_strdup(separator);
    if (sep == NULL)
        return FREE("%1 %1", data, file);
    data->nb_rows = count_rows(file) - 1;
    if (read_csv_next(data, file, sep) == ERROR)
        return FREE("%1 %1 %1", data, file, sep);
    FREE("%1 %1", file, sep);
    return data;
}
