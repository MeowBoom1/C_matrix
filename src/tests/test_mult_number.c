#include "testing_matrix.h"

START_TEST(mult_number_1) {
  matrix_t M = {0};
  int multiplier = 100;
  ck_assert_int_eq(s21_mult_number(&M, multiplier, NULL), CALC_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t M = {0};
  int multiplier = 4;
  matrix_t result = {0};
  matrix_t answer = {0};
  s21_create_matrix(10, 10, &M);
  s21_create_matrix(10, 10, &answer);
  s21_init_matrix(&M, 1, 1);
  s21_init_matrix(&answer, 4, 4);
  s21_mult_number(&M, multiplier, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&M);
  s21_remove_matrix(&result);
  s21_remove_matrix(&answer);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t M = {0};
  int multiplier = 2;
  matrix_t result = {0};
  matrix_t answer = {0};
  s21_create_matrix(5, 5, &M);
  s21_create_matrix(5, 5, &answer);
  s21_init_matrix(&M, 1, 1);
  s21_init_matrix(&answer, 2, 2);
  s21_mult_number(&M, multiplier, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&M);
  s21_remove_matrix(&result);
  s21_remove_matrix(&answer);
}
END_TEST

START_TEST(mult_number_4) {
  matrix_t M = {0};
  double multiplier = 0.5;
  matrix_t result = {0};
  matrix_t answer = {0};
  s21_create_matrix(5, 5, &M);
  s21_create_matrix(5, 5, &answer);
  s21_init_matrix(&M, 1, 0);
  s21_init_matrix(&answer, 0.5, 0);
  s21_mult_number(&M, multiplier, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&M);
  s21_remove_matrix(&result);
  s21_remove_matrix(&answer);
}
END_TEST

START_TEST(mult_number_5) {
  matrix_t M = {0};
  double multiplier = 10;
  matrix_t result = {0};
  matrix_t answer = {0};
  s21_create_matrix(5, 5, &M);
  s21_create_matrix(5, 5, &answer);
  s21_init_matrix(&M, 1, 1);
  s21_init_matrix(&answer, 10, 10);
  s21_mult_number(&M, multiplier, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&M);
  s21_remove_matrix(&result);
  s21_remove_matrix(&answer);
}
END_TEST

Suite *test_mult_number() {
  Suite *s = suite_create("\033[36m< s21_mult_number >\033[0m");
  TCase *tc = tcase_create("mult_number_tc");

  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);
  tcase_add_test(tc, mult_number_3);
  tcase_add_test(tc, mult_number_4);
  tcase_add_test(tc, mult_number_5);

  suite_add_tcase(s, tc);
  return s;
}