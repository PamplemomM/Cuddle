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

static int found_len(char *str, int i)
{
    int result = 0;

    while (str[i] != ' ' && str[i] != '\0') {
        result++;
        i++;
    }
    return result;
}

static int looping(char *str, int *i)
{
    while (str[*i] == ' ') {
        (*i)++;
    }
    return 1;
}

static int count_words(char *str)
{
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            count += looping(str, &i);
        }
    }
    return count;
}

static int condition(char *str, int i)
{
    while (str[i] == ' ') {
            i++;
    }
    return i;
}

static int init_inside(char **res, char *str, int *i, int *j)
{
    int word_len = found_len(str, *i);
    int k = 0;

    res[*j] = malloc(sizeof(char) * (word_len + 1));
    if (res[*j] == NULL)
        return ERROR;
    while (str[*i] != '\0' && str[*i] != ' ') {
        res[*j][k] = str[*i];
        (*i)++;
        k++;
    }
    res[*j][k] = '\0';
    (*j)++;
    return SUCCESS;
}

char **my_str_to_word_array(char *str, char *delim)
{
    int j = 0;
    int size = count_words(str);
    char *dup = NULL;
    char **res = malloc(sizeof(char *) * (size + 1));

    if (res == NULL)
        return NULL;
    dup = my_strdup(str);
    for (int value = 0; delim[value] != '\0'; value++)
        replace_me_those_spaces(str, delim[value], delim[0]);
    for (int i = 0; str[i] != '\0'; i = condition(str, i)) {
        if (str[i] != delim[0])
            init_inside(res, str, &i, &j);
    }
    res[j] = NULL;
    return res;
}

void free_word_array(char **wa)
{
    if (wa == NULL) {
        return;
    }
    for (int i = 0; wa[i] != NULL; i++) {
        free(wa[i]);
    }
    free(wa);
}

int my_print_wa(char **wa)
{
    for (int i = 0; wa[i] != NULL; i++) {
        for (int j = 0; wa[i][j] != '\0'; j++) {
            write(1, &wa[i][j], 1);
        }
        write(1, "\n", 1);
    }
    return SUCCESS;
}
