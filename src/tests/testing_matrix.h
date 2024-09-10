#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *test_create_matrix();
Suite *test_remove_matrix();
Suite *test_eq_matrix();
Suite *test_sum_matrix();
Suite *test_sub_matrix();
Suite *test_mult_matrix();
Suite *test_mult_number();

Suite *test_calc_complements();
Suite *test_determinant();
Suite *test_transpose();
Suite *test_inverse_matrix();

#endif