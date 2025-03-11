/*
** EPITECH PROJECT, 2023
** lib_test.c
** File description:
** test each function of lib
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../../include/header_cuddle.h"

//*********************************
// ------- MY_FREE FUNCTION -------
//*********************************

Test(my_free, full_covr, .init = cr_redirect_stdout)
{
    char *dup = my_strdup("Tom, really good, mate");
    char **array = my_str_to_word_array(dup, ", ");

    my_free("%as %s", array, dup);
}

Test(my_free_float, full_covr, .init = cr_redirect_stdout)
{
    float **farray = malloc(sizeof(float *) * 2);

    farray[0] = malloc(sizeof(float) * 3);
    farray[0][0] = 1.0;
    farray[0][1] = 2.5;
    farray[0][2] = 0;
    farray[1] = NULL;
    my_free("%af", farray);
}

Test(my_free_int, full_covr, .init = cr_redirect_stdout)
{
    int **iarray = malloc(sizeof(int *) * 2);

    iarray[0] = malloc(sizeof(int) * 3);
    iarray[0][0] = 1;
    iarray[0][1] = 2;
    iarray[0][2] = 0;
    iarray[1] = NULL;
    my_free("%ad", iarray);
}
