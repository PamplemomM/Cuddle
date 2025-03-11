/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** The file for the function my_str_to_word_array.c.
*/
#include "../../include/header_cuddle.h"

static int replace_me_those_spaces(char *str, char bad, char good)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == bad)
            str[i] = good;
    }
    return SUCCESS;
}

static int found_len(char *str, int i, char delim)
{
    int result = 0;

    if (str == NULL)
        return 0;
    while (str[i] != delim && str[i] != '\0') {
        result++;
        i++;
    }
    return result;
}

static int looping(char *str, int *i, char delim)
{
    while (str[*i] == delim)
        (*i)++;
    return 1;
}

static int count_words(char *str, char delim)
{
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim)
            count += looping(str, &i, delim);
    }
    return count;
}

static int condition(char *str, int i, char delim)
{
    while (str[i] == delim)
        i++;
    return i;
}

static int init_inside(char **res, char *str, int *i, char delim)
{
    static int j = 0;
    int word_len = found_len(str, *i, delim);
    int k = 0;

    if (str == NULL) {
        j = 0;
        return 0;
    }
    res[j] = malloc(sizeof(char) * (word_len + 1));
    if (res[j] == NULL)
        return ERROR;
    while (str[*i] != '\0' && str[*i] != delim) {
        res[j][k] = str[*i];
        (*i)++;
        k++;
    }
    res[j][k] = '\0';
    j++;
    return j;
}

char **my_str_to_word_array(char *str, char *delim)
{
    int j = 0;
    int size = count_words(str, delim[0]);
    char *dup = NULL;
    char **res = malloc(sizeof(char *) * (size + 1));

    if (res == NULL)
        return NULL;
    init_inside(NULL, NULL, NULL, '\0');
    dup = my_strdup(str);
    for (int value = 0; delim[value] != '\0'; value++)
        replace_me_those_spaces(dup, delim[value], delim[0]);
    for (int i = 0; dup[i] != '\0'; i = condition(dup, i, delim[0])) {
        if (dup[i] != delim[0])
            j = init_inside(res, dup, &i, delim[0]);
    }
    res[j] = NULL;
    free(dup);
    return res;
}

void free_word_array(char **wa)
{
    if (wa == NULL)
        return;
    for (int i = 0; wa[i] != NULL; i++)
        free(wa[i]);
    free(wa);
}

int my_print_wa(char **wa)
{
    for (int i = 0; wa[i] != NULL; i++) {
        for (int j = 0; wa[i][j] != '\0'; j++)
            write(1, &wa[i][j], 1);
        write(1, "\n", 1);
    }
    return SUCCESS;
}

char **my_array_dup(char **wa)
{
    int len = 0;
    char **res;

    if (wa == NULL)
        return NULL;
    while (wa[len] != NULL)
        len++;
    res = malloc(sizeof(char *) * (len + 1));
    if (res == NULL)
        return NULL;
    for (int i = 0; wa[i] != NULL; i++) {
        res[i] = my_strdup(res[i]);
        if (res[i] == NULL) {
            free_word_array(res);
            return NULL;
        }
    }
    res[len] = NULL;
    return res;
}
