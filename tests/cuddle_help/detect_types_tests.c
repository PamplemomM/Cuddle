/*
** EPITECH PROJECT, 2023
** found_data_types_tests.c
** File description:
** test each functions of the found_data_types function.
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../../include/header_cuddle.h"

//*******************************
// ---- FOUND_TYPES FUNCTION ----
//*******************************

Test(found_data_type, full_covr, .init = cr_redirect_stdout)
{
    void *ptr = found_data_type("2", UINT);
    ptr = found_data_type(NULL, UINT);
    ptr = found_data_type("-2", INT);
    ptr = found_data_type(NULL, INT);
    ptr = found_data_type("4.86", FLOAT);
    ptr = found_data_type(NULL, FLOAT);
    ptr = found_data_type("true", BOOL);
    ptr = found_data_type(NULL, BOOL);
    ptr = found_data_type("true", UNDEFINED);
    ptr = found_data_type(NULL, UNDEFINED);
}

