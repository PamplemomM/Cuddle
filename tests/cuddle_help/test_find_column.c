/*
** EPITECH PROJECT, 2023
** test_find_column.c
** File description:
** test each functions of the find_column function.
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../../include/header_cuddle.h"

//*******************************
// ---- FIND_COLUMN FUNCTION ----
//*******************************

Test(find_column, full_covr, .init = cr_redirect_stdout)
{
    dataframe_t *dataframe = malloc(sizeof(dataframe_t) * 1);
    int value = 0;

    if (dataframe == NULL)
        return;
    dataframe->nb_columns = 2;
    dataframe->column_names = malloc(sizeof(char *) * 3);
    if (dataframe->column_names == NULL)
        return;
    dataframe->column_names[0] = my_strdup("name");
    dataframe->column_names[1] = my_strdup("age");
    dataframe->column_names[2] = NULL;
    value = find_column(dataframe, "age");
    mini_printf("%d\n", value);
    cr_assert_stdout_eq_str("1\n");
}

Test(find_column_error, full_covr, .init = cr_redirect_stdout)
{
    int value = 0;

    value = find_column(NULL, NULL);
    mini_printf("%d\n", value);
    cr_assert_stdout_eq_str("-1\n");
}
