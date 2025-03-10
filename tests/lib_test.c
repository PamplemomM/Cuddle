/*
** EPITECH PROJECT, 2023
** lib_test.c
** File description:
** test each function of lib
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/header_cuddle.h"

// **********************************
// ----- MY_STR_TO_WORD_ARRAY.c -----
//**********************************

Test(my_str_to_word_array, full_covr, .init = cr_redirect_stdout)
{
    char *str = my_strdup("hello  \t  comment \\t \t\t ca va");
    char **test = my_str_to_word_array(str);

    mini_printf("%s %s\n", test[0], test[1]);
    cr_assert_stdout_eq_str("hello comment\n");
}

Test(my_print_wa, full_covr, .init = cr_redirect_stdout)
{
    char *test[] = {"unit_tests", "coucou"};

    my_print_wa(test);
    cr_assert_stdout_eq_str("unit_tests\ncoucou\n");
}

Test(my_free_wa, full_covr, .init = cr_redirect_stdout)
{
    char **test = my_str_to_word_array("Yolo yolo yolo");

    free_word_array(test);
    free_word_array(NULL);
}

//**********************************
// ----- MINI_PRINTF -----
//**********************************

Test(mini_printf_str, full_covr, .init = cr_redirect_stdout)
{
    char *str = "hello";

    mini_printf("%s\n", str);
    cr_assert_stdout_eq_str("hello\n");
}

Test(mini_printf_char, full_covr, .init = cr_redirect_stdout)
{
    mini_printf("%c %%", '\n');
    cr_assert_stdout_eq_str("\n %");
}

Test(mini_printf_num, full_covr, .init = cr_redirect_stdout)
{
    mini_printf("%d %d\n", 2, -25);
    cr_assert_stdout_eq_str("2 -25\n");
}

Test(mini_printf_overflow, full_covr, .init = cr_redirect_stdout)
{
    mini_printf("%d\n", -2147483647 - 1);
    cr_assert_stdout_eq_str("-2147483648\n");
}

//**********************************
// ----- LIB FUNCTIONS -----
//**********************************

Test(my_strlen, full_covr)
{
    char str[7] = "cbbcbb\0";

    cr_assert_eq(my_strlen(str), 6);
}

Test(my_strdup, full_covr, .init = cr_redirect_stdout)
{
    char *dup = my_strdup("Hello");

    mini_printf("%s\n", dup);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_strcmp, full_covr)
{
    char str[7] = "cbbcbb\0";
    char src[7] = "caacaa\0";

    cr_assert_eq(my_strcmp(str, str), 0);
    cr_assert_eq(my_strcmp(str, src), 1);
    cr_assert_eq(my_strcmp(src, str), -1);
}

//**********************************
// ----- MY_STRTOK FUNCTION -----
//**********************************

Test(my_strtok, full_covr, .init = cr_redirect_stdout)
{
    char *dup = my_strdup("Tom, really good, mate");
    char *first = my_strtok(dup, ", ");
    char *second = my_strtok(NULL, ",");

    mini_printf("%s %s\n", first, second);
    cr_assert_stdout_eq_str("Tom  really good\n");
}

Test(my_strtok_error, full_covr, .init = cr_redirect_stdout)
{
    char *dup = my_strdup("Tom, really good, mate");
    char *first = my_strtok(NULL, ",");
    char *second = my_strtok(dup, "bad delim");
    char *third = my_strtok(dup, "s");
    char *four = my_strtok(dup, dup);

    mini_printf("%s\n", "dup");
    cr_assert_stdout_eq_str("dup\n");
}
