/*
** EPITECH PROJECT, 2023
** my_is_functions_tests.c
** File description:
** test each functions of the is_functions directory
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/header_cuddle.h"

//*********************************
// -------- MY_IS FUNCTION --------
//*********************************

Test(my_isnum, full_covr, .init = cr_redirect_stdout)
{
    mini_printf("%d %d\n", my_isnum('1'), my_isnum('a'));
    cr_assert_stdout_eq_str("1 0\n");
}

Test(my_isbool, full_covr, .init = cr_redirect_stdout)
{
    mini_printf("%d %d\n", my_isbool("True"), my_isbool(NULL));
    cr_assert_stdout_eq_str("1 0\n");
}

Test(my_istrue, full_covr, .init = cr_redirect_stdout)
{
    mini_printf("%d %d\n", my_istrue("true"), my_istrue("False"));
    cr_assert_stdout_eq_str("1 0\n");
}
