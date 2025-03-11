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

Test(detect_type, full_covr, .init = cr_redirect_stdout)
{
    column_type_t type = detect_type("True");
    mini_printf((type == BOOL) ? "1" : "0");
    mini_printf("\n");
    cr_assert_stdout_eq_str("1\n");
}
