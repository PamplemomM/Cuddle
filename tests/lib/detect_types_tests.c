/*
** EPITECH PROJECT, 2023
** detect_types_tests.c
** File description:
** test each functions of the detect_types function.
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../../include/header_cuddle.h"

//********************************
// ---- DETECT_TYPES FUNCTION ----
//********************************

Test(detect_type_bool, full_covr, .init = cr_redirect_stdout)
{
    column_type_t type = detect_type("True");
    mini_printf((type == BOOL) ? "1" : "0");
    mini_printf("\n");
    cr_assert_stdout_eq_str("1\n");
}

Test(detect_type_int, full_covr, .init = cr_redirect_stdout)
{
    column_type_t type = detect_type("-12");
    mini_printf((type == INT) ? "1" : "0");
    mini_printf("\n");
    cr_assert_stdout_eq_str("1\n");
}

Test(detect_type_uint, full_covr, .init = cr_redirect_stdout)
{
    column_type_t type = detect_type("143");
    mini_printf((type == UINT) ? "1" : "0");
    mini_printf("\n");
    cr_assert_stdout_eq_str("1\n");
}

Test(detect_type_float, full_covr, .init = cr_redirect_stdout)
{
    column_type_t type = detect_type("3.6");
    mini_printf((type == FLOAT) ? "1" : "0");
    mini_printf("\n");
    type = detect_type("-3.6");
    mini_printf((type == FLOAT) ? "1" : "0");
    mini_printf("\n");
    cr_assert_stdout_eq_str("1\n1\n");
}

Test(detect_type_str, full_covr, .init = cr_redirect_stdout)
{
    column_type_t type = detect_type("blablabla");
    mini_printf((type == STRING) ? "1" : "0");
    mini_printf("\n");
    cr_assert_stdout_eq_str("1\n");
}

Test(detect_type_undefined, full_covr, .init = cr_redirect_stdout)
{
    column_type_t type = detect_type(NULL);
    mini_printf((type == UNDEFINED) ? "1" : "0");
    mini_printf("\n");
    cr_assert_stdout_eq_str("1\n");
}

