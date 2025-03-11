/*
** EPITECH PROJECT, 2023
** read_filelib_tests.c
** File description:
** test each functions of the read_filelib functions
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../../include/header_cuddle.h"

//**********************************
// ------- READFILE FUNCTION -------
//**********************************

Test(open_file, full_covr)
{
    char *error = open_file(NULL);
    char *file = open_file("Makefile");
}
