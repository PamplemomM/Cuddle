/*
** EPITECH PROJECT, 2023
** lib_test.c
** File description:
** test each function of lib
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../../include/header_cuddle.h"

//**********************************
// ---- SALADE_DE_FREE FUNCTION ----
//**********************************

Test(salade_de_free, full_covr, .init = cr_redirect_stdout)
{
    char *dup = my_strdup("Tom, really good, mate");
    char **array = my_str_to_word_array(dup, ", ");

    salade_de_free("%2 %1", array, dup);
}

Test(salade_de_free_float, full_covr, .init = cr_redirect_stdout)
{
    float **farray = malloc(sizeof(float *) * 2);

    farray[0] = malloc(sizeof(float) * 3);
    farray[0][0] = 1.0;
    farray[0][1] = 2.5;
    farray[0][2] = 0;
    farray[1] = NULL;
    salade_de_free("%2", farray);
}

Test(salade_de_free_int, full_covr, .init = cr_redirect_stdout)
{
    int **iarray = malloc(sizeof(int *) * 2);

    iarray[0] = malloc(sizeof(int) * 3);
    iarray[0][0] = 1;
    iarray[0][1] = 2;
    iarray[0][2] = 0;
    iarray[1] = NULL;
    salade_de_free("%2", iarray);
}
