/*
** EPITECH PROJECT, 2023
** my_stringlib_tests.c
** File description:
** test each functions of the strings functions
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../../include/header_cuddle.h"

//**********************************
// -------- STRING FUNCTION --------
//**********************************

Test(my_strcpy, full_covr, .init = cr_redirect_stdout)
{
    char *dup = my_strdup("Hello");
    char *cpy;

    mini_printf("%s\n", my_strcpy(cpy, dup));
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_strncmp, full_covr)
{
    char str[7] = "cbbcbb\0";
    char src[7] = "caacaa\0";

    cr_assert_eq(my_strncmp(str, str, 1), 0);
    cr_assert_eq(my_strncmp(str, src, 1), 0);
    cr_assert_eq(my_strncmp(str, src, 6), 1);
    cr_assert_eq(my_strncmp(src, str, 6), -1);
}
