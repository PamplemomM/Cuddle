/*
** EPITECH PROJECT, 2025
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
    while (str[*i] == delim) {
        if (str[*i + 1] == '\0') {
            break;
        }
        (*i)++;
    }
    return 1;
}

static int count_words(char *str, char *delim)
{
    int count = 1;
    char *dup = NULL;

    if (str == NULL || delim == NULL)
        return 0;
    dup = my_strdup(str);
    if (dup == NULL)
        return 0;
    for (int value = 0; delim[value] != '\0'; value++)
        replace_me_those_spaces(dup, delim[value], delim[0]);
    for (int i = 0; dup[i] != '\0'; i++) {
        if (dup[i] == delim[0])
            count += looping(dup, &i, delim[0]);
    }
    free(dup);
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
        return -1;
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
    int size = count_words(str, delim);
    char *dup = NULL;
    char **res = malloc(sizeof(char *) * (size + 1));

    if (res == NULL)
        return NULL;
    init_inside(NULL, NULL, &j, '\0');
    dup = my_strdup(str);
    if (dup == NULL)
        return FREE("%1", res);
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
        res[i] = my_strdup(wa[i]);
        if (res[i] == NULL)
            return FREE("%2", res);
    }
    res[len] = NULL;
    return res;
}
